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
    ll t; cin>>t;
    while(t--){
        long double n,d,h;cin>>n>>d>>h;
        vector<long double> a(n);
        fore(i,0,n)cin>>a[i];
        sort(ALL(a));
        long double res = 0;
        long double new_b = d/(2*h);
        cout << setprecision(15);
        // cout << new_b << "\n";
        fore(i,0,n){
            res += d*h;
            if(i<n-1 && a[i]+h>a[i+1]){
                // cout << i << "\n";
                // cout << (a[i]+h-a[i+1]) << " asa\n";
                // cout << d-(2*new_b*(a[i+1]-a[i])) << " asaaa\n";
                res -= (a[i]+h-a[i+1])*(d-(2*new_b*(a[i+1]-a[i])));
            }
        }
        res/=2;
        cout << res << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/