#include <bits/stdc++.h>
#define fore(i, a, b) for (ll i = a; i < b; i++)

typedef long long ll;
using namespace std;
const ll NMAX = 2e5+10;
ll h,w,n;
#define oper max
#define NEUT -1
struct STree { // segment tree for max over integers
	vector<int> st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void init(int k, int s, int e, ll *a){
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int k, int s, int e, int p, int v){
		if(s+1==e){st[k]=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(ll *a){init(1,0,n,a);}
	void upd(int p, int v){upd(1,0,n,p,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

STree rs(NMAX);

int main(void){
    #ifdef ONLINE_JUDGE
        freopen("billboard.in","r",stdin);
        freopen("billboard.out","w",stdout);
    #endif
    cin>>h>>w>>n;
    vector<ll> w_i(n);
    fore(i,0,n)cin>>w_i[i];
    ll *ws=(ll *)calloc(NMAX,sizeof(ll));
    fore(i,0,NMAX)ws[i]=w;
    rs.init(ws);
    vector<ll> rows(n,-1);
    fore(i,0,n){
        ll ma = rs.query(0,min(h,n));
        if(ma<w_i[i])continue;
        ll l = 0; ll r = min(h,n);
        while(l+1<r){
            ll m = (l+r)/2;
            ma = rs.query(l,m);
            if(w_i[i]>ma){
                l = m;
            } else {
                r = m;
            }
        }
        rows[i]=l+1;
        rs.upd(l,ws[l]-w_i[i]);
        ws[l]-=w_i[i];
    }
    fore(i,0,n){
        cout << rows[i] << "\n";
    }
    return 0;
}