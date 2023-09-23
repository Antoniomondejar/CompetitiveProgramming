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
typedef long double ld;
const ll NMAX = 1e5+10;
const ll MOD = 1e9+7;

vector<pair<int,ll> > g[NMAX];  // u->[(v,cost)]
ll dist[NMAX];
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
    ll t;cin>>t;
    while(t--){
        ll n,m,k;cin>>n>>m>>k;
        cout<<setprecision(8)<<fixed;
        fore(i,0,m){
            ll x,y,c;cin>>x>>y>>c;--x;--y;
            g[x].pb({y,c});
            g[y].pb({x,c});
        }
        dijkstra(n-1);
        vector<ll> dis(n);
        fore(i,0,n){
            dis[i]=(dist[i]==-1)?1e18:dist[i];
        }
        ld res=ld(dis[0]);ld acc=0;
        sort(ALL(dis));
        fore(i,0,n){
            if(dis[i]==1e18)break;
            acc+=ld(dis[i]);
            // cout << ld(k)*ld(n)/(ld(i+1))+acc/(ld(i+1)) << "\n";
            res=min(res,ld(k)*ld(n)/(ld(i+1))+acc/(ld(i+1)));
        }
        cout << res << "\n";
        fore(i,0,n)g[i].clear();
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/