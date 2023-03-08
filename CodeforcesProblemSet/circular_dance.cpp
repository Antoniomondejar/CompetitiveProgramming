#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, a1, a2;
    cin >> n;
    pair<int,int> aux;
    pair<int,int> kids_memory[n];
    if (n==3){
        cout << "1 2 3" << endl;
        return 0;
    }
    for(int i = 0; i < n; ++i){
        cin >> a1 >> a2;
        kids_memory[i] = make_pair(a1-1,a2-1);
    }
    for(int i = 0; i < n; ++i){
        aux = kids_memory[i];
        if(kids_memory[aux.second].first == aux.first || kids_memory[aux.second].second == aux.first){
            kids_memory[i] = make_pair(aux.second, aux.first);
        }
    }
    cout << 1 << " ";
    aux = kids_memory[0];
    for(int i = 1; i < n; ++i){
        cout << aux.first + 1 << " ";
        aux = kids_memory[aux.first];
    }
    return 0;
}