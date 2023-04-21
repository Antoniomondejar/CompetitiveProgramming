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

vector<ll> k;
bool can(ll m, ll t){
    ll res = 0;
    fore(i,0,SZ(k)){
        res += m/k[i];
        if(res>=t)return true;
    }
    return false;
}

int main(){FIN;
    ll n, t, inp; cin >> n >> t;
    fore(i,0,n) {cin >> inp; k.pb(inp);}
    sort(ALL(k));
    ll m; ll l = 0; ll r = 1000000000000000000;
    while(l<=r){
        m = (l+r)/2;
        if(can(m, t))
            r = m-1;
        else
            l = m+1;
    }
    cout << l << "\n";
    return 0;
}