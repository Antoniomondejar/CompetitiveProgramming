#include <bits/stdc++.h>
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

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll n, l, r; cin >> n >> l >> r;
        ll a[n];
        fore(i,0,n) cin >> a[i];
        sort(a,a+n);
        ll l_p, r_p; ll res = 0;
        fore(i,0,n){
            l_p = max((ll)(lower_bound(a,a+n,l-a[i])-a), i+1);
            r_p = lower_bound(a,a+n,r-a[i]+1)-a; // +1 por off by one (or more :/)
            res += max(0LL,r_p - l_p);
        }
        cout << res << "\n";
    }
    return 0;
}