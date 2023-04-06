#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        long long n,x1,y1,x2,y2;
        cin >> n >> x1 >> y1 >> x2 >> y2;
        x1 = min(x1, n-x1+1); y1 = min(y1,n-y1+1); x2 = min(x2, n-x2+1); y2 = min(y2, n-y2+1);
        long long matrix_1 = min(x1,y1);
        long long matrix_2 = min(x2,y2);
        matrix_1 = matrix_1==(n/2)+1?matrix_1-1:matrix_1;
        matrix_2 = matrix_2==(n/2)+1?matrix_2-1:matrix_2;
        cout << abs(matrix_1-matrix_2) << endl;
    }
    return 0;
}
