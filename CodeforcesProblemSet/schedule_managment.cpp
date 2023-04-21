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
        ll n,m, inp; cin >> n >> m;
        vector<ll> w(n,0);
        fore(i,0,m){
            cin >> inp;
            ++w[inp-1];
        }
        ll w_p = 0; ll r = 2*m; ll l = 1; ll t_max;
        while(l<=r){
            w_p = 0;
            t_max = (r+l)/2;
            fore(i,0,n){
                w_p += min(w[i], t_max) + (t_max-min(w[i], t_max))/2;
            }
            if(w_p>=m) r = t_max-1;
            else l = t_max+1;
        }
        cout << l << "\n";
    }
    return 0;
}