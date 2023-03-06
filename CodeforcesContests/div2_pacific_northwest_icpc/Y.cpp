#include <bits/stdc++.h>
using namespace std;
#include <math.h>

int main(void){
    long double K,P,X;
    long double one = 1.0;
    cin >> K >> P >> X;
    long double number_of_painters = round(sqrt(K*P/X));
    cout << K*P/number_of_painters << endl;
    cout << (long double) (X * number_of_painters) << endl;
    long double cost = K*P/number_of_painters + (X * number_of_painters);
    printf("%3.Lf\n", cost);
    return 0;
}
