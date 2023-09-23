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
const ll NMAX = 3e5+10;
const ll MOD = 1e9+7;

ll h_i[NMAX];
ll vis[NMAX];
vector<ll> g[NMAX];

void dfs(ll x, ll h){
    vis[x]=1;
    if(h==0)return;
    for(auto i:g[x]){
        if(vis[i])continue;
        dfs(i,max(h-1,h_i[i]));
    }
    return;
}

int main(){FIN;
    ll n,m;cin>>n>>m;
    fore(i,1,n){
        ll p;cin>>p;--p;
        g[p].pb(i);
    }
    fore(i,0,m){
        ll x,y;cin>>x>>y;--x;
        h_i[x]=max(h_i[x],y);
    }
    fore(i,0,n){
        if(!vis[i] && h_i[i]>0){
            dfs(i,h_i[i]);
        }
    }
    ll count = 0;
    fore(i,0,n){
        count += vis[i];
    }
    cout << count << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/