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
        ll c = 0;
        if(s.length() == 1){
            if(s[0] == '_') cout << 2 << "\n";
            else cout << 1 << "\n";
            continue;
        }
        fore(i,0,s.length()){
            if (s[i] == '_' && i == 0){ 
                ++c;
            }
            if(i == s.length()-1 && s[i] == '_'){
                ++c;
            }
            if(i < s.length()-1 && s[i] == '_' && s[i+1] == '_'){
                ++c;
            }
        }
        cout << c << "\n";
    }
    return 0;
}