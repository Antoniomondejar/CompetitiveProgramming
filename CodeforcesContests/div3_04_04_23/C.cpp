#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long b[n-1];
        for(int i = 0; i < n-1; ++i){
            cin >> b[i];
        }
        bool satisfies = true;
        long long result[n];
        long long result2[n];
        int position_insertion = -1;
        int position_insertion2 = -1;
        for(int i = 0; i < n-1; ++i){
            result[i] = b[i];
            if(i < n-2 && result[i]<b[i+1]){
                result[i+1] = 0;
                position_insertion = i+1;
                break;
            }
        }
        if(position_insertion==-1){
            result[n-1] = 0;
        } else {
            for(int i = position_insertion+1; i < n; ++i){
                result[i] = b[i-1];
                if(result[i]==result[i-1] && (i==n-1 || result[i]!=b[i])){
                    result[i] = 0;
                }
            }
            for(int i = 0; i < n-1; ++i){
                satisfies = max(result[i], result[i+1]) == b[i];
                if(!satisfies)
                    break;
            }
            if (satisfies){
                for(int i = 0; i < n; ++i){
                   cout << result[i] << " ";
                }
                continue;        
            }
        }
        for(int i = n-1; i >= 1; --i){
            result[i] = b[i-1];
            if(i>1 && result[i]<b[i-2]){
                result[i-1] = 0;
                position_insertion2 = i-1;
                break;
            }
        }
        if(position_insertion2 == -1){
            result[0] = 0;
        } else {
            for(int i = position_insertion2-1; i >= 0; --i){
                result[i] = b[i];
                if(result[i] == result[i+1] && (i==0 || result[i]!=b[i-1]))
                    result[i] = 0;
            }
        }
        for(int i = 0; i < n; ++i){
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}