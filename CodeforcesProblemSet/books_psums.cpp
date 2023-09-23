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

int main(){FIN;
    ll n,t; cin >> n >> t;
    vector<ll> a(n),ps(n+1);ps[0]=0;
    fore(i,0,n)cin>>a[i],ps[i+1]=ps[i]+a[i];
    ll res = 0;
    fore(i,0,n){
        ll l = i+1; ll r = n;
        while(l<=r){
            ll m = (l+r)/2;
            if(ps[m]-ps[i]<=t){
                l = m+1;
            } else {
                r = m-1;
            }
        }
        res = max(res,r-i);
    }
    cout << res << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/