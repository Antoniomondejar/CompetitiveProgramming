#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        long long array[n];
        long long prefix_sum[n+1];
        prefix_sum[0] = 0;
        for(int i = 0; i < n; ++i){
            cin >> array[i];
            prefix_sum[i+1] = prefix_sum[i] + array[i];
            // cout << array[i] << " ";
        }
        // cout << endl;
        long long l, r, k, new_sum;
        for(int i = 0; i < q; ++i){
            cin >> l >> r >> k;
            new_sum = prefix_sum[n] - (prefix_sum[r]-prefix_sum[l-1]) + (r-l+1)*k;
            if (new_sum % 2 == 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}