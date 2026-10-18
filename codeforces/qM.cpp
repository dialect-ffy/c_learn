// #include <iostream>
// #include <vector>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     vector<int> v(n);
//     for(int i = 0 ; i < n ; i ++)
//         cin >> v[i];
//     int q;
//     cin >> q;
//     int l , r , x , y;
//     for(int j = 0 ; j < q ; j ++){
//         cin >> l >> r >> x >> y;
//         for(int i = l -1 ; i <= r -1 ; i++){
//             if(v[i] == x) v[i] = y;
//         }
//     }
//     for(auto &e: v){
//         cout << e << " ";
//     }cout << endl;
//     return 0;
// }