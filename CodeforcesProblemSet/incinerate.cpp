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

struct STreeL { // example: range sum with range addition
	vector<ll> st,lazy;int n;
	STreeL(int n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
	void init(int k, int s, int e, vector<ll> &a){
		lazy[k]=0;  // lazy neutral element
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=st[2*k]+st[2*k+1]; // operation
	}
	void push(int k, int s, int e){
		if(!lazy[k])return; // if neutral, nothing to do
		st[k]+=(e-s)*lazy[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]+=lazy[k];
			lazy[2*k+1]+=lazy[k];
		}
		lazy[k]=0; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, ll v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]+=v; // accumulate lazy
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=st[2*k]+st[2*k+1]; // operation
	}
	ll query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return 0; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return query(2*k,s,m,a,b)+query(2*k+1,m,e,a,b); // operation
	}
	void init(vector<ll> &a){init(1,0,n,a);}
	void upd(int a, int b, ll v){upd(1,0,n,a,b,v);}
	ll query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);


#define oper min
#define NEUT 1e15
struct STree { // segment tree for min over integers
	vector<ll> st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void init(int k, int s, int e, vector<ll> &a){
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int k, int s, int e, int p, ll v){
		if(s+1==e){st[k]=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ll query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(vector<ll> &a){init(1,0,n,a);}
	void upd(int p, ll v){upd(1,0,n,p,v);}
	ll query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);


int main(){FIN;
    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        vector<ll> po(n),he(n);
        fore(i,0,n)cin>>he[i];
        fore(i,0,n)cin>>po[i];
        STree st(n);st.init(po);
        STreeL st_l(n);st_l.init(he);
        ll mu=0; ll l=0,r=n-1,mini=NEUT; ll it=0;
        while(mu<n && k>0){
            st_l.upd(0,n,-k);
            ++it;
            while(1){
                mini=st.query(0,n);
                // cout << mini << " " << it << "\n";
                if(mu==n)break;
                l = 0,r=n-1;
                while(l<=r){
                    ll m=(l+r)/2;
                    // cout << st.query(l,m+1) << "\n";
                    if(st.query(l,m+1)>mini)l=m+1;
                    else r=m-1;
                }
                if(st_l.query(l,l+1)>0){break;}
                else {
                    // cout << st_l.query(l,l+1) << "\n";
                    mu++;
                    st.upd(l,NEUT);
                }
            }
            if(mu==n)break;
            k-=mini;
        }
        // cout << mu << "\n";
        if(k>0)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/