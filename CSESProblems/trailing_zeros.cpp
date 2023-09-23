#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    
    long long acumulador = 5;

    int resultado = 0;

    while(n>=acumulador){
        resultado += n/acumulador;
        acumulador *= 5;
    }

    cout << resultado << '\n';

    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/