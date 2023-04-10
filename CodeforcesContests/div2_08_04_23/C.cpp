#include <bits/stdc++.h>
using namespace std;

struct classcomp {
    bool operator() (const pair<int,int>&x, const pair<int, int> &y) const {
        if (x.first > y.first)
            return x.first > x.second;
        else if(x.first == y.first && x.second < y.second)
            return 1;
        return 0;
    }
};


vector<set<pair<int,int>, classcomp>> vertex_heavy_sons;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // return 0;
    vertex_heavy_sons.push_back(set<pair<int,int>, classcomp>{});
    vertex_heavy_sons.at(0).insert(make_pair(100,2));
    vertex_heavy_sons.at(0).insert(make_pair(100,5));
    vertex_heavy_sons.at(0).insert(make_pair(104,7));
    vertex_heavy_sons.at(0).insert(make_pair(104,6));
    cout << "hoalsa";
    for(int i = 0; i < 4; ++i){
        std::_Rb_tree_const_iterator<std::pair<int, int>> heavy_son = vertex_heavy_sons.at(0).begin();
        cout << heavy_son->first << " " << heavy_son->second << "\n";
        vertex_heavy_sons.at(0).erase(make_pair(heavy_son->first,heavy_son->second));
    }
    return 0;
}