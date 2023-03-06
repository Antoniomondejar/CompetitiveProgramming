#include <bits/stdc++.h>
using namespace std;
#include <math.h>

int main(void){
    set<pair<int,int>> test;
    test.insert(make_pair(2,3));
    test.insert(make_pair(2,1));
    test.insert(make_pair(2,6));
    test.insert(make_pair(1,4));
    test.insert(make_pair(1,1));
    std::_Rb_tree_const_iterator<std::pair<int, int>> front;
    for(int i = 0; i < 5; ++i){
        front = test.begin();
        cout << front->first << " " << front->second << endl; // Testing how set data structure orders the pairs.
        test.erase(make_pair(front->first, front->second));
    }
    return 0;
}