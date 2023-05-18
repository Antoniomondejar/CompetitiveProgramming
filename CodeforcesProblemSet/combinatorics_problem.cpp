#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define str string
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const ll MAXN = 1e7+10;
const ll MAXK = 6;
ll mul(ll x,ll y){
    return (x*y)%MOD;
}
inline ll add(ll x, ll y){
	x+=y;
	if(x>=MOD)x-=MOD;
	return x;
}
ll dp[MAXN][MAXK];
int main(){
    ll n,a1,x,y,m,k; cin>>n>>a1>>x>>y>>m>>k;
    vector<ll> a(n); a[0] = a1;
    fore(i,1,n)a[i] = (a[i-1]*x+y)%m;
    fore(j,0,k+1){
        fore(i,0,n){
            if(j==0){
                if(i==0)dp[i][j]=a[0];
                else dp[i][j] = add(a[i],dp[i-1][j]);
            } else if (j==1) {
                if(i==0)dp[i][j]=a[0];
                else dp[i][j]=add(add(dp[i-1][j-1],dp[i-1][j]),a[i]);
            } else {
                if(i==0)dp[i][j]=0;
                else dp[i][j]=add(dp[i-1][j-1],dp[i-1][j]);
            }
        }
    }
    ll res = dp[0][k]*1;
    fore(i,1,n){
        res ^= dp[i][k]*(i+1);
    }
    cout << res << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/