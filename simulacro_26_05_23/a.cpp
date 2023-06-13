#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void){FIN;
    int n; cin>>n;
    set<string> st;
    string s;
    fore(i,0,n) {
        cin>>s;
        if(st.find(s)!=st.end()) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
            st.insert(s);
        }
    }

    return 0;
}