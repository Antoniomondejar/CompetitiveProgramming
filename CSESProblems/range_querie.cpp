#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,q;
    cin >> n >> q;
    long long values[n];
    for(int i = 0; i < n; ++i){
        cin >> values[i];
    }
    long long prefix_sum[n+1];
    prefix_sum[0] = 0;
    for(int i = 1; i < n+1; ++i){
        prefix_sum[i] = prefix_sum[i-1] + values[i-1];
    }
    int a,b;
    while(q--){
        cin >> a >> b;
        cout << prefix_sum[b]-prefix_sum[a-1] << endl;
    }
    return 0;
}