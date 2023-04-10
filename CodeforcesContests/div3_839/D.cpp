#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll n, d; cin >> n;
        ll a[n]; fore(i,0,n) cin >> a[i];
        ll minx = LONG_LONG_MIN; ll maxx = LONG_LONG_MAX;
        bool p = true;
        fore(i,0,n-1){
            if(a[i]<a[i+1]){
                d = (a[i]+a[i+1])/2 + ((a[i]+a[i+1])%2!=0 && a[i]+a[i+1] < 0);
                maxx = min(maxx,d);
                if(minx>maxx){
                    p = false;
                    break;
                }
            } else if (a[i]>a[i+1]){
                d = (a[i]+a[i+1])/2 + ((a[i]+a[i+1])%2!=0 && a[i]+a[i+1] > 0);
                minx = max(minx, d);
                if(minx>maxx){
                    p = false;
                    break;
                }
            }
        }
        if(!p) cout << -1 << "\n";
        else cout << min(maxx,1000000000ll) << "\n";
    }
    return 0;
}