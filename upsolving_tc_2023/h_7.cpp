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
const ll NMAX = 1e5+10;
const ll INF = 1e9+10;


#define oper(a,b) min(a,b)
#define NEUT INF
struct STree { // persistent segment tree for min over integers
	vector<int> st, L, R; int n,sz,rt;
	STree(int n): st(1,NEUT),L(1,0),R(1,0),n(n),rt(0),sz(1){}
	int new_node(int v, int l=0, int r=0){
		int ks=SZ(st);
		st.pb(v);L.pb(l);R.pb(r);
		return ks;
	}
	int init(int s, int e, int *a){ // not necessary in most cases
		if(s+1==e)return new_node(a[s]);
		int m=(s+e)/2,l=init(s,m,a),r=init(m,e,a);
		return new_node(oper(st[l],st[r]),l,r);
	}
	int upd(int k, int s, int e, int p, int v){
		int ks=new_node(st[k],L[k],R[k]);
		if(s+1==e){st[ks]=v;return ks;}
		int m=(s+e)/2,ps;
		if(p<m)ps=upd(L[ks],s,m,p,v),L[ks]=ps;
		else ps=upd(R[ks],m,e,p,v),R[ks]=ps;
		st[ks]=oper(st[L[ks]],st[R[ks]]);
		return ks;
	}
	int query(int k, int s, int e, int a, int b){
		if(e<=a||b<=s)return NEUT;
		if(a<=s&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(L[k],s,m,a,b),query(R[k],m,e,a,b));
	}
	int init(int *a){return init(0,n,a);}
	int upd(int k, int p, int v){return rt=upd(k,0,n,p,v);}
	int upd(int p, int v){return upd(rt,p,v);} // update on last root
	int query(int k,int a, int b){return query(k,0,n,a,b);};
}; // usage: STree rmq(n);root=rmq.init(x);new_root=rmq.upd(root,i,v);rmq.query(root,s,e);

ll roots[NMAX], a[NMAX], vis[NMAX], dis[NMAX];
pair<ll,ll> times[NMAX];
ll act_t;
vector<ll> g[NMAX];


void dfs(ll x, STree &st){
    vis[x]=1;times[x].fst=act_t;
    // if(roots[dis[x]]==-1)roots[dis[x]]=st.upd(times[x].fst,a[x]);
    // else {
    //     // cout << x << " "<< roots[dis[x]] << " " << times[x].fst << "\n";
    //     st.upd(roots[dis[x]],times[x].fst,a[x]);
    // }
    ++act_t;
    fore(i,0,SZ(g[x])){
        if(vis[g[x][i]])continue;
        dis[g[x][i]]=dis[x]+1;
        dfs(g[x][i],st);
    }
    times[x].snd=act_t;
}

void bfs(ll x, STree &st){
    queue<ll> q;q.push(x);
    vis[x]=1;
    while(SZ(q)){
        auto cv = q.front();q.pop();
        if(roots[dis[cv]]==-1)roots[dis[cv]]=st.upd(times[cv].fst,a[cv]);
        else roots[dis[cv]]=st.upd(roots[dis[cv]],times[cv].fst,a[cv]);
        fore(i,0,SZ(g[cv])){
            if(vis[g[cv][i]])continue;
            vis[g[cv][i]]=1;
            q.push(g[cv][i]);
        }
    }
}


int main(){FIN;
    act_t=0;
    mset(roots,-1);
    ll n,r;cin>>n>>r;--r;
    fore(i,0,n)cin>>a[i];
    fore(i,0,n-1){
        ll x,y;cin>>x>>y;--x;--y;
        g[x].pb(y);g[y].pb(x);
    }
    STree st(n);
    dis[r]=0;
    dfs(r,st);
    mset(vis,0);
    bfs(r,st);
    ll max_d = 0;
    fore(i,0,n)max_d = max(max_d, dis[i]);
    // fore(j,0,max_d+1){
    //     fore(i,0,n){
    //         cout << st.query(roots[j],i,i+1) << " ";
    //     }
    //     cout << "\n";
    // }
    ll q;cin>>q;
    ll ans = 0;
    while(q--){
        ll pi,qi;cin>>pi>>qi;
        ll x = (pi+ans)%n, k = (qi+ans)%n;
        // if(x==0)x=n-1;
        // else --x;
        // cout << x << " " << k << "\n";
        ans = st.query(roots[min(max_d,dis[x]+k)],times[x].fst,times[x].snd);
        cout << ans << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/