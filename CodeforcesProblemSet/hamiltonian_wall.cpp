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
        ll m; cin >> m;
        char g[3][m];
        map<pair<ll,ll>, ll> ady;
        fore(i,0,m) {
            cin >> g[1][i];
            if (g[1][i] == 'B') ady[mp(1,i)] = 0;
        }
        fore(i,0,m){
            cin >> g[2][i];
            if (g[2][i] == 'B') ady[mp(2,i)] = 0;
        } 
        fore(i,1,3){
            fore(j,0,m){
                if(g[i][j]=='W') continue;
                if(i==2 && g[i-1][j] == 'B') ++ady[mp(i,j)];
                if(i==1 && g[i+1][j] == 'B') ++ady[mp(i,j)];
                if(j>0 && g[i][j-1] == 'B') ++ady[mp(i,j)];
                if(j<m-1 && g[i][j+1] == 'B') ++ady[mp(i,j)];
            }
        }
        // ll c = 0;
        bool p = true;
        fore(i,1,3){
            fore(j,0,m){
                if(g[i][j]=='W') continue;
                if(ady[mp(i,j)]==3){
                    // cout << i << " " << j << "\n";
                    if(ady[mp(i+1,j)]==3){
                        ady[mp(i,j)] = 2;
                        ady[mp(i+1,j)] = 2;
                        continue;
                    }
                    if(ady[mp(i-1,j)]==3){
                        ady[mp(i,j)] = 2;
                        ady[mp(i-1,j)] = 2;
                        continue;
                    }
                    if(ady[mp(i,j+1)]==3){
                        ady[mp(i,j)] = 2;
                        ady[mp(i,j+1)] = 2;
                        continue;
                    }
                    if(ady[mp(i,j-1)]==3){
                        ady[mp(i,j)] = 2;
                        ady[mp(i,j-1)] = 2;
                        continue;
                    }
                    if(j+1==m-1){
                        ady[mp(i,j)] = 2;
                        --ady[mp(i,j+1)];
                        continue;
                    }
                    p = false;
                    break;
                } else if (ady[mp(i,j)]==0 && SZ(ady)>1) {p = false; break;}
            }
        }
        if (p) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;

}