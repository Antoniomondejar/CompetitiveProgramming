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
const ll NMAX = 1e6+10;
const ll MOD = 1e9+7;

bool dp[105][NMAX];
bool vis[105][NMAX];
ll s[110];
ll w,fi,n;

bool f(ll x, ll sum){
    if(sum<0)return false;
    if(x==n && sum!=0)return false;
    if(sum==0)return true;
    bool &res = dp[x][sum];
    if(vis[x][sum])return res;
    vis[x][sum]=1;
    res = f(x+1,sum-s[x])||f(x+1,sum);
    return res;
}


bool can(ll me){
    ll sum = 0;
    ll w_n = me*w, f_n=me*fi;
    fore(i,0,n)sum+=s[i];
    if(sum>w_n+f_n)return false;
    if(sum<=w_n||sum<=f_n)return true;
    fore(i,1,sum+1){
        if(f(0,i)){
            if(i<=f_n && sum-i<=w_n)return true;
            if(i<=w_n && sum-i<=f_n)return true;
        }
    }
    return false;
}


int main(){FIN;
    ll t;cin>>t;
    while(t--){
        cin>>w>>fi>>n;
        fore(i,0,n)fore(j,0,1e6+5)vis[i][j]=0;
        fore(i,0,n)cin>>s[i];
        ll l=1, r=1e6+5;
        while(l<=r){
            ll me =(l+r)/2;
            if(can(me))r=me-1;
            else l =me+1;
        }
        cout << l << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/