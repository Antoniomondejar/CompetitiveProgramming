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

vector<ll> g[2010];
ll vis[2010];


ll bfs(ll x){
    vis[x] = 1;
    queue<pair<ll,ll> > b;
    b.push({x,0});
    ll max_d = 0;
    while(SZ(b)){
        auto cv = b.front(); b.pop();
        fore(i,0,SZ(g[cv.fst])){
            auto n = g[cv.fst][i];
            if(vis[n]) continue;
            max_d = max(cv.snd+1, max_d);
            b.push({n,cv.snd+1});

        }
    }
    return max_d;
}

int main(){FIN;
    ll n; cin >> n;
    vector<ll> sup;
    fore(i,0,n){
        ll p; cin >> p; --p;
        if(p==-2){sup.pb(i); continue;}
        g[p].pb(i);
    }
    ll res = 0;
    fore(i,0,SZ(sup)){
        res = max(res,bfs(sup[i])+1);
    }
    cout << res << "\n";
    return 0;
}