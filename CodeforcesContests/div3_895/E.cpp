#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define str string
#define fore(i,a,b) for(int i=a,thxMat=b;i<thxMat;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll NMAX = 2e5+10;
const ll MOD = 1e9+7;

#define oper(a,b) (a^b)
#define NEUT 0
struct STree { // segment tree for min over integers
	vector<int> st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void init(int k, int s, int e, vector<int> &a){
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
	void init(vector<int> &a){init(1,0,n,a);}
	void upd(int p, int v){upd(1,0,n,p,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);



int main(){FIN;
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<int> a(n);
        fore(i,0,n)cin>>a[i];
        string bi;cin>>bi;
        ll res_0 = 0, res_1=0;
        fore(i,0,n){
            if(bi[i]=='0')res_0 ^= a[i];
            else res_1 ^=a[i];
        }
        STree st(n); st.init(a);
        ll q;cin>>q;
        while(q--){
            ll ty;cin>>ty;
            if(ty==1){
                ll l,r;cin>>l>>r;--l;
                ll que = st.query(l,r);
                res_0 ^= que;
                res_1^=que;
            } else {
                ll g;cin>>g;
                if(g==0) cout << res_0 << " ";
                else cout << res_1 << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/