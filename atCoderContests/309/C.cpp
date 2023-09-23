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
    ll n,k; cin>>n>>k;
    vector<pair<ll,ll>> a(n); ll sum = 0;
    fore(i,0,n)cin>>a[i].fst>>a[i].snd,sum += a[i].snd;
    sort(ALL(a));
    bool p = false; ll l_d = 1;
    fore(i,0,n){
        if(sum<=k){cout << l_d << "\n";p=true;break;}
        sum-=a[i].snd;
        l_d = a[i].fst + 1;
    }
    if(!p)cout << a[n-1].fst+1 << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/