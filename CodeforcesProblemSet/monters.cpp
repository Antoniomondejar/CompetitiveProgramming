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
const ll NMAX = 2*1e5+10;

ll pa[NMAX];
ll sz[NMAX];
priority_queue<pair<ll,ll>> pq[NMAX];
vector<ll> a;
vector<ll> g[NMAX];

ll find(ll x){
    return (pa[x]==x?x:pa[x]=find(pa[pa[x]]));
}
void join(ll x, ll y){
    ll pa_x = find(x), pa_y = find(y);
    if(pa_x == pa_y)return;
    if(sz[pa_x]>sz[pa_y])swap(pa_x,pa_y);
    sz[pa_y]+=sz[pa_x];
    pa[pa_x] = pa_y;
    while(SZ(pq[pa_x])){
        auto f = pq[pa_x].top();
        pq[pa_y].push(f);
        pq[pa_x].pop();
    }
}

void dsu_init(ll n){
    fore(i,0,n){
        sz[i] = 1; pa[i] = i;
        while(SZ(pq[i])) pq[i].pop();
        for(auto n:g[i]){
            pq[i].push({-a[n], n});
        }
    }
}

void prim(ll x){
    while(SZ(pq[find(x)])){
        auto n = pq[find(x)].top(); pq[find(x)].pop();
        if(find(n.snd) == find(x)) continue;
        if(-n.fst<=sz[find(x)]){
            join(n.snd, x);
        } else {
            pq[find(x)].push(n);
            break;
        }
    }
}


int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        a.clear();
        a.resize(n);
        fore(i,0,n) cin >> a[i];
        fore(i,0,n) g[i].clear();
        fore(i,0,m){
            ll x,y; cin >> x >> y; --x,--y;
            g[x].pb(y); g[y].pb(x);
        }
        dsu_init(n); bool p = false;
        fore(i,0,n){
            if(a[i] == 0 && sz[find(i)] == 1 && find(i) == i){
                prim(i);
                if(sz[find(i)] == n){
                    cout << "YES\n";
                    p = true;
                    break;
                }
        }
            }
        if(!p) cout << "NO\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/