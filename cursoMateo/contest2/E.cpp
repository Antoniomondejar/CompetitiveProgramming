#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define str string
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
vector<ll> a(200005), b(200005);

bool can(ll m, ll n){
    ll richer = m-1; ll poorer = 0; ll inv = 0;
    fore(i,0,n) {
        if(a[i]>=richer && b[i]>=poorer){
            ++inv;
            --richer;
            ++poorer;
        }
        if(inv == m) return true;
    }
    return false;
}

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        fore(i,0,n){
            cin >> a[i];
            a[i] = min(n-(i+1), a[i]);
            cin >> b[i];
        }
        ll l = 1; ll r = 200005; ll m;
        while(l<=r){
            m = (l+r)/2;
            if(can(m, n)){
                l = m+1;
            } else {
                r = m-1;
            }
        }
        cout << r << "\n";
    }
    return 0;
}