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
        string s; cin >> s;
        ll s_1s = 0; ll max_s_ls = 0;
        fore(i,0,s.length()){
            if(s[i] == '1' && i == 0){
                s_1s = 1;
                fore(j,0,s.length()-1){
                    if(s[s.length()-1-j] == '1') ++s_1s;
                    else break;
                }
                if (s_1s == s.length()) {max_s_ls = s_1s; break;}
                continue;
            } else if (s[i] == '1'){
                ++s_1s;
            } else {
                max_s_ls = max(max_s_ls, s_1s);
                s_1s = 0;
            }
        }
        max_s_ls = max(max_s_ls,s_1s);
        if(max_s_ls==s.length()){
            cout << max_s_ls*max_s_ls << "\n";
            continue;
        }
        if(max_s_ls % 2 == 0) cout << max_s_ls/2 * (max_s_ls/2+1) << "\n";
        else cout << (max_s_ls/2 +1)*(max_s_ls/2 +1) << "\n";
    }
    return 0;
}