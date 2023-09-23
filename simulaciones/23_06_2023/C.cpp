#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v)sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<ll> vvl;

int main(){FIN;

    // d = x % 10
    // s += (d-1)*10
    // l = log_10(x)
    // s += l(l+1)/2

    ll t; cin >> t;

    while (t--)
    {
        ll x; cin >> x;
        ll d = x % 10;
        ll s = (d-1)*10;
        ll l = 0;
        while (x > 0) 
        {
            x /= 10;
            l++;
        }
        s += (l*(l+1))/2;
        cout << s << "\n";
    }


    return 0;
}