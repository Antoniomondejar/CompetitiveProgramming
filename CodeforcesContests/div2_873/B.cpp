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
        ll n; cin >> n;
        vector<ll> a(n);
        fore(i,0,n) cin >> a[i];
        vector<ll> dis;
        fore(i,0,n){
            if(a[i] == i+1) continue;
            else{
                dis.pb(abs(a[i]-(i+1)));
            }
        }
        ll min_d = dis[0];
        fore(i,1,SZ(dis)){
            min_d = __gcd(min_d,dis[i]);
        }
        cout << min_d << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/