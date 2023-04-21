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
    ll n,m, d; cin >> n >> m;
    map<ll,ll> df;
    fore(i,0,m){
        cin >> d;
        if(df.count(d)) ++df[d];
        else df[d] = 1;
        // cout << SZ(df) << "\n";
        if(SZ(df) == n){
            cout << 1;
            fore(j,1,n+1){
                if(df[j] == 1) {df.erase(j); continue;}
                --df[j];
            }
        } else {
            cout << 0;
        }
    }
    cout << "\n";
    return 0;
}