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
const ll NMAX = 1e6+10;
const ll MOD = 1e9+7;

ll a[NMAX];
ll bss[NMAX];

int main(){FIN;
    #ifdef ONLINE_JUDGE
        freopen("deposits.in","r",stdin);
        freopen("deposits.out","w",stdout);
    #endif
    ll n; cin >> n;
    vector<ll> as(n);
    set<ll> ass;
    fore(i,0,n){
        cin >> as[i];
        a[as[i]]++;
        ass.insert(as[i]);
    }
    ll m; cin >> m;
    vector<ll> bs(m);
    fore(i,0,m)cin>>bs[i];
    for(auto i:ass){
        for(int j = 1;j*j<=i; ++j){
            if(i%j==0){
                bss[j]+=a[i];
                if(i!=j*j)bss[i/j]+=a[i];
            }
        }
    }
    ll res = 0;
    fore(i,0,m){
        res += bss[bs[i]];
        // cout << bs[i] << " " << bss[bs[i]] << "\n";
    }
    cout << res << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/