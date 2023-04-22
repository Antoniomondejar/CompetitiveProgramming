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
    ll m_int = -1; ll c_int = 0; bool ho = false; bool h_ = false;
    fore(i,0,N){
        if(s[i] == 'o'){
            ho = true;
            ++c_int;
        } else if(s[i] == '-'){
            h_ = true;
            m_int = max(c_int, m_int);
            c_int = 0;
        }
    }
    m_int = max(m_int, c_int);
    if(ho && h_)
        cout << m_int << "\n";
    else
        cout << "-1\n";
    return 0;
}