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

ll mat[5][5];

int main(){FIN;
    vector<ll> fact(10);
    fact[0]=1;
    fore(i,1,10)fact[i]=fact[i-1]*i;
    vector<ll> a(9);
    fore(i,0,9)cin>>a[i];
    sort(ALL(a));
    ll count= 0;

    do{
        mat[0][0]=a[0],mat[0][1]=a[1],mat[0][2]=a[2];
        mat[1][0]=a[3],mat[1][1]=a[4],mat[1][2]=a[5];
        mat[2][0]=a[6];mat[2][1]=a[7];mat[2][2]=a[8];

        fore(i,0,3){
            fore(j,0,3){
                cout << mat[i][j]<< " ";
            }
            cout << "\n";
        }
        cout << "\n";

        if(mat[0][0]==mat[0][1] && mat[0][1]!=mat[0][2]){count++;continue;}
        if(mat[1][0]==mat[1][1] && mat[1][1]!=mat[1][2]){count++;continue;}
        if(mat[2][0]==mat[2][1] && mat[2][1]!=mat[2][2]){count++;continue;}
        if(mat[0][0]==mat[1][0] && mat[1][0]!=mat[2][0]){count++;continue;}
        if(mat[0][1]==mat[1][1] && mat[1][1]!=mat[2][1]){count++;continue;}
        if(mat[0][2]==mat[1][2] && mat[1][2]!=mat[2][2]){count++;continue;}
        if(mat[0][0]==mat[1][1] && mat[1][1]!=mat[2][2]){count++;continue;}
        if(mat[0][2]==mat[1][1] && mat[1][1]!=mat[2][0]){count++;continue;}
    } while(next_permutation(ALL(a)));
    cout << count << "\n";
    double res = double(count)/double(fact[9]);
    cout << setprecision(10) << res << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/