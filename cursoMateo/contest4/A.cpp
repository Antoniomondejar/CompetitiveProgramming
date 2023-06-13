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
    ll x,a,b,c;
    cin >> x >> a >> b >> c;
    ll m = max({x,a,b,c});
    if(x < m) cout << m-x << " ";
    if(a < m) cout << m-a << " ";
    if(b < m) cout << m-b << " ";
    if (c < m) cout << m-c << " ";
    cout << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/