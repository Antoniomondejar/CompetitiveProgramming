#include <bits/stdc++.h>
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
    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        string s;cin>>s;
        if(k%2==0){
            sort(ALL(s));
            cout << s << "\n";
            continue;
        }
        vector<char> par;
        vector<char> imp;
        fore(i,0,n){
            if(i&1) imp.pb(s[i]);
            else par.pb(s[i]);
        }
        sort(ALL(imp));sort(ALL(par));
        ll cont_imp = 0, cont_p = 0;
        fore(i,0,n){
            if(i&1){
                cout << imp[cont_imp];
                cont_imp++;
            } else {
                cout << par[cont_p];
                ++cont_p;
            }
        }
        cout << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/