from pathlib import Path
from xml.sax.saxutils import escape
from reportlab.pdfgen import canvas
from reportlab.lib.pagesizes import A4
from reportlab.lib.colors import HexColor
from reportlab.pdfbase import pdfmetrics
from reportlab.pdfbase.ttfonts import TTFont
from reportlab.platypus import Paragraph
from reportlab.lib.styles import ParagraphStyle
from pypdf import PdfReader

ROOT = Path('D:/about_vs_code/code')
OUT = ROOT / 'output/pdf/美国中东军事与外交部署_中英双语.pdf'
OUT.parent.mkdir(parents=True, exist_ok=True)
pdfmetrics.registerFont(TTFont('Song', 'C:/Windows/Fonts/simsun.ttc', subfontIndex=0))
pdfmetrics.registerFont(TTFont('Hei', 'C:/Windows/Fonts/simhei.ttf'))
pdfmetrics.registerFont(TTFont('Arial', 'C:/Windows/Fonts/arial.ttf'))
pdfmetrics.registerFont(TTFont('ArialBold', 'C:/Windows/Fonts/arialbd.ttf'))

blocks = [
('局势概览',
'当地时间2026年10月上旬，美国在中东军事行动、对外制裁、国际外交等领域接连出台新举措，密集的政策调整持续搅动中东地缘政治格局，区域安全局势不确定性显著增加。',
'As of early October 2026 local time, the United States has rolled out a string of new measures regarding military operations, external sanctions and diplomatic affairs in the Middle East. These frequent policy shifts keep shaking the geopolitical landscape of the region and bring markedly rising uncertainties to regional security.'),
('对伊军事备战与制裁',
'10月7日，多名美国政府官员向媒体证实，美国国防部已正式向美军中央司令部下达指令，要求短期内完成对伊朗开展大规模军事打击的全套备战工作。据美国阿克西奥斯新闻网披露，此次备战指令明确了兵力调配、装备部署、应急方案等多项筹备任务，但并未划定具体军事行动时间，美国总统特朗普尚未对是否发起打击作出最终决策。与此同时，美国国务院同步跟进制裁手段，于10月8日宣布针对伊朗影子船队网络实施新一轮专项制裁，通过切断相关航运、经济链路，进一步压缩伊朗对外发展空间，配合军事备战布局。',
'On October 7, multiple U.S. administration officials confirmed to the media that the U.S. Department of Defense had formally issued orders to U.S. Central Command to complete full preparations for potential large-scale military strikes against Iran in a short timeframe. According to U.S. news website Axios, the preparation order specified a series of tasks including troop deployment, equipment arrangement and contingency plans. However, no timeline for military action was set, and U.S. President Donald Trump has not yet made the final decision on whether to launch strikes. Meanwhile, the U.S. State Department rolled out corresponding sanctions. On October 8, it announced a new round of targeted sanctions against Iran’s shadow shipping network to cut off relevant shipping and economic links, further limit Iran’s external development space and coordinate with military preparedness.'),
('也门局势',
'在也门局势层面，美国也释放出更强的军事干预信号。10月10日，特朗普公开表态，美国大概率会介入针对也门胡塞武装的军事行动，相关决策将在短期内敲定。此前胡塞武装多次在红海区域开展军事行动，影响国际航运安全，美方以此为理由，持续加码中东军事部署，扩大区域军事介入范围。',
'On the Yemen front, the United States has sent stronger signals of military intervention. On October 10, Trump stated publicly that the U.S. would most likely get involved in military operations targeting Yemen’s Houthi forces, with relevant decisions to be finalized soon. Previously, Houthi forces had carried out multiple military operations in the Red Sea, disrupting international shipping security. Citing this as the reason, the U.S. continues to beef up its military deployment in the Middle East and expand the scope of regional military involvement.'),
('美俄外交互动',
'除军事布局外，美俄外交互动也迎来新动态。10月7日，俄罗斯总统新闻秘书佩斯科夫公开回应美俄元首通话事宜，表示目前普京与特朗普的通话尚未敲定具体细节，但俄方保持开放态度，只要美方提出沟通倡议，俄方将第一时间推进协调工作，为两国缓解博弈态势预留外交空间。',
'Beyond military arrangements, new developments have emerged in U.S.-Russia diplomatic exchanges. On October 7, Kremlin spokesman Dmitry Peskov commented publicly on the potential phone call between the Russian and U.S. presidents. He said specific details of the conversation between Putin and Trump had not been finalized. Nevertheless, Russia maintains an open attitude. Should the U.S. put forward a communication proposal, Russia will push forward coordination promptly to reserve diplomatic room for the two sides to ease their rivalry.'),
('区域影响与后续观察',
'一系列动作落地后，中东地区军事对峙、博弈氛围持续加剧。分析人士表示，美国近期军事备战与制裁并行的策略，旨在强化其中东主导地位，但大规模军事干预的潜在风险极高，一旦开启军事行动，或将引发中东多国连锁反应，进一步冲击区域和平稳定与全球能源、航运秩序。目前，国际社会正密切关注美方最终决策，静待区域局势后续走向。',
'With this series of measures taking effect, the atmosphere of military standoff and rivalry in the Middle East keeps intensifying. Analysts argue that Washington’s recent strategy combining military preparedness and sanctions aims to consolidate its dominant position in the Middle East. Still, large-scale military intervention carries extremely high risks. Once military operations start, it may trigger chain reactions across multiple Middle Eastern states and further undermine regional peace and stability as well as global energy and shipping order. At present, the international community is closely watching Washington’s final decision and waiting for further developments of the regional situation.')
]

