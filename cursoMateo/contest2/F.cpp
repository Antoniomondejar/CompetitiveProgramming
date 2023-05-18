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
vector<ll> h(200005);

bool can(ll m, ll n){
    bool p = true;
    vector<ll> h_s(n,0);
    fore(i,0,n-2){
        if(h[n-1-i]<m){
            fore(j,0,n) h[j] -= h_s[j];
            return false;
        }
        ll h_p = min(h[n-1-i]-h_s[n-1-i], h[n-1-i]-m);
        if(h_p < 3) continue;
        if(h_p%3!=0){
            --h_p;
            if(h_p%3!=0){
                --h_p;
            }
        }
        h[n-1-i-2] += 2*(h_p/3);
        h[n-1-i-1] += h_p/3;
        h_s[n-1-i-2] += 2*(h_p/3);
        h_s[n-1-i-1] += h_p/3;            
    }
    if(h[0]<m || h[1] < m){
        p = false;
    }
    fore(i,0,n) h[i] -= h_s[i];
    return p;
}

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        fore(i,0,n) cin >> h[i];
        ll l = 0; ll r = 1000000000000; ll m;
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