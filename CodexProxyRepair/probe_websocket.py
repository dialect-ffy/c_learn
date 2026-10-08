import base64,json,os,socket,ssl,time
from pathlib import Path
started=time.monotonic()
host='chatgpt.com'
auth=json.loads(Path('C:/Users/L/.codex/auth.json').read_text(encoding='utf-8'))
tokens=auth['tokens']
def headers(s):
 data=b''
 while b'\r\n\r\n' not in data:
  chunk=s.recv(4096)
  if not chunk: raise RuntimeError('Connection closed before headers')
  data+=chunk
  if len(data)>65536: raise RuntimeError('Headers too large')
 return data.split(b'\r\n',1)[0].decode('ascii',errors='replace')
try:
 with socket.create_connection(('127.0.0.1',7897),timeout=12) as raw:
  raw.sendall(f'CONNECT {host}:443 HTTP/1.1\r\nHost: {host}:443\r\n\r\n'.encode())
  tunnel=headers(raw)
  if ' 200 ' not in tunnel: raise RuntimeError('Proxy tunnel failed: '+tunnel)
  with ssl.create_default_context().wrap_socket(raw,server_hostname=host) as s:
   key=base64.b64encode(os.urandom(16)).decode()
   fields=[f'GET /backend-api/codex/responses HTTP/1.1',f'Host: {host}','Connection: Upgrade','Upgrade: websocket','Sec-WebSocket-Version: 13',f'Sec-WebSocket-Key: {key}',f"Authorization: Bearer {tokens['access_token']}",f"ChatGPT-Account-ID: {tokens['account_id']}",'OpenAI-Beta: responses_websockets=2026-02-06','User-Agent: codex-proxy-diagnostic']
   s.sendall(('\r\n'.join(fields)+'\r\n\r\n').encode())
   status=headers(s)
   print(json.dumps({'proxy':'127.0.0.1:7897','websocket_status':status,'elapsed_seconds':round(time.monotonic()-started,2)}))
   if ' 101 ' not in status: raise SystemExit(2)
except Exception as exc:
 print(json.dumps({'error_type':type(exc).__name__,'elapsed_seconds':round(time.monotonic()-started,2)}))
 raise SystemExit(1)