W, H = A4
M = 47
WIDTH = W - 2*M
INK = HexColor('#202C38')
ACCENT = HexColor('#28566A')
GRAY = HexColor('#64717C')
RULE = HexColor('#D4DFE5')
cn_style = ParagraphStyle('CN', fontName='Song', fontSize=11, leading=17.5,
    textColor=INK, wordWrap='CJK', firstLineIndent=22)
en_style = ParagraphStyle('EN', fontName='Arial', fontSize=10.1, leading=14.4,
    textColor=HexColor('#45515E'))
heading_style = ParagraphStyle('Heading', fontName='Hei', fontSize=12, leading=18, textColor=ACCENT)

c = canvas.Canvas(str(OUT), pagesize=A4, pageCompression=1)
c.setTitle('美国近期密集推进中东军事与外交部署 区域局势持续升温')
c.setAuthor('新华社综合报道（按提供稿件排版）')

def paragraph(text, style, y, x=M, width=WIDTH):
    p = Paragraph(escape(text), style)
    _, h = p.wrap(width, H)
    p.drawOn(c, x, y-h)
    return y-h

def frame(page):
    c.setFillColor(ACCENT)
    c.rect(M, H-40, 19, 3, fill=1, stroke=0)
    c.setFont('Hei', 9)
    c.drawString(M+27, H-41, '国际观察  /  中英双语')
    c.setFont('Arial', 8)
    c.setFillColor(GRAY)
    c.drawRightString(W-M, H-41, 'OCTOBER 2026')
    c.setStrokeColor(RULE)
    c.setLineWidth(.5)
    c.line(M, 42, W-M, 42)
    c.setFont('Hei', 8)
    c.drawString(M, 27, '美国中东军事与外交部署')
    c.setFont('Arial', 8)
    c.drawRightString(W-M, 27, f'{page:02d} / 02')

def draw_block(b, y):
    heading, cn, en = b
    y = paragraph(heading, heading_style, y)-7
    y = paragraph(cn, cn_style, y)-10
    c.setFillColor(ACCENT)
    c.setFont('ArialBold', 7.1)
    c.drawString(M, y-7, 'ENGLISH REPORT')
    y -= 15
    y = paragraph(en, en_style, y)
    return y

frame(1)
y=H-73
title = ParagraphStyle('Title', fontName='Hei', fontSize=22, leading=31, textColor=INK)
y=paragraph('美国近期密集推进中东军事与外交部署', title, y)
subtitle = ParagraphStyle('Subtitle', fontName='Hei', fontSize=17, leading=25, textColor=ACCENT)
y=paragraph('区域局势持续升温', subtitle, y-4)-13
c.setFillColor(GRAY)
c.setFont('Song', 10)
c.drawString(M, y-10, '新华社综合报道')
y-=26
c.setStrokeColor(ACCENT)
c.setLineWidth(1)
c.line(M, y, W-M, y)
y-=20
y=draw_block(blocks[0],y)-23
y=draw_block(blocks[1],y)
print('Page 1 bottom:',y)
assert y > 60, 'Page 1 overflows'
c.showPage()
frame(2)
y=H-72
for i,b in enumerate(blocks[2:]):
    y=draw_block(b,y)
    if i<2:
        y-=12
        c.setStrokeColor(RULE)
        c.setLineWidth(.5)
        c.line(M,y,W-M,y)
        y-=19
print('Page 2 bottom:',y)
assert y > 60, 'Page 2 overflows'
c.save()
r=PdfReader(str(OUT))
assert len(r.pages)==2
extracted=''.join(p.extract_text() for p in r.pages)
for _,cn,en in blocks:
    assert ''.join(cn.split()) in ''.join(extracted.split()), 'Missing Chinese text'
    assert ''.join(en.split()) in ''.join(extracted.split()), 'Missing English text'
print('Verified all five Chinese and English sections; 2 pages.')
print(OUT)
