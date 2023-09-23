#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string stones;
    cin >> stones;

    char last_stone = stones[0];
    int resultado = 0;

    for (int i = 1; i < n; ++i) {
        if(last_stone == stones[i]) {
            resultado++;
        }
        last_stone = stones[i];
    }

    cout << resultado << '\n';

    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/