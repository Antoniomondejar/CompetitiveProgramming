#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; ++i) {
        int a, b;
        cin >> a >> b;
        int resultado;
        if(b > a) {
            resultado = (b - a) / 10;
            if((b - a) % 10 > 0) {
                ++resultado;
            }
        } else {
            resultado = (a - b) / 10;
            if((a - b) % 10 > 0) {
                ++resultado;
            }
        }
        cout << resultado << '\n';
    }

    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/