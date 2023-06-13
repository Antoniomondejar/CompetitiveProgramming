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
const ll NMAX = 1e5+10;
const ll INF = 1e17+7;

#define oper min
#define NEUT INF
struct STree { // segment tree for min over integers
	vector<ll> st;ll n;
	STree(ll n): st(4*n+5,NEUT), n(n) {}
	void init(ll k, ll s, ll e, ll *a){
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
	void init(ll *a){init(1,0,n,a);}
	void upd(ll p, ll v){upd(1,0,n,p,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

STree tss(NMAX);

int main(){
    ll n,p; cin >> n >> p;
    ll *ts=(ll *) calloc(NMAX,sizeof(ll));
    fore(i,0,n)cin>>ts[i];
    vector<ll> ans(n);
    tss.init(ts);
    ll time = 0;
    ll last_l = n;
    fore(i,0,n){
        ll minn = tss.query(0,last_l);
        if(minn>=time){
            minn = tss.query(0,n);
            if(minn>=time){
                ll l = 0; ll r = n;
                while(l+1<r){
                    ll m = (l+r)/2;
                    ll min_a = tss.query(l,m);
                    if(minn<min_a){
                        l = m;
                    } else {
                        r = m;
                    }
                }
                time = max(ts[l]+p,time+p);
                tss.upd(l,INF);
                ans[l] = time;
                last_l = l;
            } else {
                ll l = 0; ll r = n;
                while(l+1<r){
                    ll m = (l+r)/2;
                    ll min_a = tss.query(l,m);
                    if(time<min_a){
                        l = m;
                    } else {
                        r = m;
                    }
                }
                time+=p;
                ans[l]=time;
                tss.upd(l,INF);
                last_l = l;
            }
        } else {
            ll l = 0; ll r = last_l;
            while(l+1<r){
                ll m = (l+r)/2;
                ll min_a = tss.query(l,m);
                if(minn<min_a){
                    l = m;
                } else {
                    r = m;
                }
            }
            time+=p;
            ans[l]=time;
            tss.upd(l,INF);
            last_l = l;
        }
    }
    for(auto i:ans){
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/