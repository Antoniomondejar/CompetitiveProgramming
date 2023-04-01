#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n%2 == 0){
            cout << -1 << endl;
            continue;
        }
        vector<int> operations;
        int number_of_operations = 0;
        for(int i = 0; i < 40 && n > 1; ++i){
            if ((n-1)/2 % 2 == 1){
                ++number_of_operations;
                operations.push_back(2);
                n = (n-1)/2;
            } else {
                ++number_of_operations;
                operations.push_back(1);
                n = (n+1)/2;
            }
        }
        if(n!=1){
            cout << -1 << endl;
        } else {
            cout << number_of_operations << endl;
            for(int i = 0; i < number_of_operations; ++i){
                cout << operations.at(number_of_operations-i-1) << " ";
            }
            cout << endl;
        }
    }
    return 0;
}