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
const ll MAXN = 2e3+10;

pair<ll,ll> ci[MAXN];
ll ks[MAXN];

ll uf[MAXN];
void uf_init(){memset(uf,-1,sizeof(uf));}
ll uf_find(ll x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(ll x, ll y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
vector<pair<ll,pair<ll,ll> > > es; // edges (cost,(u,v))
vector<pair<ll,ll>> con; vector<ll> ps;
ll kruskal(){  // assumes graph is connected
	sort(es.begin(),es.end());uf_init();
	ll r=0;
	fore(i,0,es.size()){
		ll x=es[i].snd.fst,y=es[i].snd.snd;
		if(uf_join(x,y)){
            r+=es[i].fst; // (x,y,c) belongs to mst
            if(x==0)ps.pb(y);
            else if(y==0)ps.pb(x);
            else con.pb({x,y});
        }
    }
	return r; // total cost
}



int main(){FIN;
    ll n; cin >> n;
    fore(i,1,n+1)cin >> ci[i].fst >> ci[i].snd;
    fore(i,1,n+1){
        ll inp; cin >> inp;
        es.pb({inp,{0,i}}); // 0 es el nodo ficticio que representa conectarle una fuente de energia a la ciudad i.
    }
    fore(i,1,n+1)cin >> ks[i];
    fore(i,1,n+1)fore(j,i+1,n+1){
        ll cost = (abs(ci[i].fst-ci[j].fst)+abs(ci[i].snd-ci[j].snd))*(ks[i]+ks[j]);
        es.pb({cost,{i,j}});
    }
    ll res = kruskal();
    cout << res << "\n" << SZ(ps) << "\n";
    for(auto g : ps) cout << g << " ";
    cout << "\n" << SZ(con) << "\n";
    for(auto p : con) cout << p.fst << " " << p.snd << "\n";
    return 0;
}