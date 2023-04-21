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

bool can(ll n, ll max_m, ll l, ll r, ll *s){
    if (n==0) return true;
    fore(i,l+1,r){
        if(s[i]-s[l]>=max_m && s[r]-s[i]>=max_m)
            return can(n-1, max_m, i, r, s);
        else if(s[r]-s[i]<max_m) return false;
    }
    return false;
}

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll N,C,inp; cin >> N >> C;
        ll *s = (ll *) calloc(N, sizeof(ll));
        fore(i,0,N) {
            cin >> inp; 
            s[i]=inp;
        }
        sort(s, s+N);
        ll max_m; ll l = 0; ll r = s[N-1]-s[0];
        while(l<=r){
            max_m = (l+r)/2;
            if(s[N-1]-s[0]<max_m) {r = max_m-1; continue;}
            if(can(C-2, max_m, 0, N-1, s)){
                l = max_m+1;
            } else {
                r = max_m-1;
            }
        }
        cout << r << "\n";
    }
    return 0;
}