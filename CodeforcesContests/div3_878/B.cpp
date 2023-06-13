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

ll elevar(ll b, ll e){
    if(e==0) return 1;
    else if(e&1){
        ll x = elevar(b,(e-1)/2);
        return x*x*b;
    } else {
        ll x = elevar(b,e/2);
        return x*x;
    }
}

ll p2[33];
ll m_p;
ll n,k;

ll f(ll x, ll sum){
    if(x == m_p+1 && sum <= n) return 1;
    if(sum>n) return 0;
    ll res = f(x+1,sum+p2[x])+f(x+1,sum);
    return res;
}

int main(){FIN;
    p2[0] = 1;
    fore(i,1,33)p2[i]=p2[i-1]*2;
    ll t; cin >> t;
    while(t--){
        cin >> n >> k;
        ll res = 1;
        m_p = 0;
        while(n>0){
            while(n>=p2[m_p+1] && k>m_p+1){
                ++m_p;
            }
            if(k==m_p+1 && n>=p2[m_p+1]){
                res = elevar(2,k);
                break;
            }
            n -= p2[m_p];
            res += elevar(2,m_p);
            m_p = 0;
        }
        cout << res << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/