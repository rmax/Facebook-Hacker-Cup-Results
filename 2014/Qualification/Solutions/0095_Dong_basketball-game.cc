#include <stdio.h>
#include <string.h>
#include <algorithm>

struct player {
    char name[30];
    int shot_percentage;
    int height;
    int time_played;
    int draft_number;
};

int n, m, p;
player players[30];

int n1, n2;
player team1[30];
player team2[30];

bool draft_order(const player &p1, const player &p2)
{
    if (p1.shot_percentage != p2.shot_percentage)
        return p1.shot_percentage > p2.shot_percentage;
    return p1.height > p2.height;
}

bool substitute_order(const player &p1, const player &p2)
{
    if (p1.time_played != p2.time_played)
        return p1.time_played < p2.time_played;
    return p1.draft_number < p2.draft_number;
}

bool print_order(const player &p1, const player &p2)
{
    return strcmp(p1.name, p2.name) < 0;
}

void substitute(player *team, int team_size)
{
    for (int i = 0; i < p; i++) team[i].time_played++;

    std::sort(team, team + p, substitute_order);
    std::sort(team + p, team + team_size, substitute_order);

    if (p < team_size)
        std::swap(team[p - 1], team[p]);
}

int main()
{
    int num_tests; scanf("%d", &num_tests);

    for (int test = 0; test < num_tests; test++) {
        scanf("%d%d%d", &n, &m, &p);
        for (int i = 0; i < n; i++) {
            scanf("%s%d%d", &players[i].name, &players[i].shot_percentage, &players[i].height);
            players[i].time_played = 0;
        }

        std::sort(players, players + n, draft_order);

        n1 = n2 = 0;
        for (int i = 0; i < n; i++) {
            players[i].draft_number = i;
            if (i % 2 == 0) team1[n1++] = players[i]; else team2[n2++] = players[i];
        }

        for (int time = 0; time < m; time++) {
            substitute(team1, n1);
            substitute(team2, n2);
        }

        int n_on_court = 0;
        player on_court[30];

        for (int i = 0; i < p; i++) on_court[n_on_court++] = team1[i];
        for (int i = 0; i < p; i++) on_court[n_on_court++] = team2[i];
        std::sort(on_court, on_court + n_on_court, print_order);

        printf("Case #%d:", test + 1);
        for (int i = 0; i < n_on_court; i++) printf(" %s", on_court[i].name);
        putchar('\n');
    }

    return 0;
}
