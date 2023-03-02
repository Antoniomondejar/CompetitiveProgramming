#include <bits/stdc++.h>
using namespace std;
#include <limits.h>

int main(void){
    int n;
    cin >> n;
    long long values[n];
    for(int i = 0; i < n; ++i){
        cin >> values[i];
    }
    long long prefix_sum[n+1];
    prefix_sum[0] = 0;
    for(int i = 1; i < n+1; ++i){
        prefix_sum[i] = prefix_sum[i-1] + values[i-1];
    }
    long long min_prefix = 0;
    long long max_sum = LONG_LONG_MIN;
    for(int i = 1; i < n+1; ++i){
        max_sum = max(prefix_sum[i]-min_prefix, max_sum);
        min_prefix = min(min_prefix, prefix_sum[i]);
    }
    cout << max_sum << endl;
    return 0;
}