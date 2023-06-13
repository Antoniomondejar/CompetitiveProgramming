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
        ll a,b; cin >> a >> b;
        if(a-b != 1) {cout << "NO\n";continue;}
        ll ab = a+b; bool p = true;
        if(ab%2==0) p = false;
        if(p){
            for(ll i = 3; i*i<=ab;i+=2){
                if(ab%i==0){
                    p = false;
                    break;
                }
            }
        }
        if(p) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/