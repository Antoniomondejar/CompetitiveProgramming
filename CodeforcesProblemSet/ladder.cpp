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

struct Node{
    ll pre_or_c;
    ll suf_or_d;
    ll first;
    ll last;
    ll largo;
};
#define NEUT Node({-1,-1,-1,-1,-1})

Node operacion(Node a, Node b){
    if(a.pre_or_c==NEUT.pre_or_c) return b;
    if(b.pre_or_c==NEUT.pre_or_c) return a;
    if(a.last>b.first){
        ll suf_ma = b.suf_or_d;
        if(b.suf_or_d == b.largo) suf_ma += a.suf_or_d;
        return Node({a.pre_or_c,suf_ma,a.first,b.last,a.largo+b.largo});
    } else if(b.first>a.last){
        ll pre_ma = a.pre_or_c;
        if(a.pre_or_c == a.largo) pre_ma += b.pre_or_c;
        return Node({pre_ma,b.suf_or_d,a.first,b.last,a.largo+b.largo});
    } else {
        ll pre_ma = a.pre_or_c;
        if(a.pre_or_c == a.largo) pre_ma += b.pre_or_c;
        ll suf_ma = b.suf_or_d;
        if(b.suf_or_d == b.largo) suf_ma += a.suf_or_d;
        return Node({pre_ma,suf_ma,a.first,b.last,a.largo+b.largo});
    }
}

#define oper operacion

struct STree { // segment tree for min over integers
	vector<Node> st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void init(int k, int s, int e, vector<Node> &a){
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int k, int s, int e, int p, Node v){
		if(s+1==e){st[k]=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	Node query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(vector<Node> &a){init(1,0,n,a);}
	void upd(int p, Node v){upd(1,0,n,p,v);}
	Node query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

int main(){FIN;
    ll n,m; cin >> n >> m;
    vector<Node> a(n);
    fore(i,0,n){
        ll inp; cin >> inp;
        a[i]={1,1,inp,inp,1};
    }
    STree st(n); st.init(a);
    while(m--){
        ll l,r; cin >> l >> r;--l;
        Node que = st.query(l,r);
        if(que.pre_or_c+que.suf_or_d >= (r-l)){
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/