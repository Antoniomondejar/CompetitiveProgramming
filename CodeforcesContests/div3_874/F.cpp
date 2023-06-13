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
ll const MOD = 1e9+7;

ll add(ll x, ll y){
    return (x+y)%MOD;
}

ll mul(ll x, ll y){
    return (x*y)%MOD;
}

ll elevar(ll b, ll e){
    if(e==0)return 1;
    if(e&1){
        ll x = elevar(b,(e-1)/2);
        return mul(x,mul(x,b));
    } else {
        ll x = elevar(b,e/2);
        return mul(x,x);
    }
}

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll n,m; cin>>n>>m;
        vector<ll> a(n); vector<pair<ll,ll>> b;
        map<ll,ll> cs;
        fore(i,0,n){
            cin>>a[i];
            cs[a[i]]++;
        }
        if(m==1){cout << n << "\n";continue;}
        if(n==1){cout << "1\n"; continue;}
        for(auto i:cs){
            b.pb(i);
        }
        ll res = 0; ll c = 1; ll acc = b[0].snd;
        fore(i,1,SZ(b)){
            if(b[i].fst == b[i-1].fst+1){
                ++c;
                acc = mul(acc, b[i].snd);
                if(c == m){
                    res = add(res, acc);
                } else if(c>m){
                    acc = mul(acc, elevar(b[i-m].snd, MOD-2));
                    res = add(res, acc);
                    --c;
                }
            } else {
                c = 1;
                acc = 1;
            }
        }
        cout << res << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/