#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
    'n','o','p','q','r','s','t','u','v','w','x','y','z'};
    while(t--){
        int n, k, pairs;
        string word;
        cin >> n >> k >> word;
        std::_Rb_tree_iterator<std::pair<const char, std::pair<int, int>>> counter;
        map <char,pair<int,int>> character_counter; // (lowercase, uppercase)
        pairs = 0;

        for(int i = 0; i < 26; ++i)
            character_counter.insert(make_pair(alphabet[i], make_pair(0,0)));
        
        for(int i = 0; i < n; ++i){
            counter = character_counter.find(tolower(word[i]));
            if(isupper(word[i])){
                ++counter->second.second;
            } else {
                ++counter->second.first;
            }
        }

        int uppercase_counter, lowercase_counter;
        for(int i = 0; i < 26 && k > 0; ++i){
            counter = character_counter.find(alphabet[i]);
            uppercase_counter = counter->second.second;
            lowercase_counter = counter->second.first;
            if(lowercase_counter >= uppercase_counter){
                while(lowercase_counter-uppercase_counter>1 && k>0){
                    --lowercase_counter;
                    ++uppercase_counter;
                    --k;
                }
                counter->second = make_pair(lowercase_counter,uppercase_counter);
            }
            else {
                while(uppercase_counter-lowercase_counter>1 && k>0){
                    --uppercase_counter;
                    ++lowercase_counter;
                    --k;
                }
                counter->second = make_pair(lowercase_counter,uppercase_counter);
            }
        }

        for(int i = 0; i < 26; ++i){
            counter = character_counter.find(alphabet[i]);
            pairs = pairs + min(counter->second.first, counter->second.second);
        }
        cout << pairs << endl;
    }
    return 0;
}