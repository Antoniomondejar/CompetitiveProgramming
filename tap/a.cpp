#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int ) x.size())
#define fore(i,a,b) for(int i=a,gmat=b;i<gmat;++i)
#define FIN ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define mst(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(){FIN;

    ll n, m; cin >> n >> m;
    vector<ll> a(n), e;
    fore(i, 0, n) cin >> a[i];
    ll cu = 1e10;
    fore(i, 0, m) 
    {
        ll ei; cin >> ei;
        if (ei >= cu) continue;
        cu = ei;
        e.pb(ei);
    }
    e.pb(0);
    fore(i, 0, n)
    {
        while(1)
        {
            auto it = upper_bound(e.rbegin(), e.rend(), a[i]);
            it--;
            ll ne = *it;
            if (ne == 0) break;
            a[i] = a[i] % ne;
            if (a[i] == 0) break;
        }
    }

    fore(i, 0, n) cout << a[i] << " ";
    cout << "\n";

    return 0;
}