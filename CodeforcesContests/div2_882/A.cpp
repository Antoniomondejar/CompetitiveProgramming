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
    ll t; cin >> t;
    while(t--){
        ll k,n;cin>>n>>k;
        vector<ll> a(n); ll total_sum = 0;
        vector<ll> ans;
        fore(i,0,n){
            cin>>a[i];
            if(i>0){
                total_sum += abs(a[i]-a[i-1]);

                ans.pb(abs(a[i]-a[i-1]));
            }
        }
        // cout << total_sum << "\n";
        sort(ALL(ans));
        fore(i,0,k-1){
            // cout << ans[SZ(ans)-1-i] << "\n";
            total_sum-=ans[SZ(ans)-1-i];
        }
        cout << total_sum << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/