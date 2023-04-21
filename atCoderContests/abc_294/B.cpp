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
    ll H, W; string al = ".ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cin >> H >> W;
    vector<string> alp(H);
    ll a[H][W];
    fore(i,0,H){
        fore(j,0,W) cin >> a[i][j];
    }
    fore(i,0,H){
        alp[i] = "";
        fore(j,0,W) alp[i]+=al[a[i][j]];
    }
    // sort(ALL(alp));
    fore(i,0,H) cout << alp[i] << "\n";
    return 0;
}