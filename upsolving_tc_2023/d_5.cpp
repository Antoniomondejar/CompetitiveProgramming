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
const ll INF = 500;

ll a[210];
vector<vector<ll>> ans;
ll vis[210];

// Min cut: nodes with dist>=0 vs nodes with dist<0
// Matching MVC: left nodes with dist<0 + right nodes with dist>0
struct Dinic{
	int nodes,src,dst;
	vector<int> dist,q,work;
	struct edge {int to,rev;ll f,cap;};
	vector<vector<edge>> g;
	Dinic(int x):nodes(x),g(x),dist(x),q(x),work(x){}
	void add_edge(int s, int t, ll cap){
		g[s].pb((edge){t,SZ(g[t]),0,cap});
		g[t].pb((edge){s,SZ(g[s])-1,0,0});
	}
	bool dinic_bfs(){
		fill(ALL(dist),-1);dist[src]=0;
		int qt=0;q[qt++]=src;
		for(int qh=0;qh<qt;qh++){
			int u=q[qh];
			fore(i,0,SZ(g[u])){
				edge &e=g[u][i];int v=g[u][i].to;
				if(dist[v]<0&&e.f<e.cap)dist[v]=dist[u]+1,q[qt++]=v;
			}
		}
		return dist[dst]>=0;
	}
	ll dinic_dfs(int u, ll f){
		if(u==dst)return f;
		for(int &i=work[u];i<SZ(g[u]);i++){
			edge &e=g[u][i];
			if(e.cap<=e.f)continue;
			int v=e.to;
			if(dist[v]==dist[u]+1){
				ll df=dinic_dfs(v,min(f,e.cap-e.f));
				if(df>0){e.f+=df;g[v][e.rev].f-=df;return df;}
			}
		}
		return 0;
	}
	ll max_flow(int _src, int _dst){
		src=_src;dst=_dst;
		ll result=0;
		while(dinic_bfs()){
			fill(ALL(work),0);
			while(ll delta=dinic_dfs(src,INF))result+=delta;
		}
		return result;
	}
};

ll crib[100005];
vector<ll> g[210];


void dfs(ll x){
    vis[x]=1;
    ans.back().pb(x);
    fore(i,0,SZ(g[x])){
        if(vis[g[x][i]])continue;
        dfs(g[x][i]);
    }
}


int main(){FIN;
    ll n;cin>>n;
    fore(i,2,100005){
        if(!crib[i]){
            crib[i]=-1;
            for(int j = i+i; j<=100005;j+=i){
                crib[j]=i;
            }
        }
    }
    fore(i,0,n)cin>>a[i];
    Dinic di(n+2);
    ll s=n, t=s+1;
    fore(i,0,n){
        if(a[i]&1){
            di.add_edge(i,t,2);
            continue;
        }
        di.add_edge(s,i,2);
        fore(j,0,n){
            if(crib[a[i]+a[j]]==-1){
                di.add_edge(i,j,1);
            }
        }
    }
    ll f = di.max_flow(s,t);
    fore(i,0,n){
        if(a[i]&1)continue;
        fore(j,0,SZ(di.g[i])){
            if(di.g[i][j].f>0){
                g[i].pb(di.g[i][j].to);
                g[di.g[i][j].to].pb(i);
            }
        }
    }
    if(f!=n){cout << "Impossible\n";return 0;}
    fore(i,0,n){
        if(!vis[i]){
            ans.pb({});
            dfs(i);
        }
    }
    cout << SZ(ans) << "\n";
    fore(i,0,SZ(ans)){
        cout << SZ(ans[i]) << " ";
        fore(j,0,SZ(ans[i])){
            cout << ans[i][j]+1 << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/