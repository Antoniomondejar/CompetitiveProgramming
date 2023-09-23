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
const ll NMAX = 2e5+10;
const ll MOD = 1e9+7;

#define oper(a,b) (a+b)
#define NEUT 0
struct STree { // persistent segment tree for min over integers
	vector<int> st, L, R; int n,sz,rt;
	STree(int n): st(1,NEUT),L(1,0),R(1,0),n(n),rt(0),sz(1){}
	int new_node(int v, int l=0, int r=0){
		int ks=SZ(st);
		st.pb(v);L.pb(l);R.pb(r);
		return ks;
	}
	int init(int s, int e, vector<int> &a){ // not necessary in most cases
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
	int init(vector<int> &a){return init(0,n,a);}
	int upd(int k, int p, int v){return rt=upd(k,0,n,p,v);}
	int upd(int p, int v){return upd(rt,p,v);} // update on last root
	int query(int k,int a, int b){return query(k,0,n,a,b);};
}; // usage: STree rmq(n);root=rmq.init(x);new_root=rmq.upd(root,i,v);rmq.query(root,s,e);


int main(){FIN; 
    ll t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vector<pair<int,int>> seg(m);
        fore(i,0,m) cin>>seg[i].fst>>seg[i].snd;
        vector<int> a(n);
        STree st(n);
        st.init(a); vector<int> roots;
        int q, q_copy; cin >> q; q_copy = q;
        while(q--){
            ll x; cin >> x; --x;
            roots.pb(st.upd(x,1));
        }
        ll res = n;
        fore(i,0,m){
            ll ext_i = seg[i].fst, ext_d = seg[i].snd; --ext_i;
            ll l = 0, r = q_copy-1; ll sum_d = (ext_d-ext_i)/2 + 1;
            if(st.query(roots.back(),ext_i,ext_d)<sum_d)continue;
            while(l<=r){
                ll m = (l+r)/2;
                if(st.query(roots[m],ext_i,ext_d)>=sum_d){
                    r = m-1;
                } else {
                    l = m+1;
                }
            }
            // cout << ext_i << " " << ext_d << " " << " " << sum_d << " " << l << "\n";
            res = min(res,l);
        }
        if(res==n)cout << "-1\n";
        else cout << res+1 << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/