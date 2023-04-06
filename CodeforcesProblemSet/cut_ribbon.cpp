#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    int array[4001];
    int abc[3] = {a,b,c};
    sort(abc,abc+3);
    for(int i = 0; i < 4001; ++i){
        if(i < abc[0])
            array[i] = INT_MIN;
        else if(i == abc[0])
            array[i] = 1;
        else if(i < abc[1])
            array[i] = 1+array[i-abc[0]];
        else if(i == abc[1])
            array[i] = max(1, 1+array[i-abc[0]]);
        else if(i < abc[2])
            array[i] = max(1+array[i-abc[1]], 1+array[i-abc[0]]);
        else if(i == abc[2])
            array[i] = max({1,1+array[i-abc[1]], 1+array[i-abc[0]]});
        else
            array[i] = max({1+array[i-abc[2]],1+array[i-abc[1]], 1+array[i-abc[0]]});
    }
    cout << array[n] << endl;
    return 0;
}