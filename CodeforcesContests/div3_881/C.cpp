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

ll p2[60];

int main(){FIN;
    ll t; cin >> t;
    p2[0]=1; fore(i,1,60)p2[i]=p2[i-1]*2;
    while(t--){
        ll n; cin >> n; if(n==1){cout << "1\n";continue;}
        ll fsp2 = 0; ll lsp2 = 0; __int128_t acc = 1;
        while(acc < n){
            acc*=2; ++fsp2;
        }
        if(acc == n){
            ll res = 0;
            fore(i,0,fsp2+1){
                res += p2[i];
            }
            cout << res << "\n";
            continue;
        }
        --fsp2;
        lsp2 = fsp2+1; ll res = 1; ll ext_izq = p2[fsp2]; ll ext_der = p2[lsp2];
        ll last_sum = 1;
        fore(i,1,fsp2+1){
            ll m = (ext_der+ext_izq)/2;
            if(n<m){
                res += last_sum*2;
                last_sum = last_sum*2;
                ext_der = m;
            } else {
                res += last_sum*2 + 1;
                last_sum = 2*last_sum+1;
                ext_izq = m;
            }
        }
        cout << res << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/