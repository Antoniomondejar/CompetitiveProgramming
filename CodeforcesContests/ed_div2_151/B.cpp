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
    ll t; cin >> t;
    while(t--){
        ll xa,ya,xb,yb,xc,yc; cin>>xa>>ya>>xb>>yb>>xc>>yc;
        ll res = 1;
        if(xa>xb && xa>xc){
            res += min(abs(xa-xc),abs(xa-xb));
        }
        if(xa<xb && xa < xc){
            res += min(abs(xa-xc),abs(xa-xb));
        }
        if(ya>yb && ya>yc){
            res += min(abs(ya-yc),abs(ya-yb));
        }
        if(ya<yb && ya < yc){
            res += min(abs(ya-yc),abs(ya-yb));
        }
        cout << res << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/