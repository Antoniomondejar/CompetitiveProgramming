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
// const ll NMAX = 2e5+10;
// const ll MOD = 1e9+7;
const ll INF=30;
string in[18];


#define oper min
#define NEUT INF
struct STree { // segment tree for min over integers
	vector<int> st;int n;
	STree(int n): st(4*n+5,0), n(n) {}
	void init(int k, int s, int e, int *a){
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int k, int s, int e, int p, int v){
		if(s+1==e){
            if(st[k]>=NEUT && v==1)st[k]=1;
            else st[k]+=v;
            if(st[k]==0)st[k]=NEUT;
            return;
        }
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
	void init(int *a){init(1,0,n,a);}
	void upd(int p, int v){upd(1,0,n,p,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

int main(){
    ll n,k;cin>>n>>k;--k;
    map<char,ll> cam; cam['A']=1;cam['D']=10;cam['Q']=11;cam['J']=12;
    cam['K']=13; vector<ll> order; set<char> alr;
    fore(i,0,n){
        cin>>in[i];
        fore(j,0,4){
            if(alr.count(in[i][j]))continue;
            else {
                alr.insert(in[i][j]);
                if(cam.count(in[i][j])){
                    order.pb(cam[in[i][j]]);
                } else {
                    order.pb(in[i][j]-'0');
                }
            }
        }
    }
    sort(ALL(order));
    vector<STree> sts;
    fore(i,0,n){
        sts.pb(STree(n));
        fore(j,0,4){
            if(cam.count(in[i][j])){
                ll pos = lower_bound(ALL(order),cam[in[i][j]])-order.begin();
                sts[i].upd(pos,1);
            } else {
                ll pos = lower_bound(ALL(order),in[i][j]-'0')-order.begin();
                sts[i].upd(pos,1);
            }
        }
        fore(j,0,n){
            if(sts[i].query(j,j+1)==0)sts[i].upd(j,INF);
        }
        if(sts[i].query(0,n)==4 && i!=k){
            cout << i+1 << "\n";return 0;
        }
    }
    vector<ll> cant(n,4);
    ll turn = k, wc = k;bool puede = false; ll winner = 100; bool hay = false;
    while(1){
        // fore(j,0,n){
        //     fore(i,0,4)cout << sts[j].query(i,i+1) << " ";
        //     cout << "\n";
        // }
        if(wc==turn && puede){
            wc = (turn+1)%n;
            puede = false;
            if(sts[turn].query(0,n)==4 && cant[turn]==4){winner=turn+1;break;}
            turn = (turn+1)%n;
            continue;
        }
        if(wc==turn && !puede)puede=true;
        ll mini = sts[turn].query(0,n);
        ll l = 10;
        fore(i,0,n)if(sts[turn].query(i,i+1)==mini){l=i;break;}
        sts[turn].upd(l,-1);
        ll next = (turn+1)%n;
        sts[next].upd(l,1);
        --cant[turn];++cant[next];
        if(sts[turn].query(0,n)==4 && wc!=turn && cant[turn]==4) {winner=turn+1;hay=true;}
        // if(sts[next].query(0,n)==4 && wc!=next && cant[next]==4) {winner=min(winner,next+1);hay=true;}
        if(hay)break;
        turn = next;
    }
    cout << winner << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/