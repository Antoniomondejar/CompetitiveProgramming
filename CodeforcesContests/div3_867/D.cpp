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
        ll n; cin >> n;
        if (n == 1) {cout << 1 << "\n"; continue;}
        if(n&1) {cout << -1 << "\n"; continue;}
        fore(i,0,n){
            if(i&1) cout << i << " ";
            else cout << n-i << " ";
        }
        cout << "\n";
    }
    return 0;
}