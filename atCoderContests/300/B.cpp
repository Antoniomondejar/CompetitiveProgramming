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
    ll H,W; cin >> H >> W;
    ll A[H][2], B[H][2];
    ll a_w[W][2], b_w[W][2];
    string inp_a[H], inp_b[H];
    fore(i,0,H){
        A[i][0] = 0;
        A[i][1] = 0;
        cin >> inp_a[i];
        fore(j,0,W){
            if(inp_a[i][j] == '#') ++A[i][0];
            else ++A[i][1];
        }
    }
    fore(i,0,H){
        B[i][0] = 0;
        B[i][1] = 0;
        cin >> inp_b[i];
        fore(j,0,W){
            if(inp_b[i][j] == '#') ++B[i][0];
            else ++B[i][1];
        }
    }
    fore(i,0,W){
        a_w[i][0] = 0;
        a_w[i][1] = 0;
        b_w[i][0] = 0;
        b_w[i][1] = 0;
        fore(j,0,H){
            if(inp_a[j][i] == '#') ++a_w[i][0];
            else ++a_w[i][1];
            if(inp_b[j][i] == '#') ++b_w[i][0];
            else ++b_w[i][1];
        }
    }
    bool p = true; bool f = false;
    fore(i,0,H){
        fore(j,0,H){
            if(A[i][0] == B[j][0] && A[i][1] == B[j][1]){
                B[j][0] = -1;
                B[j][1] = -1;
                f = true;
                break;
            }
        }
        if(!f){
            p = false; break;
        }
        f = false;
    }
    if(!p){
        cout << "No\n";
        return 0;
    }
    fore(i,0,W){
        fore(j,0,W){
            if(a_w[i][0] == b_w[j][0] && a_w[i][1] == b_w[j][1]){
                b_w[j][0] = -1;
                b_w[j][1] = -1;
                f = true;
                break;
            }
        }
        if(!f){
            p = false; break;
        }
        f = false;
    }
    cout << (p?"Yes\n":"No\n");
    // cout << (A[0] == B[0] && A[1] == B[1]?"Yes\n":"No\n"); 
    return 0;
}