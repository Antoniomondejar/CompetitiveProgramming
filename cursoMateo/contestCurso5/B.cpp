#include "bits/stdc++.h"
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define str string
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll NMAX = 2e5+10;
const ll MOD = 1e9+7;

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll aux = n; ll n_3 = 0;
        if(n==1){cout << "0\n";continue;}
        while(aux%3==0){
            ++n_3;
            aux/=3;
        }
        ll n_2 = 0;
        while(aux%2==0){
            ++n_2;
            aux/=2;
        }
        if(aux>1 || n_3 == 0 || n_2 > n_3){
            cout << "-1\n";
            continue;
        }
        cout << n_3+(n_3-n_2) << '\n';
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/