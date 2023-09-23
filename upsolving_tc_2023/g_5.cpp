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
const int K = 20;


pair<ll,ll> pa[NMAX];
ll sz[NMAX], repr[NMAX], head[NMAX];
vector<pair<ll,ll>> ed;


vector<pair<ll,ll>> g[1<<K];int n,m;  // K such that 2^K>=n
int F[K][1<<K],D[1<<K];
void lca_dfs(int x){
	fore(i,0,g[x].size()){
		int y=g[x][i].fst;if(y==F[0][x])continue;
		pa[y]={x,g[x][i].snd};
        F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
	}
}
void lca_init(){
	D[0]=0;F[0][0]=-1;
	lca_dfs(0);
	fore(k,1,K)fore(x,0,n)
		if(F[k-1][x]<0)F[k][x]=-1;
		else F[k][x]=F[k-1][F[k-1][x]];
}
int lca(int x, int y){
	if(D[x]<D[y])swap(x,y);
	for(int k=K-1;k>=0;--k)if(D[x]-(1<<k)>=D[y])x=F[k][x];
	if(x==y)return x;
	for(int k=K-1;k>=0;--k)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];
	return F[0][x];
}

void dsu_init(){
    fore(i,0,n)repr[i]=i,sz[i]=1, head[i]=i;
}

ll find(ll x){
    if(repr[x]==x)return x;
    return repr[x]=find(repr[x]);
}

ll join(ll x, ll y){
    if(find(x)==find(y))return false;
    ll reprx = find(x), repry=find(y);
    if(sz[reprx]<sz[repry])swap(reprx,repry);
    sz[reprx]+=sz[repry];
    if(D[head[repry]]<D[head[reprx]])head[reprx]=head[repry];
    repr[repry]=reprx;
    return true;
}


ll go(ll x, ll y, ll c){
    ll anc = lca(x,y);
    x = head[find(x)]; y = head[find(y)];
    while(c>0 && find(x)!=find(anc)){
        assert(pa[x].fst!=-1);
        c/=pa[x].snd;
        x=head[find(pa[x].fst)];
    }
    while(c>0 && find(y)!=find(anc)){
        assert(pa[y].fst!=-1);
        c/=pa[y].snd;
        y=head[find(pa[y].fst)];
    }
    return c;
}


int main(){FIN;
    cin>>n>>m;
    dsu_init();
    fore(i,0,n-1){
        ll x,y,c;cin>>x>>y>>c;--x;--y;
        g[x].pb({y,c});g[y].pb({x,c});
        ed.pb({x,y});
    }
    lca_init();
    fore(i,0,n){
        fore(j,0,SZ(g[i])){
            if(g[i][j].snd == 1)join(i,g[i][j].fst);
        }
    }
    pa[0]={-1,1};
    while(m--){
        ll ty;cin>>ty;
        if(ty==1){
            ll a,b,y;cin>>a>>b>>y; --a;--b;
            cout << go(a,b,y) << '\n';
        } else {
            ll p,c;cin>>p>>c;--p;
            ll x = ed[p].fst, y = ed[p].snd;
            if(c==1){
                join(x,y);
            } else {
                if(pa[x].fst==y){
                    pa[x].snd=c;
                } else {
                    pa[y].snd=c;
                }
            }
        }
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/