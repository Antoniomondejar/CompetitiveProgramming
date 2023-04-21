#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define str string
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

vector <ll> p2(21);

int main(){FIN;
    p2[0]=1;
    fore(i,1,21) p2[i] = p2[i-1]*2;
    ll t; cin >> t;
    while(t--){
        string s; cin >> s;
        map<char,vector<ll>> p;
        fore(i,0,s.length()){
            p[s[i]].pb(i+1);
        }
        ll mres = LONG_LONG_MAX; ll mx_d = -1;
        for(auto e:p){
            mx_d = max(e.snd[0]-1,(ll)(s.length()-e.snd[SZ(e.snd)-1]));
            fore(i,0,SZ(e.snd)-1){
                mx_d = max(mx_d,e.snd[i+1]-e.snd[i]-1);
            }
            if(mx_d == 0) {mres = 0; break;}
            fore(i,0,21){
                if(mx_d==p2[i]){
                    mres = min(mres, i+1);
                    break;
                }
                if(mx_d<p2[i]){
                    mres=min(mres,i);
                    break;
                }
            }
        }
        cout << mres << "\n";
    }
    return 0;
}