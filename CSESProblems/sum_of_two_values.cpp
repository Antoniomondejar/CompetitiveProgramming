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
    ll n, x, y; cin >> n >> x;
    vector<ll> a(n), b(n);
    fore(i,0,n) {cin >> a[i];b[i]=a[i];}
    sort(ALL(a));
    bool p = false;
    fore(i,0,n-1){
        if(a[i]>=x){cout << "IMPOSSIBLE\n";break;}
        y = max((ll)(lower_bound(ALL(a),x-a[i])-a.begin()),i+1);
        if(a[i]+a[y] == x) {p=true;break;}
    }
    if(p){
        ll l = -1;ll r = -1;
        fore(i,0,n){
            if(b[i] == a[y] && l == -1){
                l = i;
                continue;
            }
            if(b[i] == x-a[y])
                r = i;
        }
        cout << l+1 << " " << r+1 << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}