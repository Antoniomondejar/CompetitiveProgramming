#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define str string
#define fore(i,a,b) for(int i=a,thxMat=b;i<thxMat;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll NMAX = 2e5+10;
const ll MOD = 1e9+7;

vector<ll> g[NMAX];
ll pa[NMAX];
pair<ll,ll> ci;
ll vis[NMAX];

void dfs(ll x){
    vis[x]=1;
    fore(i,0,SZ(g[x])){
        if(vis[g[x][i]]){
            if(g[x][i]!=pa[x] && ci.fst==-1){
                ci={x,g[x][i]};
            }
            continue;
        }
        pa[g[x][i]]=x;
        dfs(g[x][i]);
    }
}

ll dist[NMAX][2];

void bfs(ll x, ll cual){
    vis[x]=1;
    queue<ll> q;q.push(x);
    dist[x][cual]=0;
    while(SZ(q)){
        auto cv = q.front();q.pop();
        fore(i,0,SZ(g[cv])){
            if(vis[g[cv][i]])continue;
            vis[g[cv][i]]=1;
            dist[g[cv][i]][cual]=dist[cv][cual]+1;
            q.push(g[cv][i]);
        }
    }
}

int main(){FIN;
    ll t;cin>>t;
    while(t--){
        ll n,a,b;cin>>n>>a>>b;--a;--b;
        fore(i,0,n)g[i].clear(),vis[i]=0;
        fore(i,0,n){
            ll x,y;cin>>x>>y;--x;--y;
            g[x].pb(y);g[y].pb(x);
        }
        ci={-1,-1};
        pa[0]=-1;
        dfs(0);
        fore(i,0,n)vis[i]=0;
        bfs(a,0);
        fore(i,0,n)vis[i]=0;
        bfs(b,1);
        bool p = false;
        ll act = ci.fst; ll quiero = ci.snd;
        //cout << quiero << " ";
        while(act != quiero){
            if(dist[act][0]>dist[act][1]){p=true;break;}
            //cout << act << " " << pa[act] << " " << quiero << "\n";
            act = pa[act];
        }
        if(dist[quiero][0]>dist[quiero][1])p=true;
        if(p)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/