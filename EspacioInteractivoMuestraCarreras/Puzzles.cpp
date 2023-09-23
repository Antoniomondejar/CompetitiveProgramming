#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);

    for(int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    sort(a.begin(),a.end());

    int respuesta = 100000;

    for(int i = 0; i < m; ++i) {
        if(i + n - 1 >= m) {
            break;
        }
        respuesta = min(respuesta, a[i + n - 1] - a[i]);
    }

    cout << respuesta << '\n';
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/