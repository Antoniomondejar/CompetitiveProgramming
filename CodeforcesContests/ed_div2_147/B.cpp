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
        ll n; cin >> n;
        vector<ll> a(n), a_s(n);
        fore(i,0,n) cin >> a[i];
        fore(i,0,n) cin >> a_s[i];
        ll fc = n+1; ll lc = -1;
        fore(i,0,n){
            if(a[i] != a_s[i]){
                fc = min(fc, i);
                lc = max(lc, i);
            }
        }
        // cout << fc << " " << lc << "\n";
        ll fc_aux = fc;
        if(fc == n+1){cout << 1 << " " << n << "\n"; continue;}
        fore(i,0,fc_aux){
            if(a_s[fc_aux-1-i] <= a_s[fc])
                --fc;
            else
                break;
        }
        ll lc_aux = lc;
        fore(i,1,n-lc_aux){
            if(a_s[lc]<=a_s[lc_aux+i])
                ++lc;
            else
                break;
        }
        cout << fc+1 << " " << lc+1 << "\n";
    }
    return 0;
}