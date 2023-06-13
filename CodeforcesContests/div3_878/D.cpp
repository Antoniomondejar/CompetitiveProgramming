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

ll a[NMAX];

bool can(ll n, ll m){
    ll e_i = a[0]; ll c = 1;
    fore(i,1,n){
        if(a[i]>2*m+e_i){
            c++;
            e_i = a[i];
        }
    }
    return c <= 3;
}

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll n;
        cin >> n;
        fore(i,0,n)cin>>a[i];
        ll l = 0; ll r = 1e9+1;
        sort(a,a+n);
        // fore(i,0,n) cout << a[i] << " ";
        while(l<=r){
            ll m = (l+r)/2;
            if(can(n,m)){
                r = m-1;
            } else {
                l = m+1;
            }
        }
        cout << l << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/