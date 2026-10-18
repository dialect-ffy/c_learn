#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    //二分加贪心
    int n , k;
    cin >> n >> k;
    vector <long long> pos (n);
    vector <long long> result(k);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> pos[i];
    }
    sort(pos.begin(),pos.end());
    long long low = 0 , high = pos[n-1] - pos[0];
    while(low <= high){
        long long d = low + (high - low) / 2;
        vector <long long > chosen;
        chosen.push_back(pos[0]);
        for(int i = 1 ; i < n && chosen.size() < k ; i ++){
            if(pos[i] - chosen.back() >= d) chosen.push_back(pos[i]);
        }
        if(chosen.size() == k){
            result = chosen;
            low = d + 1;
        }else{
            high = d - 1;
        }
    }
    for(long long e : result){
        cout << e << ' ';
    }cout << endl;
    return 0;
}