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
        ll n;cin>>n;
        if(n==1){cout << "1\n";continue;}
        if(n==2){cout << "1 2\n";continue;}
        cout << "2 ";
        fore(i,1,n/2){
            cout << i+3 << " ";
        }
        cout << "1 ";
        fore(i,n/2+3,n+1){
            cout << i << " ";
        }
        cout << "3\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/