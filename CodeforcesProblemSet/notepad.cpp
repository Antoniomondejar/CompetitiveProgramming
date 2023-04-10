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
        ll n; cin >> n;
        str s; cin >> s;
        set<pair<char,char>> p;
        bool r = false;
        fore(i,0,n-1){
            if(i>0 && s[i-1] == s[i] && s[i] == s[i+1] && (i==1 || s[i-2]!=s[i-1])) continue;
            auto el = p.find(mp(s[i], s[i+1]));
            if (el != p.end()){
                r = true;
                break;
            } else p.insert(mp(s[i], s[i+1]));
        }
        if (r) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}