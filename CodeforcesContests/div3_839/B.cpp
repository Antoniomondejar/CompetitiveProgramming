#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef int ll;

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll a,b,c,d; cin >> a >> b >> c >> d;
        if(a < c && b < d && a < b && c < d) cout << "YES\n";
        else if(c < d && a < b && c < a && d < b) cout << "YES\n";
        else if(d < b && c < a && d < c && b < a) cout << "YES\n";
        else if(b < a && d < c && b < d && a < c) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}