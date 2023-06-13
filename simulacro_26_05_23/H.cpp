#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

bool is_number(char c) {
  return c>='0' && c<='9';
}

ll to_number(char c) {
  return (ll)c-'0';
}

int main(void){FIN;
  string s; cin>>s;
  int n=s.length();

  ll ans=0, x=0;
  ll d=1, p=0;
  bool mil=0;
  for(int i=n-1; i>=0; --i) {
    if(is_number(s[i])) {
      x+=to_number(s[i])*d;
      p++; // cuenta los digitos antes del punto
      d*=10;
    } else if(s[i]=='.') {
      if(p==2) mil=1;
    } else {
      if(mil) ans+=x;
      else ans+=100*x;
      p=0; x=0; d=1; mil=0;
    }
  }
  
  ll w,e,r,t;
  t=ans%100;  // decimales
  ans/=100;
  r=ans%1000; // centenares
  ans/=1000;
  e=ans%1000; // miles
  ans/=1000;
  w=ans%1000; // millares

  bool ceros=0;
  if(w) {
    cout<<w<<'.';
    ceros=1;
  }
  if(e) {
    if(ceros && e<10) {
      cout<<"00";
    } else if(ceros && e<100) {
      cout<<"0";
    }
    ceros=1;
    cout<<e<<'.';
  } else {
    if(ceros) {
      cout<<"000.";
    }
  }
  if(r) {
    if(ceros && r<10) {
      cout<<"00";
    } else if(ceros && r<100) {
      cout<<"0";
    }
    cout<<r;
  } else {
    if(ceros) {
      cout<<"000";
    } else {
      cout<<r;
    }
  }
  if(t) {
    cout<<'.';
    if(t<10) cout<<"0";
    cout<<t;
  }

  return 0;
}