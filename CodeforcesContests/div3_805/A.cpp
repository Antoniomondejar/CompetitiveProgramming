#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    long long powers_of_ten[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
    while(t--){
        long long m;
        cin >> m;
        int nearest_power = 0;
        while(nearest_power < 10 && powers_of_ten[nearest_power] <= m)
            ++nearest_power;
        --nearest_power;
        cout << m - powers_of_ten[nearest_power] << endl;
    }
    return 0;
}