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
        ll n,k;cin>>n>>k;
        vector<ll> c(n);
        fore(i,0,n)cin>>c[i];
        ll c_0 = c[0]; ll c_n = c[n-1];
        ll k_c_0 = k-1-(c_0==c_n); ll k_c_n = k-1;
        fore(i,1,n-1){
            if(k_c_0 && c[i]==c_0) {--k_c_0;continue;}
            if(!k_c_0 && k_c_n && c[i]==c_n)--k_c_n;
        }
        if((k_c_0 <= 0 && k_c_n <= 0)||(k_c_0<=0 && c_0==c_n)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/