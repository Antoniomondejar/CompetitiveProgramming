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
        ll n, inp; cin >> n;
        map<ll,ll> pr;
        fore(i,0,n){
            ll p = 0, k = 0;
            cin >> inp;
            while(inp%2==0){
                inp/=2;
                ++k;
            }
            if(k>=1){
                ++p;
                if(pr.count(2)) pr[2]+=k;
                else pr[2] = k;
            }
            for(int i = 3; i*i<=inp; i+=2){
                k = 0;
                while(inp%i == 0){
                    inp/=i;
                    ++k;
                }
                if(k>=1){
                    ++p;
                    if(pr.count(i)) pr[i]+=k;
                    else pr[i] = k;
                }
            }
            if(inp>1){
                if(pr.count(inp)) pr[inp]+=1;
                else pr[inp] = 1;
            }
        }
        ll res = 0; ll ac = 0;
        for(auto i:pr){
            // cout << i.fst << " " << i.snd << "\n";
            res += i.snd/2;
            if(i.snd%2) ++ac;
            if(ac==3){
                res += 1;
                ac = 0;
            }
        }
        cout << res << "\n";
    }
    return 0;
}