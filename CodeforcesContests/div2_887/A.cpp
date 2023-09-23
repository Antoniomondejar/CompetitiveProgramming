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
        vector<ll> a(n);
        bool sor=true;
        fore(i,0,n){
            cin>>a[i];
            if(i>0 && a[i]<a[i-1])sor=false;
        }
        if(!sor){cout << "0\n";continue;}
        ll mini=1e10;
        fore(i,1,n){
            mini=min(a[i]-a[i-1],mini);
        }
        cout << (mini+2)/2 << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/