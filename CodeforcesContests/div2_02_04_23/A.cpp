#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n, result_xor, final_j;
        cin >> n;
        int array[n];
        int aux_array[n];
        for(int i = 0; i < n; ++i){
            cin >> array[i];
            aux_array[i] = array[i];
        }
        for(int j = 0; j < 256; ++j){
            for(int i = 0; i < n; ++i){
                array[i] = array[i] ^ j;
            }
            result_xor = array[0];
            array[0] = aux_array[0];
            for(int i = 1; i < n; ++i){
                result_xor = result_xor ^ array[i];
                array[i] = aux_array[i];
            }
            final_j = j;
            if (result_xor==0)
                break;
        }
        if (result_xor == 0){
            cout << final_j << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}