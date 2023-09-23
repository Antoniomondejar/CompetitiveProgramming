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
const ll NMAX = 2e5+10;
const ll MOD = 1e9+7;

string mat[3010];

ll izq[3010][3010],der[3010][3010];
ll rows[3010][3010];

int main(){FIN;
    ll t;cin>>t;
    while(t--){
        int n;cin>>n;
        fore(i,0,n)cin>>mat[i];        
        fore(i,0,n)fore(j,0,n)izq[i][j]=0, der[i][j]=0, rows[i][j]=0;
        ll res = 0;
        fore(j,0,n){
            if(mat[0][j]=='1'){
                res++;
                
                if(j>0){izq[1][j-1]+=1;rows[1][j-1]+=1;}
                if(j<n-1){der[1][j+1]+=1;rows[1][j+1]+=1;}
                rows[1][j]+=1;
            }
        }
        fore(i,1,n){
            fore(j,0,n){
                int mi_resu = rows[i][j];
                bool sume=false;
                if(mat[i][j]=='1' && mi_resu%2==0){
                    ++res;sume=true;
                } else if(mat[i][j]=='0' && mi_resu%2==1){
                    ++res;sume=true;
                }
                if(i==n-1)continue;
                if(j>0){rows[i+1][j-1]+=izq[i][j]+sume;izq[i+1][j-1]+=izq[i][j]+sume;}
                if(j<n-1){rows[i+1][j+1]+=der[i][j]+sume;der[i+1][j+1]+=der[i][j]+sume;}
                rows[i+1][j]+=mi_resu+sume;
            }
        }
        cout << res << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/