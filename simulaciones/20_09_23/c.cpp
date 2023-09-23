#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define fore(i,a,b) for(int i=a,gmat=b;i<gmat;++i)
#define FIN ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//typedef vii vector<ll>
//typedef ii pair<ll,ll>
const ll NMAX = 1048576;

typedef ll tf;
typedef vector<tf> poly;


struct CD{
	double r,i;
	CD(double r=0, double i=0):r(r),i(i){}
	double real()const{return r;}
	void operator /=(const int c){r/=c,i/=c;}
};
CD operator *(const CD& a, const CD&b){
	return CD(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);
}
CD operator +(const CD&a, const CD&b){return CD(a.r+b.r,a.i+b.i);}
CD operator -(const CD&a, const CD&b){return CD(a.r-b.r,a.i-b.i);}
const double pi=acos(-1.0);

CD cp1[NMAX+9],cp2[NMAX+9];
int R[NMAX+9];
void dft(CD* a, int n, bool inv){
	fore(i,0,n)if(R[i]<i)swap(a[R[i]],a[i]);
	for(int m=2;m<=n;m*=2){
		double z=2*pi/m*(inv?-1:1);
		CD wi=CD(cos(z),sin(z));
		for(int j=0;j<n;j+=m){
			CD w(1);
			for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
				CD u=a[k];CD v=a[k2]*w;a[k]=u+v;a[k2]=u-v;w=w*wi;
			}
		}
	}
	if(inv)fore(i,0,n)a[i]/=n;
}


poly multiply(poly &p1, poly& p2){
	int n=p1.size()+p2.size()+1;
	int m=1,cnt=0;
	while(m<=n)m+=m,cnt++;
	//cout << '\n' << m << "\n";
	fore(i,0,m){R[i]=0;fore(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
	//cout << "haosa\n";
	fore(i,0,m)cp1[i]=0,cp2[i]=0;
	fore(i,0,p1.size())cp1[i]=p1[i];
	fore(i,0,p2.size())cp2[i]=p2[i];
	dft(cp1,m,false);dft(cp2,m,false);
	fore(i,0,m)cp1[i]=cp1[i]*cp2[i];
	dft(cp1,m,true);
	poly res;
	n-=2;
	fore(i,0,n)res.pb((tf)floor(cp1[i].real()+0.5));
	return res;
}

int main(){FIN;
	ll n,m;cin>>n;
	vector<ll> dis(NMAX/4);
	fore(i,0,n){
		ll x;cin>>x;
		dis[x]++;
	}
	//cout << dis.size()+dis.size()+1 << "\n";
	vector<ll> res = multiply(dis,dis);
	cin>>m;
	ll ans = 0;
	fore(i,0,m){
		ll x;cin>>x;
		if(res[x] || dis[x]) ++ans;
	}
	cout << ans << "\n";
	return 0;
}