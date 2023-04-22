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

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll k, x, l, r, m; cin >> k >> x;
        ll res = 0;
        if(x>=k*(k+1)/2){
            res = k;
            x -= k*(k+1)/2;
        } else {
            l = 0; r = k;
            while(l<=r){
                m = (l+r)/2;
                if(m*(m+1)/2>=x){
                    r = m-1;
                } else {
                    l = m+1;
                }
            }
            cout << l << "\n";
            continue;
        }
        ll h = k*(k-1)/2; 
        if(x>=h){
            cout << 2*k-1 << "\n";
        } else {
            ll l = 0; ll r = k+1;
            while(l<=r){
                m = (r+l)/2;
                if(h-m*(m+1)/2>=x){
                    l = m+1;
                } else {
                    r = m-1;
                }
            }
            res += (k-1)-r;
            cout << res << "\n";
        }
    }
    return 0;
}