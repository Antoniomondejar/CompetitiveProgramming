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
const ll NMAX = 1e3+10;
const ll MOD = 1e9+7;
ll dp[NMAX][NMAX];
ll h,w;
string grid[NMAX];
bool valid(ll x, ll y){
    return 0<=x&&x<h&&0<=y&&y<w&&grid[x][y]!='#';
}
ll addd(ll x,ll y){
    return (x+y)%MOD;
}

ll f(ll x, ll y){
    if(x==h-1 && y==w-1)return 0;
    if(dp[x][y]!=-1)return dp[x][y];
    if(!valid(x+1,y) && !valid(x,y+1)){
        dp[x][y] = -1e5;
        return -1e5;
    }
    ll ad = (x==0&&y==0);
    if(valid(x+1,y) && valid(x,y+1)){
        ll aux1 = f(x+1,y);
        ll aux2 = f(x,y+1);
        if(aux1>=0 && aux2>=0)dp[x][y] = addd(ad+1,addd(aux1,aux2));
        else if(aux1>=0)dp[x][y]=addd(aux1,ad);
        else if(aux2>=0)dp[x][y]=addd(aux2,ad);
        else dp[x][y]=-1e5;
        return dp[x][y];
    }
    if(valid(x+1,y) && f(x+1,y)>=0){
        dp[x][y]=addd(f(x+1,y),ad);
        return dp[x][y];
    }
    if(valid(x,y+1) && f(x,y+1)>=0){
        dp[x][y]=addd(f(x,y+1),ad);
        return dp[x][y];
    }
    dp[x][y]=-1e5;
    return dp[x][y];
}
int main(){FIN;
    cin>>h>>w; mset(dp,-1);
    fore(i,0,h)cin>>grid[i];
    cout << ((f(0,0)<0)?0:f(0,0)) << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/