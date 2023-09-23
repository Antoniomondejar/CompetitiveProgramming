#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define str string
#define fore(i,a,b) for(int i=a,thxMat=b;i<thxMat;++i)
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
        vector<ll> a(n);vector<ll> num(n+1);
        fore(i,0,n)cin>>a[i],num[a[i]]++;
        ll mex;
        fore(i,0,n+1){
            if(num[i]==0)mex=i;
        }
        a.pb(mex);
        vector<ll> ans(n);
        fore(i,0,n+1){
            if((i+k)%(n+1)==n)continue;
            ans[(i+k)%(n+1)]=a[i];
        }
        for(auto i:ans)cout << i << " ";
        cout << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/