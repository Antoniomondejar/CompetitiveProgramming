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
const ll MOD = 1e9+7;


#define oper(a,b) a+b
#define NEUT 0
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
		if(s+1==e){st[ks]+=v;return ks;}
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

int main(){FIN;
	ll y,n; cin>>y>>n;
	vector<ll> x_is(y);
	fore(i,0,y)cin>>x_is[i];
	vector<vector<vector<ll>>> que(y);
	fore(i,0,n){
		ll a,p,f;cin>>a>>p>>f;--a;
		que[a].pb({p,f,i});
	}
	vector<ll> ans(n);
	vector<ll> roots;
	STree st(NMAX);
	for(int i = y-1; i>=0; --i){
		for(auto j:que[i]){
			if(j[1]==0 || j[0]<=x_is[i]){
				ans[j[2]]=0;
				continue;
			}
			if(j[1]==SZ(roots)){
				ans[j[2]]=st.query(roots.back(),j[0],NMAX);
			} else {
				ans[j[2]]=st.query(roots.back(),j[0],NMAX)-st.query(roots[SZ(roots)-1-j[1]],j[0],NMAX);
			}
		}
		roots.pb(st.upd(x_is[i],1));
	}
	for(auto i:ans)cout << i << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/