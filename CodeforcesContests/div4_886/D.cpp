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
        vector<ll> a(n);
        fore(i,0,n)cin>>a[i];
        if(n==1){cout << "0\n";continue;}
        sort(ALL(a));
        ll res = 0;
        ll pre_m = 1;
        fore(i,0,n-1){
            if(a[i+1]-a[i]<=k)++pre_m;
            else res = max(pre_m,res),pre_m=1;
        }
        res = max(res,pre_m);
        cout << n-res << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/