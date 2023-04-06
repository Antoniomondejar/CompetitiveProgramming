#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<long long> array(n);
    vector<long long> prefix_sum(n+1); prefix_sum[0] = 0;
    vector<long long> ordered_prefix_sum(n+1); ordered_prefix_sum[0] = 0;
    for(int i = 0; i < n; ++i){
        cin >> array[i];
        prefix_sum[i+1] = prefix_sum[i] + array[i];
    }
    sort(array.begin(),array.end());
    for(int i = 0; i < n; ++i){
        ordered_prefix_sum[i+1] = ordered_prefix_sum[i] + array[i];
    }
    int m, l, r, type;
    cin >> m;
    while(m--){
        cin >> type >> l >> r;
        if(type == 1)
            cout << (prefix_sum[r] - prefix_sum[l-1]) << "\n";
        else
            cout << (ordered_prefix_sum[r] - ordered_prefix_sum[l-1]) << "\n";
    }
    return 0;
}