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
        ll n,c;cin>>n>>c;
        vector<ll> a(n);
        __int128_t sum=0; __int128_t sum_2=0;
        fore(i,0,n)cin>>a[i],sum+=a[i],sum_2+=a[i]*a[i];
        // cout << sum << " " << sum_2 << "\n";
        __int128_t dis = sqrtl(__int128_t(sum*sum)+__int128_t(n*(c-sum_2)));
        // cout << dis << "\n";
        cout << ll((dis-sum)/(2*n)) << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/