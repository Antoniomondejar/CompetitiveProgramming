#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;int counting_positions = 0; int last_zero = 1;
    cin >> n;
    string brackets;
    cin >> brackets;
    if (n%2 != 0){
        cout << 0 << endl;
        return 0;
    }
    int brackets_number[n];
    for(int i = 0; i < n; ++i){
        if (brackets[i] == '(')
            brackets_number[i] = 1;
        else
            brackets_number[i] = -1;
    }
    int sum_prefix_brackets[n+1];
    sum_prefix_brackets[0] = 0;
    for(int i = 1; i < n+1; ++i){
        sum_prefix_brackets[i] = sum_prefix_brackets[i-1] + brackets_number[i-1];
        if (sum_prefix_brackets[i] < -2){
            cout << 0 << endl;
            return 0;
        }
        if (sum_prefix_brackets[i] == 0)
            last_zero = i;
    }
    if (sum_prefix_brackets[n] == 0 || sum_prefix_brackets[n] > 2 || sum_prefix_brackets[n] < -2){
        cout << 0 << endl;
        return 0;
    }
    int unbalance = sum_prefix_brackets[n];
    if (unbalance == -2){
        for(int i = 1; i < n; ++i){
            if (sum_prefix_brackets[i]<sum_prefix_brackets[i-1]){
                ++counting_positions;
                if (sum_prefix_brackets[i]==-2)
                    break;
            }
        }
    } else {
        for(int i = 2; i < n+1; ++i){
            if(sum_prefix_brackets[i]>sum_prefix_brackets[i-1])
                ++counting_positions;
        }
    }
    cout << counting_positions << endl;
    return 0;
}