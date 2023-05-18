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
        ll n, k; cin >> n >> k;
        vector<ll> b(n);
        vector<pair<ll,ll>> a(n);
        fore(i,0,n) {
            ll inp;
            cin >> inp;
            a[i] = {inp, i};
        }
        fore(i,0,n) cin >> b[i];
        sort(ALL(a));
        fore(i,0,n){
            if(a[i].fst<=k)
                k += b[a[i].snd];
            else
                break;
        }
        cout << k << "\n";
    }
    return 0;
}