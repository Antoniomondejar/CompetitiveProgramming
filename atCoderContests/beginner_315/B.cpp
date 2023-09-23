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
    ll m;cin>>m;
    vector<ll> mon(m), pre(m+1);pre[0]=0;
    ll sum = 0;
    fore(i,0,m)cin>>mon[i],sum+=mon[i],pre[i+1]=pre[i]+mon[i];
    // fore(i,0,m) cout << pre[i] << " ";
    // cout << "\n";
    ll pos = lower_bound(ALL(pre),(sum+1)/2)-pre.begin();
    --pos;
    cout << pos+1 << " " << (sum+1)/2-pre[pos] << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/