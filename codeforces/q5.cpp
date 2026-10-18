// #include <iostream>
// using namespace std;
// #include <vector>
// #include <string>
// int main(){
//     //顺时针为正 逆时针为负 向后转就默认为顺时针吧。
   
//     int n;
//     cin >> n;
//     vector <string> v(n);
//     for(int i = 0 ; i < n ; i++)
//         cin >> v[i];
//     int finial = 0;
//     for(int i = 0 ; i < n ; i++){
//         if(v[i] == "right") finial++;
//         if(v[i] == "left") finial--;
//         if(v[i] == "back") finial += 2;
//     }
   
//         finial %= 4;
//         if(finial == 0) cout << "north" << endl;
//         if(finial == 1) cout << "east" << endl;
//         if(finial == 2) cout << "south" << endl;
//         if(finial == 3) cout << "west" << endl;
//         if(finial == -1) cout << "west" << endl;
//         if(finial == -2) cout << "south" << endl;
//         if(finial == -3) cout << "east" << endl;
    
//     return 0;
// }