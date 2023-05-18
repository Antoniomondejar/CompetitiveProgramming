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
        ll n, q; cin >> n >> q;
        vector<ll> a(n), b(n);
        fore(i,0,n){
            cin >> a[i];
            a[i] += i;
            // cout << a[i] << " ";
        }
        // cout << "\n";
        fore(i,0,n) cin >> b[i];
        pair<ll,ll> max_t = {0,-1};
        fore(i,0,n){
            if(a[i]<=q && b[i]>max_t.fst){
                max_t = {b[i], i};
            }
        }
        cout << (max_t.snd == -1? -1:max_t.snd+1) << "\n";
    }
    return 0;
}