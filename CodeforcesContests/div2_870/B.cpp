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
        ll n; cin >> n;
        vector<ll> a(n);
        fore(i,0,n) cin >> a[i];
        vector<ll> a_r(n/2);
        if(n==1){
            cout << "0\n";
            continue;
        }
        if(n==2){
            if(a[0] == a[1])
                cout << "0\n";
            else
                cout << max(a[0],a[1])-min(a[0],a[1]) << "\n";
            continue;
        }
        fore(i,0,n/2){
            a_r[i] = max(a[i], a[n-i-1])-min(a[i],a[n-i-1]);
        }
        ll mcd = 0;
        fore(i,0,n/2){
            mcd = __gcd(mcd,a_r[i]);
        }
        cout << mcd << "\n";
    }
    return 0;
}