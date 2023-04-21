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
        ll n, mex; cin >> n;
        ll a_s[n];
        ll a[n];
        fore(i,0,n){
            cin >> a[i];
            a_s[i] = a[i];
        }
        sort(a_s, a_s+n);
        mex = 0;
        if(a_s[0] == 0) {
            fore(i,1,n){
                if(a_s[i] > a_s[i-1]+1){
                    mex = a_s[i-1]+1;
                }
            }
            if(mex == 0) mex = a_s[n-1] + 1;
        }
        int l_in = n; int r_in = -1;
        fore(i,0,n){
            if(a[i] == mex+1){
                l_in = min(l_in, i);
                r_in = max(r_in, i);
            }
        }
        bool p = true;
        if(r_in == -1){
            p = mex != n;
        } else {
            p = true;
            map<ll,ll> oc;
            fore(i,0,n){
                if(oc.count(a[i])) ++oc[a[i]];
                else oc[a[i]] = 1;
            }
            fore(i,l_in,r_in+1){
                if(a[i]<mex && oc[a[i]]<2){
                    p = false;
                    break;
                }
                --oc[a[i]];
            }
        }
        if(p) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}