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

vector<ll> g[NMAX], g_inv[NMAX];
ll a[NMAX];ll pa[NMAX];

int n;
vector<int> tsort(){  // lexicographically smallest topological sort
	vector<int> r;priority_queue<int> q;
	vector<int> d(2*n,0);
	fore(i,0,n)fore(j,0,g[i].size())d[g[i][j]]++;
	fore(i,0,n)if(!d[i])q.push(-i);
	while(!q.empty()){
		int x=-q.top();q.pop();r.pb(x);
		fore(i,0,g[x].size()){
			d[g[x][i]]--;
			if(!d[g[x][i]])q.push(-g[x][i]);
		}
	}
	return r;  // if not DAG it will have less than n elements
}

ll vis[NMAX];
pair<ll,ll> ans[NMAX];


pair<ll,ll> dfs(ll x){
    vis[x]=1;
    pair<ll,ll> res = ans[x];
    fore(i,0,SZ(g[x])){
        if(vis[g[x][i]])continue;
        if(ans[g[x][i]].fst<ans[x].fst || (ans[x].fst==ans[g[x][i]].fst && ans[x].snd>ans[g[x][i]].snd)){
            ans[g[x][i]].fst++;
            res = max(res,dfs(g[x][i]));
        }
    }
    return res;
}


int main(){FIN;
    ll t;cin>>t;
    while(t--){
        ll m,k;cin>>n>>m>>k;
        fore(i,0,n)g[i].clear(),g_inv[i].clear(),pa[i]=i, vis[i]=0;
        fore(i,0,n)cin>>a[i];
        vector<ll> ind(n);
        fore(i,0,m){
            ll x,y;cin>>x>>y;--x;--y;
            g[x].pb(y);
            ind[y]++;
            g_inv[y].pb(x);
        }
        // if(n==1){cout << "0\n";continue;}
        vector<pair<ll,ll>> pas;
        fore(i,0,n){
            if(ind[i]==0)pas.pb({a[i],i});
        }
        sort(ALL(pas));
        vector<int> t = tsort();
        fore(i,0,n){
            // cout << pa[i] << " ";
            pair<ll,ll> maxi = {0,a[t[i]]};
            fore(j,0,SZ(g_inv[t[i]])){
                maxi = max(maxi, ans[g_inv[t[i]][j]]);
            }
            if(maxi.snd>a[t[i]]){
                ans[t[i]]={maxi.fst+1,a[t[i]]};
            } else {
                ans[t[i]]={maxi.fst,a[t[i]]};
            }
        }
        // cout << "\n";
        pair<ll,ll> maxi = {0,0};
        fore(i,0,n){
            maxi=max(maxi,ans[i]);
        }
        ll res = maxi.fst*k+maxi.snd-pas[0].fst;
        fore(i,0,SZ(pas)-1){
            ans[pas[i].snd].fst++;
            maxi = max(maxi,dfs(pas[i].snd));
            // cout << maxi.fst << " " << maxi.snd << "\n";
            res = min(res,maxi.fst*k+maxi.snd-pas[i+1].fst);
        }
        cout << res << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/