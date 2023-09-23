#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int police_available = 0;
    int crimes_untreated = 0;

    for (int i = 0; i < n; ++i) {
        int event;
        cin >> event;

        if (event == -1) {
            if(police_available > 0)
                --police_available;
            else
                ++crimes_untreated;
        } else {
            police_available += event;
        }
    }

    cout << crimes_untreated << '\n';

    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/