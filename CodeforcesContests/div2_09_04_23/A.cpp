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
        ll a,b; cin >> a >> b;
        if(a == 1 || b == 1){
            cout << 1 << "\n"; cout << a << " " << b << "\n";
            continue;
        }
        cout << 2 << "\n";
        cout << 1 << " " << b-1 << "\n";
        cout << a << " " << b << "\n";
    }
    return 0;
}