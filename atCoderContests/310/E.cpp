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

ll dp[NMAX][2];
ll n;
ll a[NMAX];


ll f(ll x, ll ant){
    if(x==n)return 0;
    ll &res = dp[x][ant];
    if(res!=-1)return res;
    res = !(a[x]&&ant)+f(x+1,!(a[x]&&ant));
    return res;
}

int main(){FIN;
    mset(dp,-1);
    cin>>n;
    string s;cin>>s;
    fore(i,0,n)a[i]=s[i]-'0';
    // fore(i,0,n)cout << a[i] <<
    ll res = 0;
    fore(i,0,n){
        res += f(i+1,a[i])+a[i];
    }
    cout << res << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/