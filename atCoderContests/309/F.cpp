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

#define oper max
#define NEUT -1
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

map<int,int> l_p;

int main(){FIN;
    int n;cin>>n;
    vector<vector<int>> a(n);
    fore(i,0,n){
        int x,y,z;cin>>x>>y>>z;
        a[i].pb(x);a[i].pb(y);a[i].pb(z);
        sort(ALL(a[i]));
    }
    sort(ALL(a));
    vector<pair<int,int>> s;
    vector<int> t;
    fore(i,0,n){
        // cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << "\n";
        l_p[a[i][0]]=i;
        s.pb({a[i][1],i});
        t.pb(a[i][2]);
    }
    sort(ALL(s));
    ll i = 0;
    STree st(n); st.init(t);
    bool p = false;
    while(i<n && !p){
        queue<int> ps;ps.push(s[i].snd);
        ll cu = s[i].fst;
        st.upd(s[i].snd,NEUT);
        ++i;
        while(i<n && s[i].fst==cu){
            ps.push(s[i].snd);st.upd(s[i].snd,NEUT);
            ++i;
        }
        while(SZ(ps)){
            ll ci=ps.front();ps.pop();
            ll maxi = st.query(l_p[a[ci][0]]+1,n);
            if(maxi>a[ci][2]){p=true;break;}
        }
    }
    if(p)cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/