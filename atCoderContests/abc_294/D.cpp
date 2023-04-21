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
    ll N, Q, ty, x; cin >> N >> Q;
    set<ll> n_cal, alr_cal;
    fore(i,0,N) n_cal.insert(i+1);
    while(Q--){
        cin >> ty;
        if(ty == 1) {
            auto cal = n_cal.begin();
            alr_cal.insert(*cal);
            n_cal.erase(*cal);
            continue;
        }
        if(ty == 2){ 
            cin >> x;
            alr_cal.erase(x);
        } else {
            auto cal = alr_cal.begin();
            cout << *cal << "\n";
        }
    }
    return 0;
}