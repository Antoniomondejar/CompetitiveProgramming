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
    ll n;cin>>n;
    vector<ll> a(n), b(n);
    fore(i,0,n)cin>>a[i];
    fore(i,0,n)cin>>b[i];
    sort(ALL(a));sort(ALL(b));
    vector<ll> c(n);
    fore(i,0,n){
        c[i]=a[i]+b[n-1-i];
    }
    sort(ALL(c));
    cout << c.back()-c[0] << "\n";
    return 0;
}