#include <bits/stdc++.h>
#define pb push_back
#define fore(i,a,b) for(int i=a, ggdem=b; i<ggdem; ++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll NMAX = 2e5+10;

ll vis[NMAX];
ll col[NMAX];
vector<ll> g[NMAX];
ll n, sum_d;

ll dfs(ll x, ll l_c){
    vis[x]=1; col[x]=(l_c+1)%2;
    ll sum = 1;
    fore(i,0,SZ(g[x])){
        if(vis[g[x][i]])continue;
        sum += dfs(g[x][i],col[x]);
    }
    sum_d += (n-sum)*sum;
    return sum;
}


int main(void){FIN;
    sum_d = 0; cin >> n;   
    fore(i,0,n-1){
        ll x,y; cin >> x >> y; --x;--y;
        g[x].pb(y);g[y].pb(x);
    }
    dfs(0,1); ll c0 = 0, c1 = 0;
    fore(i,0,n){
        if(col[i]==0)c0++;
        else c1++;
    }
    cout << (sum_d+(c1*c0))/2 << "\n";
    return 0;
}