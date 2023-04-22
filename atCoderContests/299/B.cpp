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
    ll N, T; cin >> N >> T;
    bool c_t = false;
    vector<ll> c(N), r(N);
    ll m_t = -1; ll id;
    fore(i,0,N) {cin >> c[i]; if(c[i] == T) c_t = true;}
    fore(i,0,N){
        cin >> r[i];
        if(c_t && c[i] == T && r[i]>m_t){
            m_t = r[i];
            id = i;
        } else if (!c_t && c[i] == c[0] && r[i]>m_t){
            m_t = r[i];
            id = i;
        }
    }
    cout << id+1 << "\n";
    return 0;
}