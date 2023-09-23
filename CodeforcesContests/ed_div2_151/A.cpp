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
        ll n,k,x; cin >> n >> k >> x;
        if(x!=1){
            cout << "YES\n";
            cout << n << "\n";
            fore(i,0,n){
                cout << "1 ";
            }
            cout << "\n";continue;
        }
        if(k==1) {cout << "NO\n";continue;}
        if(n%2==0){
            cout << "YES\n";
            cout << n/2 << "\n";
            fore(i,0,n/2){
                cout << "2 ";
            }
            cout << "\n";
        } else if(k>=3){
            cout << "YES\n";
            cout << n/2 << "\n";
            fore(i,0,(n/2)-1){
                cout << "2 ";
            }
            cout << "3\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/