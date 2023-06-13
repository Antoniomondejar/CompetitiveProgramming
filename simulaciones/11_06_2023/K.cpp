#include <bits/stdc++.h>
#define pb push_back
#define fore(i,a,b) for(int i=a, ggdem=b; i<ggdem; ++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void){FIN;
    ll t; cin >> t;
    while(t--){
        ll p_x, p_y; cin >> p_x >> p_y;
        string s; cin>>s;
        ll b_x = 0, b_y = 0;
        map<char,ll> chs;
        fore(i,0,SZ(s)){
            chs[s[i]]++;
            if(s[i]=='U')++b_y;
            else if(s[i]=='D')--b_y;
            else if(s[i]=='L')--b_x;
            else++b_x;
        }
        bool p = true;
        if(b_x>p_x){
            ll aux = b_x-p_x;
            if(chs.count('R')){
                if(chs['R']<aux) p = false;
            } else {
                p = false;
            }
        } else if (b_x<p_x){
            ll aux = p_x-b_x;
            if(chs.count('L')){
                if(chs['L']<aux) p = false;
            } else {
                p = false;
            }
        }
        if(b_y > p_y){
            ll aux = b_y-p_y;
            if(chs.count('U')){
                if(chs['U']<aux) p = false;
            } else {
                p = false;
            }
        } else if (b_y< p_y){
            ll aux = p_y-b_y;
            if(chs.count('D')){
                if(chs['D']<aux) p = false;
            } else {
                p = false;
            }
        }
        if(p)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}