#include <bits/stdc++.h>
#define pb push_back
#define fore(i, a, b) for (int i = a, ggdem = b; i < ggdem; ++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(), x.end()
#define FIN                                                                    \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

optional<vector<string>> solve(ull k, string q) {

  set<char> found;

  vector<string> ans;

  for (char c : q) {
    if (found.size() < k && found.find(c) == found.end()) {
      ans.push_back("");
      found.insert(c);
    }

    ans.back() += c;
  }

  if (found.size() < k) {
    return {};
  } else {
    return ans;
  }
}

int main(void) {
  FIN;
  ull k;
  cin >> k;
  string q;
  cin >> q;

  optional<vector<string>> ans = solve(k, q);

  if (ans.has_value()) {
    cout << "YES\n";
    for (string s : ans.value()) {
      cout << s << '\n';
    }
  } else {
    cout << "NO\n";
  }

  /*     set<char> let;
    fore(i, 0, SZ(q))
    {
        let.insert(q[i]);
    }
    if (SZ(let) < k)
    {
        cout << "NO\n";
        return 0;
    }
    set<char> new_let;
    new_let.insert(q[0]);
    for (auto i : let)
    {
        new_let.insert(i);
        if (SZ(new_let) == k)
            break;
    }
    string aux = "";
    aux += q[0];
    vector<string> ans;
    set<char> alr;
    alr.insert(q[0]);
    fore(i, 1, SZ(q))
    {
        if (new_let.count(q[i]))
        {
            ans.pb(aux);
            aux = "";
            aux += q[i];
            alr.insert(q[i]);
        }
        else
        {
            aux += q[i];
        }
    }
    ans.pb(aux);
    cout << "YES\n";
    for (auto i : ans)
    {
        cout << i << "\n";
    } */
  return 0;
}