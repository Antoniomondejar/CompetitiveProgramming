#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int **p_g;
int **p_r;

string rev(string s){
    string res = "";
    for(int i = s.length()-1; i>=0; i--)
        res += s[i];
    return res;
}

bool le_c(string s, string h){
    fore(i,0,s.length()){
        if(s[i] == h[i] && s[i] == '1') return true;
    }
    return false;
}

string bfs(ll C, ll R, int **p){
    int **vis = (int **) calloc(R, sizeof(int *));
    fore(i,0,R) vis[i] = (int *) calloc(C,sizeof(int *));
    queue<pair<ll,ll>> bfs_q;
    ll v = 0;
    fore(i,0,C){
        if(!p[0][i] && !vis[0][i]){
            bfs_q.push({i,0});
            vis[0][i] = 1;
        }
    }
    while(SZ(bfs_q)){
        auto pa = bfs_q.front(); auto pa_aux = bfs_q.front();
        bfs_q.pop();
        if(pa.snd == R-1) return "Y\n";
        if(!p[pa.snd+1][pa.fst] && !vis[pa.snd+1][pa.fst]){
            bfs_q.push({pa.fst,pa.snd+1});
            vis[pa.snd+1][pa.fst] = 1;
        }
        if (pa.snd > 0 && !p[pa.snd-1][pa.fst] && !vis[pa.snd-1][pa.fst]){
            bfs_q.push({pa.fst,pa.snd-1});
            vis[pa.snd-1][pa.fst] = 1;
        }
        fore(i,0,C){
            v = (pa.fst + 1)%C;
            ++pa.fst;
            if (p[pa.snd][v]) break;
            if (vis[pa.snd][v]) continue;
            vis[pa.snd][v] = 1;
            if (!p[pa.snd+1][v] && !vis[pa.snd+1][v]){
                bfs_q.push({v,pa.snd+1});
                vis[pa.snd+1][v] = 1;
            }
            if(pa.snd==0) continue;
            if (!p[pa.snd-1][v] && !vis[pa.snd-1][v]){
                bfs_q.push({v,pa.snd-1});
                vis[pa.snd-1][v] = 1;
            }
        }
        pa = pa_aux;
        fore(i,0,C){
            v = (pa.fst == 0?(C-1):pa.fst-1);
            if (p[pa.snd][v]) break;
            pa.fst = (pa.fst == 0?(C-1):pa.fst-1);
            if (vis[pa.snd][v]) continue;
            vis[pa.snd][v] = 1;
            if (!p[pa.snd+1][v] && !vis[pa.snd+1][v]){
                bfs_q.push({v,pa.snd+1});
                vis[pa.snd+1][v] = 1;
            }
            if(pa.snd==0) continue;
            if (!p[pa.snd-1][v] && !vis[pa.snd-1][v]){
                bfs_q.push({v,pa.snd-1});
                vis[pa.snd-1][v] = 1;
            }
        }
    }
    return "N\n";
}


int main(){FIN;
    ll R, C; cin >> R >> C;
    p_g = (int **) calloc (R,sizeof(int *)); p_r = (int **) calloc (R,sizeof(int *));
    fore(i,0,R) {
        p_g[i] = (int *) calloc(C,sizeof(int));
        p_r[i] = (int *) calloc(C,sizeof(int));
    }
    string inp, nu, nu_r, aux1, aux2;
    cin >> nu;
    nu_r = rev(nu);
    vector<string> nus(C); nus[0] = nu;
    vector<string> nus_r(C); nus_r[0] = nu_r;
    aux1 = nu; aux2 = nu_r;
    fore(i,1,C){
        nus[i] = aux1[C-1] + aux1;
        nus[i].pop_back();
        aux1 = nus[i];
        nus_r[i] = aux2[C-1] + aux2;
        nus_r[i].pop_back();
        aux2 = nus_r[i];
    }
    fore(i,0,R){
        cin >> inp;
        fore(j,0,C){
            if(le_c(nus[j], inp)) p_g[i][j] = 1;
            if(le_c(nus_r[j], inp)) p_r[i][j] = 1;
        }
    }
    string res = bfs(C, R, p_g);
    string res_2 = bfs(C, R, p_r);
    if(res == "Y\n" || res_2 == "Y\n") cout << "Y\n";
    else cout << "N\n";
    return 0;
}