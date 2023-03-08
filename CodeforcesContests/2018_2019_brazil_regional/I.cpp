#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N, M, input;
    long long iteration_counter = 0;
    cin >> N >> M;
    int L;
    cin >> L;
    set<int> current_lights_lit;
    for(int i = 0; i<L; ++i){
        cin >> input;
        current_lights_lit.insert(input);
    }
    int switches[N][M+1];
    for(int i = 0; i < N; ++i){
        cin >> switches[i][0];
        L = switches[i][0];
        for(int j = 1; j <= L; ++j){
            cin >> switches[i][j];
        }
    }
    // set<set<int>> initial_states;
    // long long initial_states_size = 0;
    bool lights_out = current_lights_lit.size() == 0; bool imposible = false;
    while(!lights_out && !imposible){
        // initial_states_size = initial_states.size();
        // initial_states.insert(current_lights_lit);
        // if (initial_states_size == initial_states.size()){
        //     imposible = true;
        //     break;
        // }
        for(int i = 0; i < N && !lights_out && !imposible; ++i){
            ++iteration_counter;
            if (iteration_counter == 2*N+1){
                imposible = true;
                break;
            }
            L = switches[i][0];
            for(int j = 1; j <= L; ++j){
                if(current_lights_lit.find(switches[i][j]) == current_lights_lit.end()){
                    current_lights_lit.insert(switches[i][j]);
                } else {
                    current_lights_lit.erase(switches[i][j]);
                }
            }
            if(current_lights_lit.size() == 0){
                lights_out = true;
                break;
            }
        }
    }
    if(lights_out){
        cout << iteration_counter << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}