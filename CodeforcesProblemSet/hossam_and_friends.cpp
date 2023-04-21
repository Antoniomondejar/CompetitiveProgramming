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

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll n, m, inp1, inp2; cin >> n >> m;
        vector<ll> ma(n,n);
        fore(i,0,m){
            cin >> inp1 >> inp2;
            if(inp1 < inp2)
                ma[inp1-1] = min(ma[inp1-1], inp2-1);
            else
                ma[inp2-1] = min(ma[inp2-1], inp1-1);
        }
        fore(i,1,n){
            ma[n-1-i] = min(ma[n-1-i], ma[n-i]);
        }
        ll res = 0;
        fore(i,0,n)
            res += ma[i]-i;
        cout << res << "\n";
    }
    return 0;
}