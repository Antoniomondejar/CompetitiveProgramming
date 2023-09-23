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
    ll n,t;cin>>n>>t;
    ll sum = 0;
    fore(i,0,n){
        char c; ll x; cin>>c>>x;
        sum += x;
    }
    double res = double(sum)/double(t);
    cout << setprecision(16) << res << "\n";
    return 0;
}