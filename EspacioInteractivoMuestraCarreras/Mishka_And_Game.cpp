#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int mishka_score = 0;
    int chris_score = 0;

    for (int i = 0; i < n; ++i) {
        int mishka_dice, chris_dice;
        cin >> mishka_dice >> chris_dice;

        if (mishka_dice > chris_dice){
            ++mishka_score;
        } else if (chris_dice > mishka_dice) {
            ++chris_score;
        }
    }

    if (mishka_score > chris_score) {
        cout << "Mishka\n";
    } else if (chris_score > mishka_score) {
        cout << "Chris\n";
    } else {
        cout << "Friendship is magic!^^\n";
    }

    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/