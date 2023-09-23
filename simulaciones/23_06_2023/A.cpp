#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v)sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<ll> vll;
const ll NMAX = 2e5+10;

vector<pair<ll,ll>> g[NMAX];
vector<ll> g_d[NMAX];
ll co[NMAX]; ll vis[NMAX]; // 0 es left, 1 es right
ll n;
void dfs(ll x, ll l_c){
    vis[x]=1; co[x]=(l_c+1)%2;
    for(auto i:g[x]){
        if(vis[i.fst])continue;
        dfs(i.fst,co[x]);
    }
}

bool bipartito(){
    bool p = true;
    fore(i,0,n){
        ll col = co[i];
        for(auto j:g[i]){
            if(co[j.fst]==col){p=false;break;}
        }
        if(!p)break;
    }
    return p;
}

vector<int> tsort(){  // lexicographically smallest topological sort
	vector<int> r;priority_queue<int> q;
	vector<int> d(2*n,0);
	fore(i,0,n)fore(j,0,g_d[i].size())d[g_d[i][j]]++;
	fore(i,0,n)if(!d[i])q.push(-i);
	while(!q.empty()){
		int x=-q.top();q.pop();r.pb(x);
		fore(i,0,g_d[x].size()){
			d[g_d[x][i]]--;
			if(!d[g_d[x][i]])q.push(-g_d[x][i]);
		}
	}
	return r;  // if not DAG it will have less than n elements
}

int main(){
    ll m; cin >> n >> m;
    fore(i,0,m){
        ll ty,x,y; cin >> ty >> x >> y; --x;--y;
        g[x].pb({y,ty});g[y].pb({x,ty});
    }
    fore(i,0,n){
        if(!vis[i]){
            dfs(i,1);
        }
    }
    if(!bipartito()){cout << "NO\n"; return 0;}
    vector<ll> visi(n);
    fore(i,0,n){
        visi[i]=1;
        for(auto j:g[i]){
            if(visi[j.fst])continue;
            if(j.snd==1){
                if(co[i]==0)g_d[i].pb(j.fst);
                else g_d[j.fst].pb(i);
            } else {
                if(co[i]==0)g_d[j.fst].pb(i);
                else g_d[i].pb(j.fst);
            }
        }
    }
    vector<int> tos = tsort();
    if(SZ(tos)<n){cout << "NO\n";return 0;}
    // for(auto i:tos)cout << i << " ";
    // cout << "\n";
    cout << "YES\n"; vector<int> plac(n+10,-1);plac[tos[0]]=0;
    fore(i,1,n)plac[tos[i]]=plac[tos[i-1]]+1;
    fore(i,0,n){
        cout << (co[i]==0?"L ":"R ") << plac[i] << "\n";
    }
    return 0;
}