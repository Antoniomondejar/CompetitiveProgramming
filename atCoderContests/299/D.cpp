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
    ll N, inp, s_l, s_r, m; cin >> N;
    ll l = 1; ll r = N; s_l = 0; s_r = 1;
    while(r-l>1){
        m = (r+l)/2;
        cout << "? " << m << endl;
        cin >> inp;
        if(inp!=s_l){
            r = m;
            s_r = inp;
            continue;
        }
        if(inp!=s_r){
            l = m;
            s_l = inp;
            continue;
        }
    }
    cout << "! " << l << "\n";
    return 0;
}