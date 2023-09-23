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

#define oper min
#define NEUT 8e18
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

vector<ll> a[NMAX];
int main(){FIN;
    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        fore(i,0,n)a[i].clear();
        vector<ll> c_i(n);
        fore(i,0,n)cin>>c_i[i];
        vector<ll> p(k);
        fore(i,0,k)cin>>p[i];
        // vector<vector<ll>>a(n);
        vector<ll> c_s(n);
        fore(i,0,n){
            ll m;cin>>m;
            ll sum = 0;
            fore(j,0,m){
                ll x;cin>>x;--x;
                a[x].pb(i);
                sum+=c_i[x];
            }
            c_s[i]=(sum==0?NEUT:sum);
        }
        STree st(n); st.init(c_i);
        fore(i,0,n){
            st.upd(i,min(c_i[i],c_s[i]));
        }
        fore(i,0,k){
            st.upd(p[i]-1,0);
        }
        vector<ll> ans(n,-1);
        ll cant=0;
        while(cant<n){
            // fore(i,0,n)cout << st.query(i,i+1) << " ";
            // cout << "\n";
            ll mini = st.query(0,n);
            ll l = 0; ll r=n-1;
            while(l<=r){
                ll m = (l+r)/2;
                if(st.query(l,m+1)>mini)l=m+1;
                else r=m-1;
            }
            // cout << l << "\n";
            ans[l]=st.query(l,l+1);
            fore(i,0,SZ(a[l])){
                if(ans[a[l][i]]!=-1)continue;
                ll re = ans[l]-c_i[l];
                st.upd(a[l][i],min(st.query(a[l][i],a[l][i]+1),c_s[a[l][i]]+re));
                c_s[a[l][i]]+=re;
            }
            st.upd(l,NEUT);
            ++cant;
        }
        for(auto i:ans)cout << i << " ";
        cout << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/