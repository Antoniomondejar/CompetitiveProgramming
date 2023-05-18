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
const ll MAXN = 8e5+10; // 8 porque voy a "armar" 3 grafos auxiliares pero va a estar todo dentro del mismo g
// De 0 a n-1 el grafo de input, de n a 2n-1 el grafo de restar max, de 2n a 3n-1 el grafo de sumar dos veces min y de 3n a 4n-1 el grafo que junta ambos.

vector<pair<int,int> > g[MAXN];  // u->[(v,cost)]
ll dist[MAXN];
ll dist1[MAXN];
void dijkstra(int x){
	memset(dist,-1,sizeof(dist));
	priority_queue<pair<ll,int> > q;
	dist[x]=0;q.push({0,x});
	while(!q.empty()){
		x=q.top().snd;ll c=-q.top().fst;q.pop();
		if(dist[x]!=c)continue;
		fore(i,0,g[x].size()){
			int y=g[x][i].fst; ll c=g[x][i].snd;
			if(dist[y]<0||dist[x]+c<dist[y])
				dist[y]=dist[x]+c,q.push({-dist[y],y});
		}
	}
}

int main(){FIN;
    ll n,m; cin >> n >> m;
    fore(i,0,m){
        ll x,y,c; cin>>x>>y>>c; --x;--y;
        if(x==0)dist1[y]=c;
        if(y==0)dist1[x]=c;
        g[x].pb({y,c});g[y].pb({x,c});
        g[x+n].pb({y+n,c});g[y+n].pb({x+n,c});
        g[x+2*n].pb({y+2*n,c});g[y+2*n].pb({x+2*n,c});
        g[x+3*n].pb({y+3*n,c});g[y+3*n].pb({x+3*n,c});
        g[x].pb({y+n,0});g[y].pb({x+n,0});
        g[x].pb({y+2*n,2*c});g[y].pb({x+2*n,2*c});
        g[x+n].pb({y+3*n,2*c});g[y+n].pb({x+3*n,2*c});
        g[x+2*n].pb({y+3*n,0});g[y+2*n].pb({x+3*n,0});
    }
    dijkstra(0);
    fore(i,1,n){
        if(dist1[i]!=0) cout << min(dist1[i],dist[i+3*n]) << " ";
        else cout << dist[i+3*n] << " ";
    }
    cout << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/