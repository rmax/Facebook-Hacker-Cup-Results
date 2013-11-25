#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Player {
    string name;
    int shotPercentage, height, minutesPlayed, draftNumber;
};

int t, n, m, p, n1, n2;
Player pl[30], team1[15], team2[15], onField[30];

bool cmpRate(const Player &pl1, const Player &pl2) {
    return (pl1.shotPercentage > pl2.shotPercentage) ||
           ((pl1.shotPercentage == pl2.shotPercentage) &&
            (pl1.height > pl2.height));
}

bool cmpMinPlayed(const Player &pl1, const Player &pl2) {
    return (pl1.minutesPlayed > pl2.minutesPlayed) ||
           ((pl1.minutesPlayed == pl2.minutesPlayed) &&
            (pl1.draftNumber > pl2.draftNumber));
}

bool cmpName(const Player &pl1, const Player &pl2) {
    return pl1.name < pl2.name;
}

void solveTest(int testNumber) {
    Player tmp;
    cin >> n >> m >> p;
    for (int i = 0; i < n; i++) {
        pl[i].minutesPlayed = 0;
        cin >> pl[i].name >> pl[i].shotPercentage >> pl[i].height;
    }
    sort(pl, pl + n, cmpRate);
    n1 = n2 = 0;
    for (int i = 1; i <= n; ++i) {
        pl[i - 1].draftNumber = i;
        if (i % 2 == 1) team1[n1++] = pl[i - 1];
        else team2[n2++] = pl[i - 1];
    }
    for (int i=0; i<p; i++) {
        onField[i] = team1[i];
        onField[i + p] = team2[i];
    }
    while (m--) {
        for (int i = 0; i < 2 * p; ++i) ++onField[i].minutesPlayed;
        if ((n + 1) / 2 > p) {
            sort(onField, onField + p, cmpMinPlayed);
            sort(team1 + p, team1 + n1, cmpMinPlayed);
            tmp = onField[0];
            onField[0] = team1[n1 - 1];
            team1[n1 - 1] = tmp;
        }
        if (n / 2 > p) {
            sort(onField + p, onField + 2 * p, cmpMinPlayed);
            sort(team2 + p, team2 + n2, cmpMinPlayed);
            tmp = onField[p];
            onField[p] = team2[n2 - 1];
            team2[n2 - 1] = tmp;
        }
    }
    sort(onField, onField + 2 * p, cmpName);
    cout << "Case #" << testNumber << ": ";
    for (int i = 0; i < 2 * p; ++i)
        cout << onField[i].name << ' ';
    cout << endl;
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        solveTest(i);
    }
    return 0;
}
