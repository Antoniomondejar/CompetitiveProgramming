#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

vector<set<pair<ll,ll>>> hvs;
vector<pair<ll,ll>> vi;
vector<pair<vector<ll>,ll>> g;

pair<ll,ll> dfs(ll v, ll f, ll *a){
    ll im = a[v];
    ll d = SZ(g[v].first);
    ll n; ll ss = 1;
    pair<ll,ll> rn;
    fore(i, 0, d){
        n = g[v].first[i];
        if(n!=f){
            rn = dfs(n, v, a);
            ss += rn.second;
            im += rn.first;
            hvs[v].insert(mp(-rn.second, n));
        }
    }
    vi[v] = mp(im, ss);
    return mp(im, ss);
}

int main(){FIN;
    ll n, m, x1, x2;
    cin >> n >> m;
    ll *a = (ll *) calloc(n, sizeof(ll));
    fore(i,0,n){
        cin>>a[i];
        g.push_back(mp(vector<ll>{},0));
        hvs.push_back(set<pair<ll,ll>>{});
        vi.push_back(mp(0,0));
    }
    fore(i,0,n-1){
        cin >> x1 >> x2;
        g[x1-1].first.push_back(x2-1);
        g[x2-1].first.push_back(x1-1);
    }
    vector<ll> vis(n,0);
    queue<ll> bfs;
    ll v = 0; ll d, ne, fi;
    bfs.push(v);
    vis[0] = 1;
    while(SZ(bfs)>0){
        v = bfs.front();
        bfs.pop();
        d = SZ(g[v].first);
        fore(i,0,d){
            ne = g[v].first[i];
            if (ne != g[v].second) g[ne].second = v;
            if (vis[ne] == 0){
                vis[ne] = 1;
                bfs.push(ne);
            }
        }
    }
    dfs(0,0,a);
    // fore(i,0,n) cout << vi[i].first << " ";
    fore(i,0,m){
        cin >> x1 >> x2;
        --x2;
        if(x1==1) cout << vi[x2].first << "\n";
        else if (SZ(hvs[x2])>0){
            auto hs = hvs[x2].begin();
            fi = g[x2].second;
            g[hs->second].second = fi;
            g[x2].second = hs->second;
            vi[x2].first -= vi[hs->second].first;
            hvs[x2].erase(mp(hs->first, hs->second));
            hvs[fi].erase(mp(-vi[x2].second, x2));
            vi[hs->second].first += vi[x2].first;
            vi[x2].second -= vi[hs->second].second;
            vi[hs->second].second += vi[x2].second;
            hvs[fi].insert(mp(-vi[hs->second].second, hs->second));
            hvs[hs->second].insert(mp(-vi[x2].second, x2)); 
        }
    }
    return 0;
}