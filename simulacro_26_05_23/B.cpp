#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void){FIN;
    string s; ll n; 
    cin>>s>>n;
    vector<string> words(n);
    fore(i,0,n) cin>>words[i];
    bool f_c = false; bool s_c = false; bool p = false;
    fore(i,0,n){
        if(words[i][0]==s[1])f_c = true;
        if(words[i][1]==s[0])s_c = true;
        if(words[i]==s)p=true;
    }
    if((f_c && s_c) || p)cout << "YES\n";
    else cout << "NO\n";
    return 0;
}