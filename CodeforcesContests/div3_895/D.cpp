#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define str string
#define fore(i,a,b) for(int i=a,thxMat=b;i<thxMat;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll NMAX = 2e5+10;
const ll MOD = 1e9+7;

int main(){FIN;
    ll t;cin>>t;
    while(t--){
        ll n,x,y;cin>>n>>x>>y;
        if(x==y){cout << "0\n";continue;}
        if(x%y==0){
            ll cua = n/y - n/x;
            ll res = cua*(cua+1)/2;
            cout << -res << "\n";
        } else if(y%x==0){
            ll cua = n/x - n/y;
            ll res = n*(n+1)/2;
            res -= (n-cua)*(n-cua+1)/2;
            cout << res << "\n";
        } else {
            ll cua_x = n/x;
            ll cua_y = n/y;
            cua_x -= n/((x*y)/__gcd(x,y));
            cua_y -= n/((x*y)/__gcd(x,y));
            ll res = n*(n+1)/2;
            res-=(n-cua_x)*(n-cua_x+1)/2;
            res-=(cua_y)*(cua_y+1)/2;
            cout << res << "\n";
        }
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/