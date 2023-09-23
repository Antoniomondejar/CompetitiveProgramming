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
#define bint __int128
using namespace std;
typedef long long ll;
const ll NMAX = 2e5+10;
const bint MOD = 212345678987654321LL;

ll add(ll x, ll y){
	bint res = bint(x)+bint(y);
    return(res%MOD+MOD)%MOD;
}
 
ll mul(ll x, ll y){
	bint res = bint(x)*bint(y);
    return res%MOD;
}
 
struct Hash {
	ll MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
	vector<ll> h,pi;
	Hash(string& s){
		assert(mul(P,PI)==1);
		h.resize(s.size()+1);pi.resize(s.size()+1);
		h[0]=0;pi[0]=1;
		bint p=1;
		fore(i,1,s.size()+1){
			h[i]=add(h[i-1],mul(p,s[i-1]));
			pi[i]=mul(pi[i-1],PI);
			p=mul(p,P);
		}
	}
	ll get(int s, int e){
		return mul(add(h[e],h[s]),pi[s]);
	}
};
 

struct STree { // example: range sum with range addition
	vector<ll> st,lazy;int n;
	STree(int n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
	void init(int k, int s, int e, vector<ll> &a){
		lazy[k]=0;  // lazy neutral element
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=add(st[2*k],st[2*k+1]); // operation
	}
	void push(int k, int s, int e){
		if(!lazy[k])return; // if neutral, nothing to do
		st[k]=add(st[k],mul((e-s),lazy[k])); // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]=add(lazy[2*k],lazy[k]);
			lazy[2*k+1]=add(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=0; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, ll v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]=add(lazy[k],v); // accumulate lazy
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=add(st[2*k],st[2*k+1]); // operation
	}
	ll query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return 0; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return add(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b)); // operation
	}
	void init(vector<ll> &a){init(1,0,n,a);}
	void upd(int a, int b, ll v){upd(1,0,n,a,b,v);}
	ll query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);
 
 
 
int main(){FIN;
    ll n,m; cin >> n >> m;
    string s; cin >> s;
    string s_r = s; reverse(ALL(s_r));
    Hash ha(s); Hash ha_r(s_r);
    STree st(n+1), st_r(n+1);
    st.init(ha.h);
    st_r.init(ha_r.h);
	ll h_P[n]; h_P[0]=1; fore(i,1,n)h_P[i]=mul(h_P[i-1],ha.P);
	ll k,b,ad,a,h_b,h_a,ha1,ha2;
    char x;
	while(m--){
        ll ty; cin >> ty;
        if(ty==1){
            cin >> k >> x; --k;
            // original
            b = h_P[k];
            ad = add(mul(b,x),-mul(b,s[k]));
            st.upd(k+1,n+1,ad);
            // reverse
            b = h_P[n-k-1];
            ad = add(mul(b,x),-mul(b,s[k]));
            st_r.upd(n-k,n+1,ad);
            s[k]=x;
        } else {
            cin >> a >> b; --a;
            // Original
			h_b = st.query(b,b+1), h_a = st.query(a,a+1);
            ha1 = (((h_b-h_a+MOD)%MOD)*ha.pi[a])%MOD;
            // Reverse
			h_b = st_r.query(n-a,n-a+1); h_a = st_r.query(n-b,n-b+1);
            ha2 = (((h_b-h_a+MOD)%MOD)*ha.pi[n-b])%MOD;
            if(ha1==ha2)cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
 
/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/
