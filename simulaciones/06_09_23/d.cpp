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
const ll NMAX = 1e5+10;
const ll MOD = 1e9+7;
const ll INF = 1e12;

ll dp[NMAX][15];
ll n,m,k;
vector<ll> columns[NMAX];
ll a[15][NMAX];

ll f(ll x, ll cuan){
    if(x==m)return 0;
    ll &res = dp[x][cuan];
    if(res!=-1)return res;
    cuan = min({k,cuan,m-x});
    ll acc = 0;
    res = f(x+1,cuan+(x+1<=m-k));
    fore(i,0,cuan){
        if(i==n)break;
        acc += -columns[x][i];
        res = max(res,acc+f(x+1,cuan-i-1+(x+1<=m-k)));
    }
    // cout << x << " " << cuan << " " << res << "\n";
    return res;
}



int main(){FIN;
    cin>>n>>m>>k;
    mset(dp,-1);    
    fore(i,0,n){
        fore(j,0,m){
            cin>>a[i][j];
        }
    }
    fore(i,0,m){
        fore(j,0,n){
            columns[i].pb(-a[j][i]);
        }
        sort(ALL(columns[i]));
    }

    ll res = f(0,1);
    cout << res << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/