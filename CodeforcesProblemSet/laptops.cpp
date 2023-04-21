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
    ll n, p, q; cin >> n;
    pair<ll,ll> l[n];
    fore(i,0,n){
        cin >> p >> q;
        l[i] = {p,q};
    }
    sort(l, l+n);
    bool s = true;
    fore(i,0,n-1){
        s = l[i].snd < l[i+1].snd;
        if(!s) break;
    }
    if(!s) cout << "Happy Alex\n";
    else cout << "Poor Alex\n";
    return 0;
}