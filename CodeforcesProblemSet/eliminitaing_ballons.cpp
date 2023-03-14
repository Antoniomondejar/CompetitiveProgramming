#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    std::_Rb_tree_iterator<std::pair<const int, int>> element;
    map<int,int> arrows;
    int positions[N];
    int arrows_qty = 1;
    for(int i = 0; i < N; ++i)
        cin >> positions[i];
    if (positions[0] > 1)
        arrows.insert(make_pair((positions[0]-1),1));
    for(int i = 1; i < N; ++i){
        element = arrows.find(positions[i]);
        if(element == arrows.end()){
            ++arrows_qty;
            if (positions[i]>1){
                element = arrows.find(positions[i]-1);
                if(element == arrows.end())
                    arrows.insert(make_pair((positions[i]-1),1));
                else
                    ++element->second;
            }
        } else {
            if(element->second == 1)
                arrows.erase(positions[i]);
            else
                --element->second;
            if (positions[i]>1){
                element = arrows.find(positions[i]-1);
                if(element == arrows.end())
                    arrows.insert(make_pair((positions[i]-1),1));
                else
                    ++element->second;
            }
        }
    }
    cout << arrows_qty << endl;
    return 0;
}