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

vector<ll> g[NMAX];
vector<ll> ans;
ll vis[NMAX];


vector<int> g_p[NMAX];
ll n;
vector<int> tsort(){  // lexicographically smallest topological sort
	vector<int> r;priority_queue<int> q;
	vector<int> d(2*n,0);
	fore(i,0,n)fore(j,0,g_p[i].size())d[g_p[i][j]]++;
	fore(i,0,n)if(!d[i])q.push(-i);
	while(!q.empty()){
		int x=-q.top();q.pop();r.pb(x);
		fore(i,0,g_p[x].size()){
			d[g_p[x][i]]--;
			if(!d[g_p[x][i]])q.push(-g_p[x][i]);
		}
	}
	return r;  // if not DAG it will have less than n elements
}

void bfs(ll x){
    queue<ll> q;q.push(x);
    vis[x]=1;
    while(SZ(q)){
        auto cv = q.front();q.pop();
        fore(i,0,SZ(g[cv])){
            if(vis[g[cv][i]])continue;
            vis[g[cv][i]]=1;
            q.push(g[cv][i]);
        }
    }
}


int main(){FIN;
    cin>>n;
    fore(i,0,n){
        ll ci;cin>>ci;
        fore(j,0,ci){
            ll x;cin>>x;--x;
            g[i].pb(x);
            g_p[x].pb(i);
        }
    }
    bfs(0);
    vector<int> t = tsort();
    fore(i,0,n){
        if(vis[t[i]]&&t[i]!=0) cout << t[i]+1 << " ";
    }
    cout << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/
