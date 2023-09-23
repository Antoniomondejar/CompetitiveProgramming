#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define str string
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll NMAX = 5e4+10;
const ll MOD = 1e9+7;
const ll INF = 1e15;

ll n,t;
ll di[NMAX], pr[NMAX];

#define oper min
#define NEUT INF
struct STree { // segment tree for min over integers
	vector<ll> st;ll n;
	STree(ll n): st(4*n+5,NEUT), n(n) {}
	void init(ll k, ll s, ll e, vector<ll> &a){
		if(s+1==e){st[k]=a[s];return;}
		ll m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(ll k, ll s, ll e, ll p, ll v){
		if(s+1==e){st[k]=v;return;}
		ll m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(vector<ll> &a){init(1,0,n,a);}
	void upd(ll p, ll v){upd(1,0,n,p,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

bool can(ll m){
    ll r=-1;
    fore(i,0,n-1){
        if(pr[i]<=m)r=i+1;
    }
    if(r==-1)return false;
    STree st(n);
    st.upd(n-1,n-1);
    for(int i=n-2;i>=0;--i){
        ll res = st.query(i+1,min(n,i+r+1))-i;
        if(i>0) st.upd(i,res+di[i]+i);
        else st.upd(0,res);
    }
    // fore(i,0,n){
    //     cout << st.query(i,i+1) << " ";
    // }
    // cout << "\n";
    return st.query(0,1)<=t;
}

int main(){FIN;
#ifdef ONLINE_JUDGE
  freopen("journey.in", "r", stdin);
  freopen("journey.out", "w", stdout);
#endif
    cin>>n>>t;
    fore(i,0,n-1)cin>>pr[i];
    fore(i,1,n-1)cin>>di[i];
    ll l = 1, r=1e8;
    while(l<=r){
        ll m=(l+r)/2;
        if(can(m)){
            r = m-1;
        } else {
            l = m+1;
        }
    }
    assert(can(l));
    cout << l << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/