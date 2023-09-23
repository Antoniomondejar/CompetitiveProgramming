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

ll dp[NMAX][4][8];
ll n;string s,mex;
ll a[NMAX];
ll f(ll x, ll cual, ll mask){
    if(cual == 3){
        ll inte = 0;
        while(mask&1){
            mask/=2;
            ++inte;
        }
        // cout << inte << "\n";
        return inte;
    }
    if(x==n)return 0;
    ll &res = dp[x][cual][mask];
    if(res != -1)return res;
    res = 0;
    if(s[x]==mex[cual]){
        ll mask_aux = mask;
        fore(i,0,a[x]){
            mask_aux/=2;
        }
        if(mask_aux%2==0){
            res = f(x+1,cual+1,mask+(1LL<<a[x]))+f(x+1,cual,mask);
        } else {
            res = f(x+1,cual+1,mask)+f(x+1,cual,mask);
        }
    } else {
        res = f(x+1,cual,mask);
    }
    // cout << x << " " << cual << " " << mask << " " << res << "\n";
    return res;
}

int main(){FIN;
    mset(dp,-1);
    mex = "MEX";
    cin>>n;
    fore(i,0,n)cin>>a[i];
    cin>>s;
    ll res = f(0,0,0);
    cout << res << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/