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
        ll n; cin >> n;
        fore(i,0,n){
            if(i%2==0) cout << 2*n - i << " ";
            else cout << i+1 << " ";
        }
        cout << "\n";
        fore(i,0,n){
            if(i%2==0) cout << i+1 << " ";
            else cout << n+i << " ";
        }
        cout << "\n";
    }
    return 0;
}