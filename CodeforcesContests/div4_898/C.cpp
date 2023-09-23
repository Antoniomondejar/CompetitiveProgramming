#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define str string
#define fore(i,a,b) for(int i=a,thxMat=b;i<thxMat;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll NMAX = 2e5+10;
const ll MOD = 1e9+7;

string mat[15];
ll points[15][15];

int main(){FIN;
    ll t;cin>>t;
    while(t--){
        fore(i,0,10)cin>>mat[i];
        
        fore(j,0,5){
            fore(i,j,10-j){
                points[j][i]=j+1;
                points[i][j]=j+1;
                points[9-j][i]=j+1;
                points[i][9-j]=j+1;
            }
        }
        ll res = 0;
        fore(i,0,10){
            fore(j,0,10){
                if(mat[i][j]=='X'){
                    res += points[i][j];
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/