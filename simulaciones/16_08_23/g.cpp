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
// const ll NMAX = 2e5+10;
// const ll MOD = 1e9+7;


typedef ll tf;
typedef long double tc;
const tf INFFLOW=1e9;
const tc INFCOST=1e9;
struct MCF{
	int n;
	vector<tc> prio, pot; vector<tf> curflow; vector<int> prevedge,prevnode;
	priority_queue<pair<tc, int>, vector<pair<tc, int>>, greater<pair<tc, int>>> q;
	struct edge{int to, rev; tf f, cap; tc cost;};
	vector<vector<edge>> g;
	MCF(int n):n(n),prio(n),curflow(n),prevedge(n),prevnode(n),pot(n),g(n){}
	void add_edge(int s, int t, tf cap, tc cost) {
		g[s].pb((edge){t,SZ(g[t]),0,cap,cost});
		g[t].pb((edge){s,SZ(g[s])-1,0,0,-cost});
	}
	pair<tf,tc> get_flow(int s, int t) {
		tf flow=0; tc flowcost=0;
		while(1){
			q.push({0, s});
			fill(ALL(prio),INFCOST); 
			prio[s]=0; curflow[s]=INFFLOW;
			while(!q.empty()) {
				auto cur=q.top();
				tc d=cur.fst;
				int u=cur.snd;
				q.pop();
				if(d!=prio[u]) continue;
				for(int i=0; i<SZ(g[u]); ++i) {
					edge &e=g[u][i];
					int v=e.to;
					if(e.cap<=e.f) continue;
					tc nprio=prio[u]+e.cost+pot[u]-pot[v];
					if(prio[v]>nprio) {
						prio[v]=nprio;
						q.push({nprio, v});
						prevnode[v]=u; prevedge[v]=i;
						curflow[v]=min(curflow[u], e.cap-e.f);
					}
				}
			}
			if(prio[t]==INFCOST) break;
			fore(i,0,n) pot[i]+=prio[i];
			tf df=min(curflow[t], INFFLOW-flow);
			flow+=df;
			for(int v=t; v!=s; v=prevnode[v]) {
				edge &e=g[prevnode[v]][prevedge[v]];
				e.f+=df; g[v][e.rev].f-=df;
				flowcost+=df*e.cost;
			}
		}
		return {flow,flowcost};
	}
};

tc mat[110][110];


int main(){FIN;
    ll n;cin>>n;
    MCF mc(2*n+5);
    fore(i,0,n){
        fore(j,0,n){
            cin>>mat[i][j]; mat[i][j]=log(mat[i][j]);
        }
    }
    ll s = 2*n, t=s+1;
    fore(i,0,n){
        mc.add_edge(s,i,1,0);
        fore(j,0,n){
            mc.add_edge(i,n+j,1,-mat[i][j]);
        }
        mc.add_edge(n+i,t,1,0);
    }
    tc res = mc.get_flow(s,t).fst;
    // cout << res << "\n";
    vector<ll> ans(n);
    cout << setprecision(10);
    fore(i,0,n){
        // cout << i << ": ";
        fore(j,0,SZ(mc.g[i])){
            // cout << mc.g[i][j].to << " ";
            if(mc.g[i][j].f>0){ans[mc.g[i][j].to-n]=i+1;break;}
        }
        // cout << "\n";
    }
    fore(i,0,n) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/