#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        std::_Rb_tree_iterator<std::pair<const long long, long long>> card, next_max_bonus;
        map<long long,long long> bonus_cards;
        long long input_card;
        long long max_bonus = 0; long long points = 0;
        for(int i = 0; i < n; ++i){
            cin >> input_card;
            if (input_card){
                max_bonus = max(max_bonus, input_card);
                card = bonus_cards.find(input_card);
                if(card==bonus_cards.end())
                    bonus_cards.insert(make_pair(input_card,1));
                else
                    ++card->second;
            } else {
                points = points + max_bonus;
                card = bonus_cards.find(max_bonus);
                if (card == bonus_cards.end())
                    continue;
                if (card->second == 1){
                    bonus_cards.erase(max_bonus);
                    next_max_bonus = bonus_cards.lower_bound(max_bonus);
                    // cout << next_max_bonus->first << endl;
                    if (next_max_bonus == bonus_cards.begin())
                        max_bonus = 0;
                    else {
                        --next_max_bonus;
                        max_bonus = next_max_bonus->first;
                    }
                } else {
                    --card->second;
                }
            }
        }
        cout << points << endl;
    }
    return 0;
}