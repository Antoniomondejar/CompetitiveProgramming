#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        long long n,c,d;
        cin >> n >> c >> d;
        long long array[n];
        long long to_add_before[n];
        long long final_cost = LONG_LONG_MAX;
        for(int i = 0; i < n; ++i){
            cin >> array[i];
        }
        sort(array, array+n);
        to_add_before[0] = array[0]-1;
        for(int i = 1; i < n; ++i){
            to_add_before[i] = array[i]-array[i-1]-1;
        }
        long long elements_needed_to_be_removed = 0;
        long long elements_added_before = 0;
        if(to_add_before[0] > 0)
            final_cost = min(final_cost, d+n*c);
        for(int i = 0; i < n; ++i){
            if(to_add_before[i]<0){
                final_cost = min(final_cost, elements_added_before*d + (elements_needed_to_be_removed+1+(n-(i+1)))*c);
                ++elements_needed_to_be_removed;
            } else {
                final_cost = min(final_cost, (elements_added_before+to_add_before[i]) * d + (elements_needed_to_be_removed+n-(i+1))*c);
                elements_added_before = elements_added_before + to_add_before[i];
            }
        }
        cout << final_cost << endl;
    }
    return 0;
}