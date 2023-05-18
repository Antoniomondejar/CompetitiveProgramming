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
    string S,T; cin >> S >> T;
    map<char,ll> ls, lt;
    set<char> po;
    string at = "atcoder"; fore(i,0,7) po.insert(at[i]);
    fore(i,0,S.length()){
        if(ls.count(S[i]))
            ++ls[S[i]];
        else
            ls[S[i]] = 1;
        if(lt.count(T[i]))
            ++lt[T[i]];
        else
            lt[T[i]]=1;
    }
    if(!ls.count('@') && !lt.count('@')){
        if(S==T) cout << "Yes\n";
        else cout << "No\n";
        return 0;
    }
    bool p = true;
    if(ls['@']>lt['@'] || !lt.count('@')){
        for(auto i:lt){
            if(i.fst == '@') continue;
            if(!ls.count(i.fst)){
                if(!po.count(i.fst)){p=false; break;}
                ls['@'] -= i.snd;
                ls[i.fst] = i.snd;
                if(ls['@'] < 0){
                    p = false;
                    break;
                }
                continue;
            }
            if(i.snd > ls[i.fst]){
                if(!po.count(i.fst)){p=false; break;}
                ls['@'] -= (i.snd-ls[i.fst]);
                ls[i.fst] = i.snd;
                if(ls['@'] < 0){
                    p = false;
                    break;
                }
            }
        }
        if(lt.count('@'))
            for(auto i:ls){
                if(i.fst == '@') continue;
                if(!lt.count(i.fst)){
                    if(!po.count(i.fst)){p=false; break;}
                    lt['@'] -= i.snd;
                    lt[i.fst] = i.snd;
                    if(lt['@'] < 0){
                        p = false;
                        break;
                    }
                    continue;
                }
                if(i.snd > lt[i.fst]){
                    if(!po.count(i.fst)){p=false; break;}
                    lt['@'] -= (i.snd-lt[i.fst]);
                    lt[i.fst] = i.snd;
                    if(lt['@'] < 0){
                        p = false;
                        break;
                    }
                }
            }
    } else {
        for(auto i:ls){
            if(i.fst == '@') continue;
            if(!lt.count(i.fst)){
                if(!po.count(i.fst)){p=false; break;}
                lt['@'] -= i.snd;
                lt[i.fst] = i.snd;
                if(lt['@'] < 0){
                    p = false;
                    break;
                }
                continue;
            }
            if(i.snd > lt[i.fst]){
                if(!po.count(i.fst)){p=false; break;}
                lt['@'] -= (i.snd-lt[i.fst]);
                lt[i.fst] = i.snd;
                if(lt['@'] < 0){
                    p = false;
                    break;
                }
            }
        }
        if(ls.count('@'))
            for(auto i:lt){
                if(i.fst == '@') continue;
                if(!ls.count(i.fst)){
                    if(!po.count(i.fst)){p=false; break;}
                    ls['@'] -= i.snd;
                    ls[i.fst] = i.snd;
                    if(ls['@'] < 0){
                        p = false;
                        break;
                    }
                    continue;
                }
                if(i.snd > ls[i.fst]){
                    if(!po.count(i.fst)){p=false; break;}
                    ls['@'] -= (i.snd-ls[i.fst]);
                    ls[i.fst] = i.snd;
                    if(ls['@'] < 0){
                        p = false;
                        break;
                    }
                }
            }
    }
    if(!p){cout << "No\n"; return 0;}
    for(auto i:ls){
        if(i.snd != lt[i.fst]){
            p = false;
            cout << "No\n";
            break;
        }
    }
    if(p) cout << "Yes\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/