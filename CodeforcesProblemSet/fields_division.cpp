#include <bits/stdc++.h>
using namespace std;

#define ANA 2
#define BOB 3

int main(void){
    int N, M;
    cin >> N >> M;
    int vertex, neighbour;
    vector<int> graph[N];
    for(int i = 0; i < M; ++i){
        cin >> vertex >> neighbour;
        graph[vertex-1].push_back(neighbour-1);
        graph[neighbour-1].push_back(vertex-1);
    }
    int *visited_fields = (int *) calloc(N, sizeof(int));
    visited_fields[N-1] = ANA;
    visited_fields[N-2] = BOB;

    queue<int> bfs_queue;
    int current_vertex, current_neighbour;
    bfs_queue.push(N-2);
    while(bfs_queue.size()>0){
        current_vertex = bfs_queue.front();
        bfs_queue.pop();
        for(int i = 0; i < graph[current_vertex].size(); ++i){
            current_neighbour = graph[current_vertex].at(i);
            if (visited_fields[current_neighbour] == 0){
                visited_fields[current_neighbour] = BOB;
                bfs_queue.push(current_neighbour);
            }
        }
    }
    for(int i = 0; i < N; ++i){
        if(visited_fields[i] == 0 || visited_fields[i] == ANA)
            cout << "A";
        else
            cout << "B";
    }
    cout << endl;
    return 0;
}