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

pair<ll,ll> max_pre(pair<ll,ll> a, pair<ll,ll> b){
    return {max(a.fst, a.snd+b.fst), a.snd+b.snd};
}

#define oper max_pre
#define NEUT {0,0}
struct STree { // segment tree for min over integers
	vector<pair<ll,ll>> st;ll n;
	STree(ll n): st(4*n+5,NEUT), n(n) {}
	void init(ll k, ll s, ll e, vector<pair<ll,ll>> &a){
		if(s+1==e){st[k]=a[s];return;}
		ll m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(ll k, ll s, ll e, ll p, ll v){
		if(s+1==e){st[k]={max(0LL,v),v};return;}
		ll m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	pair<ll,ll> query(ll k, ll s, ll e, ll a, ll b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(vector<pair<ll,ll>> &a){init(1,0,n,a);}
	void upd(ll p, ll v){upd(1,0,n,p,v);}
	pair<ll,ll> query(ll a, ll b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

int main(){FIN;
    ll n,q; cin >> n >> q;
    vector<pair<ll,ll>> qs(n);
    fore(i,0,n)cin>>qs[i].snd,qs[i].fst = max(0LL,qs[i].snd);
    STree st(n);
    st.init(qs);
    while(q--){
        ll ty; cin >> ty;
        if(ty==1){
            ll k,u; cin >> k >> u; --k;
            st.upd(k,u);
        } else {
            ll a,b; cin >> a >> b; --a;
            cout << st.query(a,b).fst << "\n";
        }
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/