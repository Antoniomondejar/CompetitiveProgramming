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
        ll n,k; cin >> n >> k; ll d = 0;
        vector<ll> p(n); vector<pair<ll,ll>> ds; 
        fore(i,0,n){
            cin >> p[i]; --p[i];
            if(abs(i-p[i]) % k != 0){
                ++d;
                ds.pb({i,p[i]});
            }
        }
        if(d==0) cout << 0 << "\n";
        else if (d>2) cout << -1 << "\n";
        else if(d==2) {
            if (abs(ds[0].snd-ds[1].fst) % k == 0 && abs(ds[1].snd-ds[0].fst) % k == 0) {
                cout << 1 << "\n";
            } else {
                cout << -1 << "\n";
            }
        } else cout << -1 << "\n";
    }
    return 0;
}