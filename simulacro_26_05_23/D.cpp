#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void){FIN;
    ll n, m; cin >> n >> m;
    ll minn = (n%m)*(((n/m)+1)*(n/m))/2;
    ll minn2 = (m-(n%m))*(n/m)*((n/m)-1)/2;
    ll max = (n-m+1)*(n-m)/2;
    cout << minn+minn2 << " " << max << "\n";
    return 0;
}