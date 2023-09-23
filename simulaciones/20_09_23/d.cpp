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
//typedef pair<ll,ll> ii
//typedef vector<ll> vii
const ll NMAX = 1e4+5;


vector<int> g[NMAX];
int n,m;
int mat[NMAX]; bool vis[NMAX];
int match(int x){
	if(vis[x])return 0;
	vis[x]=true;
	for(int y:g[x])if(mat[y]<0||match(mat[y])){mat[y]=x;return 1;}
	return 0;
}

vector<pair<ll,ll>> max_matching(){
	vector<pair<ll,ll>> r;
	memset(mat,-1,sizeof(mat));
	fore(i,0,n)memset(vis,false,sizeof(vis)),match(i);
	fore(i,0,n)if(mat[i]>=0)r.pb({mat[i],i});
	return r;
}

int main(){FIN;
	cin>>n>>m;
	fore(i,0,m){
		ll x,y;cin>>x>>y;
		g[y].pb(x);
	}
	vector<pair<ll,ll>> mach=max_matching();
	if(SZ(mach)==n){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}