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

ll get(ll x){
    ll po=1;
    while(x%(po*2)==0)po*=2;
    if(x==po)po/=2;
    return po;
}

int main(){FIN;
    ll t;cin>>t;
    while(t--){
        ll x;cin>>x;
        vector<ll> ans;
        ans.pb(x);
        while(x>1){
            ll res = get(x);
            x-=res;
            ans.pb(x);
        }
        cout << SZ(ans) << "\n";
        for(auto i:ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/