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
    ll B, L, r; cin >> B >> L;
    vector<ll> d(L);
    ll s = 0;
    fore(i,0,L){
        cin>>d[i];
        if((L-1-i) % 2 == 0){
            s += d[i];
        } else {
            s += (B+1)-d[i];
        }
    }
    r = s%(B+1);
    if (!r) {cout << 0 << " " << 0 << "\n"; return 0;}
    fore(i,0,L){
        if((L-1-i)%2==0 && d[i]>=r){
            cout << i+1 << " " << d[i]-r << "\n";
            return 0;
        } else if ((L-1-i)%2==1 && d[i]>=(B+1-r)){
            cout << i+1 << " " << d[i]-(B+1-r) << "\n";
            return 0;
        }
    }
    cout << -1 << " " << -1 << "\n";
    return 0;
}


/*
PROOF:
BEING D A DIGIT BETWEEN 0 AND B
B^2 % (B+1) = 1
-> BECAUSE
(B+1)*(B-1) = B^2-B+B-1 = B^2-1;
=> D*B^2 % (B+1) = D

D*B % (B+1) = B+1-D
-> BECAUSE
(B+1)*(D-1) = B*D-B+D-1 = (B*D)-(B+1-D)

WITH THAT PROVEN, IS EASY TO SEE THAT

(D_1 * B^(L-1) + D_2 * B^(L-2) + ... + D_L) % (B+1)
{IF L IS EVEN}
= ((B+1)-D_1 + D_2 + (B+1)-D_3 + ... + D_L) % (B+1)
{IF L IS ODD}
(D_1 + (B+1)-D_2 + D_3 + ... + D_L) % (B+1)
SUPPOSE (D_1 * B^(L-1) + D_2 * B^(L-2) + ... + D_L) % (B+1) = K AN INTEGER BETWEEN 0 AND B
IF K = 0 THEN THE NUMBER IS ALREADY DIVISIBLE BY (B+1).
THEN WE WANT TO FIND THE FIRST DIGIT IN POSITION I FROM LEFT TO RIGHT SUCH AS
- D_I>=K IF L-1-I IS EVEN
-> BECAUSE 
(D_1 * B^(L-1) + D_2 * B^(L-2) + ... + D_L) % (B+1) = K
=> (D_1 * B^(L-1) + D_2 * B^(L-2) + .. + (D_I-K) * B^(L-1-I) + ... + D_L) % (B+1) = K-K % (B+1) = 0

- D_I >= (B+1)-K IF L-1-I IS ODD
-> BECAUSE
(D_1 * B^(L-1) + D_2 * B^(L-2) + ... + D_L) % (B+1) = K
=> (D_1 * B^(L-1) + D_2 * B^(L-2) + .. + (D_I-(B+1-K)) * B^(L-1-I) + ... + D_L) % (B+1) = K+(B+1-K) % (B+1) = (B+1) % (B+1) = 0

NOTE THAT THE >= IS NEEDED BECAUSE THE PROBLEM ONLY LET US REDUCE THE DIGITS.
IF WE CANT FIND ANY DIGIT THAT SATISFIES THE PROPIERTIES DESCRIPTED ABOVE
THEN THE PROBLEM HAS NO SOLUTION. AND IF WE CAN FIND IT, THEN THE OUTPUT MUST BE "I D_I-K" IF L-1-I IS EVEN
OR "I D_I-(B+1-K)" IF L-1-I IS ODD.
*/