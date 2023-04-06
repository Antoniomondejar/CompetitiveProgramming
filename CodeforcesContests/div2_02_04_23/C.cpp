#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        long long k, a, b, c;
        cin >> n >> m;
        set<long long> pendientes;
        std::_Rb_tree_const_iterator<long long> inmediatamente_menor;
        for(int i = 0; i < n; ++i){
            cin >> k;
            pendientes.insert(k);
        }
        long long discriminante;
        for(int i = 0; i < m; ++i){
            cin >> a >> b >> c;
            inmediatamente_menor = pendientes.lower_bound(b);
            if(inmediatamente_menor != pendientes.end()){
                discriminante = (b-*(inmediatamente_menor))*(b-*(inmediatamente_menor)) - 4*a*c;
                if(discriminante < 0){
                    cout << "YES" << endl;
                    cout << (*inmediatamente_menor) << endl;
                    continue;
                }
            }
            if (inmediatamente_menor != pendientes.begin())
                inmediatamente_menor--;
            discriminante = (b-*inmediatamente_menor)*(b-*inmediatamente_menor) - 4*a*c;
            if(discriminante < 0){
                cout << "YES" << endl;
                cout << (*inmediatamente_menor) << endl;
                continue;
            }
            cout << "NO" << endl;
        }
        cout << endl;
    }
    return 0;
}