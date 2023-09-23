#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define str string
#define fore(i,a,b) for(int i=a,thxMat=b;i<thxMat;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll NMAX = 2e5+10;
const ll MOD = 1e9+7;

int main(){FIN;
    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        vector<ll> a(n);
        vector<ll> h(n);
        fore(i,0,n)cin>>a[i];
        fore(i,0,n)cin>>h[i];
        ll l = 0, r = 0;
        ll acc = 0;
        ll res = 0;
        while(l<n && r<n){
            //cout << l << " " << r << "\n";
            if(l==r){
                ++r;
                if(a[l]>k){++l;continue;}
                acc=a[l];
                if(r==n)break;
            }
            if((h[r-1]%h[r])!=0){
                acc = 0;
                res = max(res,r-l);
                l=r;
                continue;
            }
            if(acc+a[r]>k){
                res = max(res, r-l);
                acc -=a[l];
                ++l;
            } else {
                acc += a[r];++r;
            }
        }
        res=max(res,r-l);
        cout << res << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/