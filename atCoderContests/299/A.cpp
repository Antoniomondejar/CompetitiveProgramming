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
    ll N; cin >> N;
    string s; cin >> s;
    bool f1=false;
    fore(i,0,N){
        if(s[i]=='*' && !f1){
            cout << "out\n";
            return 0; 
        }
        if(s[i]=='|' && !f1){
            f1 = true;
            continue;
        }
        if(s[i]=='*' && f1){
            cout << "in\n";
            return 0;
        }
        if(s[i]=='|' && f1){
            cout << "out\n";
            return 0;
        }
    }
    return 0;
}