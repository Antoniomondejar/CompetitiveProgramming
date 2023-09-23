#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define fore(i,a,b) for(int i=a,gmat=b;i<gmat;++i)
#define FIN ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vii;
typedef pair<ll,ll> ii;


#define bint __int128
struct Hash {
	bint MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
	vector<bint> h,pi;
	Hash(string& s){
		assert((P*PI)%MOD==1);
		h.resize(s.size()+1);pi.resize(s.size()+1);
		h[0]=0;pi[0]=1;
		bint p=1;
		fore(i,1,s.size()+1){
			h[i]=(h[i-1]+p*s[i-1])%MOD;
			pi[i]=(pi[i-1]*PI)%MOD;
			p=(p*P)%MOD;
		}
	}
	ll get(int s, int e){
		return (((h[e]-h[s]+MOD)%MOD)*pi[s])%MOD;
	}
};


ll res;


vector<int> kmppre(vector<ll>& t){ // r[i]: longest border of t[0,i)
	vector<int> r(t.size()+1);r[0]=-1;
	int j=-1;
	fore(i,0,t.size()){
		while(j>=0&&t[i]!=t[j])j=r[j];
		r[i+1]=++j;
	}
	return r;
}
void kmp(vector<ll>& s, vector<ll>& t){ // find t in s
	int j=0;vector<int> b=kmppre(t);
	fore(i,0,s.size()){
		while(j>=0&&s[i]!=t[j])j=b[j];
		if(++j==t.size())++res,j=b[j];
	}
}


int main(){FIN;
	ll h_p,w_p,h_m,w_m;
	cin>>h_p>>w_p>>h_m>>w_m;

	vector<string> chiq(h_p);
	vector<string> grand(h_m);	
	
	fore(i,0,h_p)cin>>chiq[i];
	fore(i,0,h_m)cin>>grand[i];
	
	vector<ll> gri_chi;

	fore(i,0,h_p){
		Hash h(chiq[i]);
		gri_chi.pb(h.get(0,SZ(chiq[i])));
		gri_chi.pb(-1);
	}

	vector<vector<ll>> col_gra(w_m-w_p+1);
	fore(j,0,h_m){
		Hash h(grand[j]);
		fore(i,0,w_m-w_p+1){
			col_gra[i].pb(h.get(i,i+w_p));
			col_gra[i].pb(-1);
		}
	}

	res = 0;

	fore(i,0,w_m-w_p+1){
		kmp(col_gra[i],gri_chi);
	}	

	cout << res << "\n";
	return 0;
}