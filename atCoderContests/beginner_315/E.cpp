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

void dfs(ll x){
    vis[x]=1;
    fore(i,0,SZ(g[x])){
        if(vis[g[x][i]])continue;
        dfs(g[x][i]);
    }
    ans.pb(x);
}


int main(){FIN;
    ll n;cin>>n;
    fore(i,0,n){
        ll ci;cin>>ci;
        fore(j,0,ci){
            ll x;cin>>x;--x;
            g[i].pb(x);
        }
    }
    dfs(0);
    ans.pop_back();
    for(auto i:ans) cout << i+1 << " ";
    cout << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/