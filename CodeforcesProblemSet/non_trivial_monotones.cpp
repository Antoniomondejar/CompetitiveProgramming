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
    ll m = 0; ll c_aux = 0;
    fore(i,1,N){
        if(!c_aux && s[i-1] == 'a' && s[i] == 'a'){
            c_aux = 2;
            continue;
        }
        if(s[i] == 'a' && c_aux){
            ++c_aux;
            continue;
        }
        if(s[i] != 'a' && c_aux){
            m += c_aux;
            c_aux = 0;
        }
    }
    m += c_aux;
    cout << m << "\n";
    return 0;
}