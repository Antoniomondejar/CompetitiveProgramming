#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, weight;
    cin >> n;
    map<int,int> weights;
    weights[100] = 0; weights[200] = 0;
    for(int i = 0; i < n; ++i){
        cin >> weight;
        ++weights[weight];
    }
    weights[200] = weights[200]%2;
    if(weights[200] == 0){
        cout << ((weights[100]%2==0)?"YES":"NO") << endl;
    } else if(weights[100]<2){
        cout << "NO" << endl;
    } else {
        weights[100] = weights[100] - 2;
        cout << ((weights[100]%2==0)?"YES":"NO") << endl;
    }
    return 0;
}