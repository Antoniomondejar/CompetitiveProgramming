#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long array[n];
        long long prefix_sum[n+1];
        prefix_sum[0] = 0;
        set<int> prefix_sum_set;
        for(int i = 0; i < n; ++i){
            cin >> array[i];
        }
        sort(array, array+n);
        for(int i = 0; i < n; ++i)
            prefix_sum[i+1] = prefix_sum[i]+array[i];
        bool equal = array[0] == 1;
        for(int i = 1; i < n; ++i){
            if (prefix_sum[i]<array[i]){
                equal = false;
                break;
            }
        }
        if (!equal)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}