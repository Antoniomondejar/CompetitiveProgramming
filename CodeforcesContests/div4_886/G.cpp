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
        ll n;cin>>n;
        vector<pair<ll,ll>> a(n);
        fore(i,0,n)cin>>a[i].fst>>a[i].snd;
        map<pair<ll,ll>,ll>po_n,po_e,po_nw,po_sw;
        fore(i,0,n){
            fore(j,0,4){
                if(j==0){
                    po_n[{a[i].fst,0}]++;
                } else if(j==1){
                    po_e[{0,a[i].snd}]++;
                } else if(j==2){
                    po_nw[{0,a[i].snd+a[i].fst}]++;
                } else {
                    po_sw[{0,a[i].snd-a[i].fst}]++;
                }
            }
        }
        ll res = 0;
        for(auto i:po_n){
            res += i.snd * (i.snd-1);
        }
        for(auto i:po_e){
            res += i.snd*(i.snd-1);
        }
        for(auto i:po_nw){
            res += i.snd*(i.snd-1);
        }
        for(auto i:po_sw){
            // cout << i.fst.fst << " " << i.fst.snd << " " << i.snd << "\n";
            res += i.snd*(i.snd-1);
        }
        cout << res << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/