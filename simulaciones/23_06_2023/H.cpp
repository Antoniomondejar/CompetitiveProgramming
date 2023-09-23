#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v)sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<ll> vll;

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vll a(n);
        ll sum = 0;
        fore(i,0,n) {
            cin >> a[i];
            if(i>0)sum+=a[i];
        }
        cout << min(sum+a[0],m) << "\n";
    }
    return 0;
}