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
        ll n,k; cin >> n >> k;
        ll x, y; bool p = false;
        fore(i,0,n+1){
            if(2*k == (i*i-i) + (n-i)*(n-i)-(n-i)){
                p = true;
                x = i;
                y = n-i;
                break;
            }
            if(p) break;
        }
        if(!p) cout << "NO\n";
        else {
            cout << "YES\n";
            fore(i,0,x){
                cout << 1 << " ";
            }
            fore(i,0,y){
                cout << -1 << " "; 
            }
            cout << "\n";
        }
    }
    return 0;
}