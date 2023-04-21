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
    ll n, inp1, inp2; cin >> n;
    vector<ll> a(n),b(n);
    fore(i,0,n){
        cin >> inp1 >> inp2;
        a[i]= inp1;
        b[i] = inp2; 
    }
    ll mx = 0;
    sort(ALL(b)); sort(ALL(a));
    fore(i,0,n){
        mx = max(mx, (ll)(lower_bound(a.begin(), a.end(), b[i])-a.begin()-i));
    }
    cout << mx << "\n";
    return 0;
}