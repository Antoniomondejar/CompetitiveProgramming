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
    ll t; cin >> t;
    while(t--){
        ll n, input; cin >> n;
        ll n1 = 0; ll n2 = 0; ll nb = 0;
        bool b1 = false; bool b2 = false;
        fore(i,0,n){
            cin >> input;
            if(input != i+1){
                ++n1;
                b1 = true;
            }
            if(input != n-i){
                ++n2;
                b2 = true;
            }
            nb += b1&&b2;
            b1=false; b2=false;
        }
        if(n1==n2 && nb==0) {cout << "First\n"; continue;}
        if(n1==n2) {cout << "Tie\n"; continue;}
        if(n1>n2){
            n1 -= n2-nb;
            n2 = nb;
            if(n1-nb > nb) cout << "Second\n";
            else cout << "Tie\n";
        } else {
            n2 -= n1-nb;
            n1 = nb;
            if(n2-nb>=nb) cout << "First\n";
            else cout << "Tie\n";
        }
    }
    return 0;
}