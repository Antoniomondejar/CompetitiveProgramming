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

vector<deque<ll>> g;
ll vis[100005];
ll pa[100005];

ll dfs(ll v){
    ll res;
    if(!vis[v]) return v;
    ll sz = SZ(g[v]);
    fore(i,0,sz){
        res = dfs(g[v][0]);
        if(res!=-1) return res;
    }
    g[pa[v]].pop_front();
    return -1;
}


int main(){FIN;
    ll Q, ty, inp; cin >> Q;
    ll id = 1; ll k = 0;
    g.pb({});
    while(Q--){
        cin >> ty;
        if(ty == 1){
            cin >> inp; --inp;
            g[inp].pb(id);
            g.pb({});
            pa[id] = inp;
            ++id;
        } else {
            cin >> inp; --inp;
            vis[inp] = 1;
            if(inp==k){
                k = dfs(0);
                cout << k+1 << "\n";
            } else {
                cout << k+1 << "\n";
            }
        }
    }
    return 0;
}