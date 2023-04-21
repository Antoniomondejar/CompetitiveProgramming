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

bool can(ll m, ll *a, ll *b, ll n){
    ll sp = 0;
    fore(i,0,n){
        if(a[i]>m) sp+=b[i];
        if(sp>m) return false;
    }
    if(sp<=m) return true;
    return false;
}

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll *a = (ll *)calloc(n, sizeof(ll));
        ll *b = (ll *)calloc(n, sizeof(ll));
        fore(i,0,n) cin >> a[i];
        fore(i,0,n) cin >> b[i];
        ll l = 0; ll r = 10000000000; ll m;
        while(l<=r){
            m = (l+r)/2;
            if (can(m, a, b, n)){
                r = m-1;
            } else {
                l = m+1;
            }
        }
        cout << l << "\n";
    }
    return 0;
}