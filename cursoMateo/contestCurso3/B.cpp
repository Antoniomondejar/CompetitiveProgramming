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

vector<ll> g[1010];

int main(){FIN;
    ll n; cin >> n;
    fore(i,1,n){
        ll x; cin >> x; --x;
        g[x].pb(i);
    }
    bool p = true;
    fore(i,0,n){
        if(SZ(g[i])){
            ll leaf_c = 0;
            fore(j,0,SZ(g[i])){
                auto n = g[i][j];
                if(SZ(g[n])==0) ++leaf_c;
                if(leaf_c == 3) break;
            }
            if(leaf_c<3){
                p = false;
                cout << "No\n";
                break;
            }
        }
    }
    if(p) cout << "Yes\n";
    return 0;
}