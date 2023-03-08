#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    int numbers[n];
    for(int i = 0; i < n; ++i){
        cin >> numbers[i];
    }
    sort(numbers, numbers+n); //Another would be keeping the two minimum and the two maximum elements while parsing the input.
    cout << min(numbers[n-1]-numbers[1], numbers[n-2]-numbers[0]) << endl;
    return 0;
}    