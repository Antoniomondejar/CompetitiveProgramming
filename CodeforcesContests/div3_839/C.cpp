#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef int ll;

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll k, n; cin >> k >> n;
        ll a[k]; ll ns = n-k;
        ll pn = 0;
        fore(i,0,41){
            if (i*(i+1)>2*ns){
                pn = i;
                break;
            }
            if(i*(i+1)==2*ns){
                pn = i+1;
                break;
            }
        }
        a[0] = 1;
        fore(i,1,min(pn+1,k)){
            a[i] = a[i-1] + i;
        }
        if(pn+1<k){
            fore(i,pn+1,k) a[i] = a[i-1]+1;
        }
        fore(i,0,k) cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}