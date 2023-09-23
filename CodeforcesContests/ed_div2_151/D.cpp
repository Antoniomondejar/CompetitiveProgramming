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
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> p_s(n+1);p_s[0]=0;
        vector<ll> a(n); fore(i,0,n)cin>>a[i],p_s[i+1]=p_s[i]+a[i];
        ll ma = 0; ll mini = 0; ll res = 0;
        fore(i,1,n+1){
            mini=min(p_s[i]-ma,mini);
            if(mini==p_s[i]-ma)res=ma;
            ma=max(ma,p_s[i]);
        }
        cout << res << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/