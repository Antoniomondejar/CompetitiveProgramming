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
const ll NMAX = 250010;
const ll MOD = 1e9+7;
ll n,m;
ll mul(ll x, ll y){
    return (x*y)%m;
}
ll add(ll x, ll y){
    return (x+y)%m;
}

ll fact[NMAX];

int main(){FIN;
    cin>>n>>m;
    fact[0]=1;
    fore(i,1,NMAX){
        fact[i]=mul(fact[i-1],i);
    }
    ll res = 0;
    fore(i,0,n){
        ll aux = mul(i+1,mul(fact[n-i],fact[i+1]));
        res = add(res,aux);
    }
    cout << res << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/