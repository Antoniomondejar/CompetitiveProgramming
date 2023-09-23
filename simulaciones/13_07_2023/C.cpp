#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggmat=b;i<ggmat;++i)
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef vector<vector<double> > Matrix;
Matrix ones(int n) {
	Matrix r(n,vector<double>(n));
	fore(i,0,n)r[i][i]=1;
	return r;
}
Matrix multiply(Matrix a, Matrix b) {
	int n=SZ(a),m=SZ(b[0]),z=SZ(a[0]);
	Matrix r(n,vector<double>(m));
	fore(i,0,n)fore(j,0,m)fore(k,0,z)
		r[i][j]+=a[i][k]*b[k][j];
	return r;
}
Matrix add(Matrix a, Matrix b){
    int n=SZ(a), m=SZ(a[0]);
    Matrix r(n,vector<double>(m));
    fore(i,0,n){
        fore(j,0,m){
            r[i][j]=a[i][j]+b[i][j];
        }
    }
    return r;
}
Matrix be(Matrix b, ll e) {
	Matrix r=ones(SZ(b));
	while(e){if(e&1LL)r=multiply(r,b);b=multiply(b,b);e/=2;}
	return r;
}


Matrix sum(Matrix a, ll n){
    if(n==1)return add({{1,0},{0,1}},a);
    if(n&1){
        Matrix aux = sum(a,(n-1)/2);
        return add(add(aux,multiply(be(a,(n-1)/2),aux)),be(a,n));
    } else {
        Matrix aux = sum(a,n/2);
        return add(aux,multiply(be(a,n/2),aux));
    }
}

int main(){FIN;
    ll T;
    cin >> T;
    double pi = 3.14159265358979323846;
    while(T--) {
        int n;
        cout << setprecision(8);
        double a,l;cin>>a>>l>>n;
        Matrix a_t = {{cos(a*2*pi/360),-sin(a*2*pi/360)},{sin(a*2*pi/360),cos(a*2*pi/360)}};
        Matrix b = {{l},{0}};
        Matrix res = multiply(sum(a_t,n),b);
        cout << res[0][0] << " " << res[1][0] << "\n";
        // cout << x << " " << y << "\n";
    }

    return 0;
}