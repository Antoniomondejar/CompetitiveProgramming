#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int ) x.size())
#define fore(i,a,b) for(int i=a,gmat=b;i<gmat;++i)
#define FIN ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define mst(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string board[55];


int main(){FIN;
    ll n;cin>>n;
    ll res = 0;
    fore(i,0,n)cin>>board[i];
    fore(i,0,n){
        fore(j,0,n-1){
            if(board[i][j]=='N' && board[i][j+1]=='N'){
                ++j;
                ++res;
            }
        }
    }
    cout << res << "\n";
    return 0;
}