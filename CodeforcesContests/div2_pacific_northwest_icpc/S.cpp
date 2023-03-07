#include <bits/stdc++.h>
using namespace std;

// int abs(int x){
//     if (x>=0)
//         return x;
//     return -x;
// }

int main(void){
    string rain;
    cin >> rain;
    int length = rain.length();
    int Rs[length], Bs[length];
    for(int i = 0; i < length; ++i){
        if (rain[i]=='B'){
            Rs[i] = -1;
            Bs[i] = 1;
        } else {
            Rs[i] = 1;
            Bs[i] = -1;
        }
    }
    int Rs_prefix_sum[length+1]; int Bs_prefix_sum[length+1];
    Rs_prefix_sum[0] = 0; Bs_prefix_sum[0] = 0;
    for(int i = 1; i < length+1; ++i){
        Rs_prefix_sum[i] = Rs_prefix_sum[i-1] + Rs[i-1];
        Bs_prefix_sum[i] = Bs_prefix_sum[i-1] + Bs[i-1];
    }
    int min_prefix_sum_bs = 0; int min_prefix_sum_rs = 0;
    int left_bs = 0; int right_bs = 0; int left_rs = 0; int right_rs = 0;
    int max_difference_bs = 0; int max_difference_rs = 0;
    for(int i = 1; i < length+1; ++i){
        if (min_prefix_sum_bs > Bs_prefix_sum[i]){
            min_prefix_sum_bs = Bs_prefix_sum[i];
            left_bs = i;
        }
        if (min_prefix_sum_rs > Rs_prefix_sum[i]){
            min_prefix_sum_rs = Rs_prefix_sum[i];
            left_rs = i;
        }
        if(max_difference_bs < (Bs_prefix_sum[i]-min_prefix_sum_bs)){
            max_difference_bs = (Bs_prefix_sum[i]-min_prefix_sum_bs);
            right_bs = (i-1);
        }
        if(max_difference_rs < (Rs_prefix_sum[i]-min_prefix_sum_rs)){
            max_difference_rs = (Rs_prefix_sum[i]-min_prefix_sum_rs);
            right_rs = (i-1);
        }
    }

    if(max_difference_bs > max_difference_rs){
        cout << left_bs+1 << " " << right_bs+1 << endl;
        return 0;
    } else if (max_difference_rs > max_difference_bs) {
        cout << left_rs+1 << " " << right_rs+1 << endl;
        return 0;
    } else {
        if (left_rs < left_bs){
            cout << left_rs+1 << " " << right_rs+1 << endl;
            return 0;
        } else if (left_bs < left_rs){
            cout << left_bs+1 << " " << right_bs+1 << endl;
            return 0;
        } else {
            if (right_rs < right_bs) {
                cout << left_rs+1 << " " << right_rs+1 << endl;
                return 0;
            } else {
                cout << left_bs+1 << " " << right_bs+1 << endl;
                return 0;
            }
        }
    }
}