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
    ll t;cin>>t;
    while(t--){
        ll x,y,n;cin>>x>>y>>n;
        ll cant = (n-1)*(n)/2;
        // cout << cant << "\n";
        if(x+cant>y){cout << "-1\n";continue;}
        cout << x << " ";
        ll last = y-cant;
        fore(i,0,n-2){
            cout << last+(n-i-1) << " ";
            last = last+(n-i-1);
        }
        cout << y << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/