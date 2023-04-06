#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long n,m,a;
    cin >> n >> m >> a;
    long long horizontal_flagstones = n/a + (n%a==0?0:1);
    long long vertical_flagstones = m/a + (m%a==0?0:1);
    cout << (horizontal_flagstones*vertical_flagstones) << endl;
    return 0;
}