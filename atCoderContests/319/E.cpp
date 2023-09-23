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
const ll NMAX = 2e5+10;
const ll MOD = 1e9+7;

ll tim[10];
ll dp[NMAX][10];
ll n,x,y;
pair<ll,ll> a[NMAX];


ll f(ll x, ll mod){
    if(x>n-1)return 0;
    ll &res = dp[x][mod];    
    if(res!=-1)return res;
    ll donde = a[x-1].fst * mod+a[x-1].snd;
    res = a[x-1].snd;
    if(donde % a[x].fst){
        res += a[x].fst-donde%a[x].fst;
    }
    if(x+1<n-1){
        res += f(x+1,((donde+a[x].fst-donde%a[x].fst)/a[x].fst)%8);
    } else {
        res += a[x].snd + y;
    }
    return res;
}

int main(){FIN;
    cin>>n>>x>>y;
    mset(dp,-1);
    fore(i,0,n-1)cin>>a[i].fst>>a[i].snd;
    ll q;cin>>q;
    while(q--){
        ll q0;cin>>q0;
        ll res = q0+x;
        if(res%a[0].fst){
            res += a[0].fst-res%a[0].fst;
        }
        // cout << res << "\n";
        if(n>2){
            ll cuant = f(1,(res/a[0].fst)%8);
            res += cuant;
            cout << res << "\n";
        } else {
            res += a[0].snd + y;
            cout << res << "\n";
        }
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/