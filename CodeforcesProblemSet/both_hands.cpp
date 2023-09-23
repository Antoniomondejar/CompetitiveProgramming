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

vector<pair<int,int> > g[NMAX], g_inv[NMAX];  // u->[(v,cost)]
ll dist_f[NMAX], dist_b[NMAX];
void dijkstra(int x){
    mset(dist_b,-1);mset(dist_f,-1);
	priority_queue<pair<pair<ll,int>,bool>> q;
	dist_b[x]=0;dist_f[x]=0;q.push({{0,x},false});
	while(!q.empty()){
		x=q.top().fst.snd;ll c=-q.top().fst.fst;
        bool ty=q.top().snd;q.pop();
        if(ty && dist_b[x]!=c)continue;
        if(!ty && dist_f[x]!=c)continue;
        if(!ty){
            fore(i,0,g[x].size()){
		// cout << x << " " << c << "\n";
                int y=g[x][i].fst; ll c=g[x][i].snd;
                if(dist_f[y]<0||dist_f[x]+c<dist_f[y])
                    dist_f[y]=dist_f[x]+c,q.push({{-dist_f[y],y},false});
            }
            fore(i,0,SZ(g_inv[x])){
                int y=g_inv[x][i].fst; ll c=g_inv[x][i].snd;
                if(dist_b[y]<0||dist_f[x]+c<dist_b[y])
                    dist_b[y]=dist_f[x]+c,q.push({{-dist_b[y],y},true});
            }
        } else {
            fore(i,0,SZ(g_inv[x])){
                int y=g_inv[x][i].fst; ll c=g_inv[x][i].snd;
                if(dist_b[y]<0||dist_b[x]+c<dist_b[y])
                    dist_b[y]=dist_b[x]+c,q.push({{-dist_b[y],y},true});
            }
        }
	}
}



int main(){FIN;
    ll n,m;cin>>n>>m;
    fore(i,0,m){
        ll x,y,c;cin>>x>>y>>c;--x;--y;
        g[x].pb({y,c});
        g_inv[y].pb({x,c});
    }
    dijkstra(0);
    fore(i,0,n){
        if(dist_b[i]==-1)dist_b[i]=1e18;
        if(dist_f[i]==-1)dist_f[i]=1e18;
    }
    fore(i,1,n){
        if(dist_b[i]>=1e18 && dist_f[i]>=1e18) cout << "-1 ";
        else cout << min(dist_b[i],dist_f[i]) << " ";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/