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
typedef __int128_t ill;
const ll NMAX = 2e5+10;
const ll MOD = 1e9+7;

ll n,x;
ll a[NMAX];
bool can(ill me){
    ill cuan=0;
    fore(i,0,n){
        cuan += ill(max(ll(me-a[i]),0ll));
    }
    return cuan<=x;
}



int main(){FIN;
    ll t;cin>>t;
    while(t--){
        cin>>n>>x;
        fore(i,0,n)cin>>a[i];
        ill l = 1, r = 1e18+10;
        while(l<=r){
            ill me=(l+r)/2;
            if(can(me))l=me+1;
            else r=me-1;
        }
        cout << (ll)r << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/