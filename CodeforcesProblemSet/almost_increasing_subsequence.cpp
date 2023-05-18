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
    ll n, q; cin >> n >> q;
    vector<ll> a(n);
    fore(i,0,n) cin >> a[i];
    vector<ll> i_d_a(n); i_d_a[0] = 0;
    fore(i,1,n){
        if(a[i]<=a[i-1] && a[i]>=a[i+1])
            i_d_a[i] = i_d_a[i-1]+1;
        else i_d_a[i] = i_d_a[i-1];
    }
    i_d_a[n-1] = i_d_a[n-2];
    fore(i,0,q){
        ll l, r;
        cin >> l >> r;
        ll res = r-l+1;
        if(r==l) cout << res << "\n";
        else cout << res - (i_d_a[r-2]-i_d_a[l-1]) << "\n";
    }
    return 0;
}