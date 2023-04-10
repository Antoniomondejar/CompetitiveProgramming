#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct classcomp {
    bool operator() (const pair<ll,ll>&x, const pair<ll, ll> &y) const {
        if (x.first > y.first)
            return x.first > y.first;
        else if(x.first == y.first && x.second < y.second)
            return 1;
        return 0;
    }
};

// primera coordenada tiene el largo del subarbol con la raiz en ese hijo y segunda coordenada el indice del hijo
vector<set<pair<ll,ll>, classcomp>> vertex_heavy_sons;
//primera coordenada tiene la importancia de cada nodo, segunda coordenada el largo del subarbol con raiz ese nodo.
vector<pair<ll, ll>> vertex_importance;
// vector de vecinos y segunda coordenada el padre del nodo.
vector<pair<vector<ll>,ll>> graph;

pair<ll,ll> dfs(ll current_vertex, ll father, ll *a){
    ll importance = a[current_vertex];
    ll degree = graph.at(current_vertex).first.size();
    ll neighbour; ll subtree_size = 1;
    pair<ll,ll> result_neighbour;
    for(int i = 0; i < degree; ++i){
        neighbour = graph.at(current_vertex).first.at(i);
        if(neighbour!=father){
            result_neighbour = dfs(neighbour, current_vertex, a);
            subtree_size += result_neighbour.second;
            importance += result_neighbour.first;
            vertex_heavy_sons.at(current_vertex).insert(make_pair(result_neighbour.second, neighbour));
        }
    }
    vertex_importance.at(current_vertex) = make_pair(importance, subtree_size);
    return make_pair(importance, subtree_size);
}



int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m, x1, x2;
    cin >> n >> m;
    ll *a = (ll *)calloc(n, sizeof(ll));
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        graph.push_back(make_pair(vector<ll>{},0));
        vertex_heavy_sons.push_back(set<pair<ll,ll>, classcomp>{});
        vertex_importance.push_back(make_pair(0,0));
    }
    for(int i = 0; i < n-1; ++i){
        cin >> x1 >> x2;
        graph.at(x1-1).first.push_back(x2-1);
        graph.at(x2-1).first.push_back(x1-1);
    }
    // Bfs para encontrar los padres de cada nodo.
    vector<int> visited(n,0);
    queue<ll> bfs;
    ll current_vertex = 0; ll degree, neighbour, heavy_son_index, size_heavy_son, father_index;
    bfs.push(current_vertex);
    visited.at(0) = 1;
    while(bfs.size()>0){
        current_vertex = bfs.front();
        bfs.pop();
        degree = graph.at(current_vertex).first.size();
        for(int i = 0; i < degree; ++i){
            neighbour = graph.at(current_vertex).first.at(i);
            if (neighbour != graph.at(current_vertex).second) graph.at(neighbour).second = current_vertex;
            if (visited.at(neighbour)==0){
                visited.at(neighbour) = 1;
                bfs.push(neighbour);
            }
        }
    }
    std::_Rb_tree_const_iterator<std::pair<ll, ll>> heavy_son;
    dfs(0, 0, a);
    for(int i = 0; i < m; ++i){
        cin >> x1 >> x2;
        --x2;
        if(x1 == 1){
            cout << vertex_importance.at(x2).first << "\n";
        } else if (vertex_heavy_sons.at(x2).size()>0){
            father_index = graph.at(x2).second;
            heavy_son = vertex_heavy_sons.at(x2).begin();
            size_heavy_son = heavy_son->first;
            heavy_son_index = heavy_son->second;
            graph.at(heavy_son_index).second = father_index;
            graph.at(x2).second = heavy_son_index;
            vertex_importance.at(x2).first -= vertex_importance.at(heavy_son_index).first;
            vertex_heavy_sons.at(x2).erase(make_pair(size_heavy_son, heavy_son_index));
            vertex_heavy_sons.at(father_index).erase(make_pair(vertex_importance.at(x2).second, x2));
            vertex_importance.at(heavy_son_index).first += vertex_importance.at(x2).first;
            vertex_importance.at(x2).second -= size_heavy_son;
            vertex_importance.at(heavy_son_index).second += vertex_importance.at(x2).second;
            vertex_heavy_sons.at(father_index).insert(make_pair(vertex_importance.at(heavy_son_index).second, heavy_son_index));
            vertex_heavy_sons.at(heavy_son_index).insert(make_pair(vertex_importance.at(x2).second, x2));
        }
    }
    return 0;
}