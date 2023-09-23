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
        vector<ll> a(n-1);
        fore(i,0,n-1)cin>>a[i];
        vector<ll> p(n+1);
        if(a[0]<=n)p[a[0]]++;
        fore(i,0,n-2){
            if(a[i+1]-a[i]<=n)
                p[a[i+1]-a[i]]++;
        }
        set<ll> nms;
        fore(i,1,n+1){
            if(p[i]==0)nms.insert(i);
        }
        if(SZ(nms)>2){cout << "NO\n";continue;}
        if(SZ(nms)==1){cout << "YES\n";continue;}
        ll sum = 0;
        for(auto i:nms)sum+=i;
        // cout << p[a[0]] << "\n";
        bool po = (a[0]<=n && p[a[0]]==1?false:sum==a[0]);
        fore(i,1,n-1){
            po=po||(sum==a[i]-a[i-1] && (a[i]-a[i-1]>n || p[a[i]-a[i-1]]>1));
        }
        if(po)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/