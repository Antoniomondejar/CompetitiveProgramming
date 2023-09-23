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

ll pre_s[NMAX];
ll a[NMAX];
ll n;
pair<ll,ll> dp[NMAX];


pair<ll,ll> f(ll x){
    if(x==n-1){
        if(a[n-1]>1)return{a[n-1],0};
        else return {1,a[n-1]};
    }
    pair<ll,ll> &res = dp[x];
    if(res.fst!=-1)return res;
    pair<ll,ll> nex = f(x+1);
    if(a[x]*nex.fst + nex.snd >= pre_s[n]-pre_s[x]){
        return res={a[x]*nex.fst,nex.snd};
    } else if(a[x]>1){
        return res={a[x],pre_s[n]-pre_s[x+1]};
    } else {
        return res={1,pre_s[n]-pre_s[x]};
    }
}

ll r;
// void build(ll x){

// }


int main(){FIN;
    ll t;cin>>t;
    while(t--){
        cin>>n;
        fore(i,0,n)dp[i]={-1,-1};
        fore(i,0,n)cin>>a[i];
        pre_s[0]=0;
        fore(i,1,n+1){
            pre_s[i]=pre_s[i-1]+a[i-1];
        }
        ll res = 0; ll maxi = 0;
        fore(i,0,n){
            ll aux = pre_s[i];
            aux += f(i).fst+f(i).snd;
            cout << i << " " << f(i).fst << " " << f(i).snd << "\n";
            if(res<aux){
                res = aux;
                maxi = i;
            }
        }
        cout << res << " " << maxi << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/