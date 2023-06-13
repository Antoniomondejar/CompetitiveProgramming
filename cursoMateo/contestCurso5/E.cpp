#include "bits/stdc++.h"
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
const ll NMAX = 1e6+10;
const ll MOD = 1e9+7;
ll a,b,n,m_d;
set<ll> ns;
ll fact[NMAX];

ll add(ll x, ll y){
    return (x+y)%MOD;
}

ll mul(ll x, ll y){
    return (x*y)%MOD;
}

ll elevar(ll b, ll e){
    if(e == 0) return 1;
    if(e%2 == 0) {
        ll x = elevar(b,e/2);
        return mul(x,x);
    }
    ll x = elevar(b,(e-1)/2);
    return mul(mul(x,x),b);
}

ll comb(ll n, ll k){
    if(n == k || k == 0) return 1;
    ll den = mul(fact[n-k], fact[k]);
    return mul(fact[n], elevar(den, MOD-2));
}

void build(ll x, ll d){
    if(d == m_d) return;
    ll x1 = x*10+a;
    ll x2 = x*10+b;
    ns.insert(x1);
    ns.insert(x2);
    build(x1, d+1);
    build(x2, d+1);
}

int main(){FIN;
    cin >> a >> b >> n;
    m_d = SZ(to_string(n*max(a,b)));
    build(0,0);
    fact[0] = 1; fore(i,1,n+2)fact[i]=mul(fact[i-1],i);
    ll res = 0;
    for(auto it:ns){
        if(a==b){
            if(it == n*a){
                res = 1;
            }
            continue;
        }
        fore(i,0,n+1){
            ll sum = (n-i)*a+i*b;
            if(sum == it){
                res = add(res,comb(n,i));
            }
        }
    }
    cout << res << '\n';
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/