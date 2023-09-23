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

vector<ll> ans;

void f(ll n){
    if(n==1){ans.pb(1);return;}
    if(n%2==0){
        f(n/2);
        for(auto &i:ans){
            // cout << n <<" " << i << " ss\n";
            i*=2;
        }
        return;
    }
    if(n%3==0){
        f(n/3);
        for(auto &i:ans)
            i*=3;
        return;
    }
    __int128_t i = 3;
    while(i*3<n){
        i*=3;
    }
    f(n-i);
    ans.pb(i);
    return;
}

int main(){FIN;
#ifdef ONLINE_JUDGE
  freopen("distribution.in", "r", stdin);
  freopen("distribution.out", "w", stdout);
#endif
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        f(n);
        cout << SZ(ans) << "\n";
        for(auto i:ans) cout << i << " ";
        cout << "\n";
        ans.clear();
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/