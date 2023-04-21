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

ll fact(ll n){
    ll res = 1;
    fore(i,1,n+1){
        res = (res * i)%998244353;
    }
    return res;
}

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        if(n%2==0){
            ll f = fact(n/2);
            cout << (f*f)%998244353 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    return 0;
}