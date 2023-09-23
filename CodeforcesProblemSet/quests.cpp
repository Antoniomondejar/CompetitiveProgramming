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
        ll n,c,d;cin>>n>>c>>d;
        vector<ll> a(n);fore(i,0,n)cin>>a[i];
        sort(ALL(a));
        ll sum = 0;
        fore(i,0,min(d,n)){
            sum+=a[n-1-i];
        }
        if(sum>=c){cout << "Infinity\n";continue;}
        ll i = n-1;--d;
        while(d>=0 && sum<c){
            --d;
            sum+=a[i];
            --i;
            if(i==-1)i=n-1;
        }
        if(d<0){cout << "Impossible\n";}
        else cout << d << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/