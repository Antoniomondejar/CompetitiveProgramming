#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// #define x first
// #define y second
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5+10;
typedef pair<int,int> PII;
string s[N];
void solve(){
    for(int i=0;i<3;i++){
        cin>>s[i];
    }
    string ans = "DRAW";
    for(int i=0;i<3;i++){
        if(s[i][0]==s[i][1]&&s[i][0]==s[i][2]){
            ans = s[i][0];
        }
        if(s[0][i]==s[1][i]&&s[1][i]==s[2][i]){
            ans = s[0][i];
        }
    }
    if(s[0][0]==s[1][1]&&s[0][0]==s[2][2]){
        ans = s[0][0];
    }
    if(s[0][2]==s[1][1]&&s[1][1]==s[2][0]){
        ans = s[1][1];
    }
    if(ans==".")
    cout<<"DRAW"<<endl;
    else
    cout<<ans<<endl;
}
signed main(){
    int T = 1;
    IOS;
    cin>>T;
    while(T--)solve();
}