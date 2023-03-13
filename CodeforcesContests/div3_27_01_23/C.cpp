#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n, input, input2;
        cin >> n;
        int elements_in_front[n][3];
        int appeared[n];
        for(int i = 0; i < n; ++i){
            appeared[i] = 0;
            elements_in_front[i][0] = -1;
            elements_in_front[i][1] = -1;
            elements_in_front[i][2] = -1;
        }
        if(n>3){
            for(int i = 0; i < n; ++i){
                cin >> input;
                --input;
                for(int j = 0; j < n-2; ++j){
                    cin >> input2;
                    --input2;
                    appeared[input2] = 1;
                    if(elements_in_front[input][0]==-1){
                        elements_in_front[input][0] = input2;
                    } else if(elements_in_front[input][1] == -1) {
                        elements_in_front[input][1] = input2;
                    } else if(elements_in_front[input][2] == -1){
                        elements_in_front[input][2] = (elements_in_front[input][0]==input2 || elements_in_front[input][1]==input2)?
                                                    input2:elements_in_front[input][1];
                    }
                    input = input2;
                }
            }
            int first;
            for(int i = 0; i < n; ++i){
                if (appeared[i] == 0){
                    first = i;
                    cout << first + 1 << " ";
                    break;
                }
            }

            for(int i = 0; i < n-1; ++i){
                if (elements_in_front[first][0] == elements_in_front[first][1] ||
                    elements_in_front[first][0] == elements_in_front[first][2]){
                    cout << elements_in_front[first][0] + 1 << " ";
                    first = elements_in_front[first][0];
                } else {
                    cout << elements_in_front[first][1] + 1 << " ";
                    first = elements_in_front[first][1];
                }
            }
            cout << endl;
        } else {
            int appearences[3];
            appearences[0] = 0;
            appearences[1] = 0;
            appearences[2] = 0;
            for(int i = 0; i < 3; ++i){
                for(int j = 0; j < 1; ++j){
                    cin >> input;
                    ++appearences[input-1];
                }
                cin >> input;
            }
            if(appearences[0] == 0 && appearences[1] == 1 && appearences[2] == 2)
                cout << "3 2 1" << endl;
            else if(appearences[0] == 0 && appearences[1] == 2 && appearences[2] == 1)
                cout << "3 1 2" << endl;
            else if(appearences[0] == 1 && appearences[1] == 0 && appearences[2] == 2)
                cout << "2 3 1" << endl;
            else if(appearences[0] == 1 && appearences[1] == 2 && appearences[2] == 0)
                cout << "2 1 3" << endl;
            else if(appearences[0] == 2 && appearences[1] == 0 && appearences[2] == 1)
                cout << "1 2 3" << endl;
            else if(appearences[0] == 2 && appearences[1] == 1 && appearences[2] == 0)
                cout << "1 2 3" << endl;
        }
   }
   return 0;
}