#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

typedef struct {
    string name;
    int rate;
    int percentage;
    int height;
    int time;
} player;

bool rateCompare(const player& firstElem, const player& secondElem) {
    if (firstElem.percentage == secondElem.percentage)
        return firstElem.height > secondElem.height;
    else return firstElem.percentage > secondElem.percentage;
}

bool fieldCompare(const player& firstElem, const player& secondElem) {
    if (firstElem.time == secondElem.time)
        return firstElem.rate < secondElem.rate;
    else return firstElem.time < secondElem.time;
}

int main() {
    string nm;
    int T, N, M, P, pc, hg, tm;
    vector<player> all;
    vector<string> answer;

    cin >> T;

    for (int i = 0; i < T; i++) {

        vector<player> fieldFirst; vector<player> fieldFirstRest;
        vector<player> fieldSecond; vector<player> fieldSecondRest;

        cin >> N >> M >> P;
        all.clear();
        for (int j = 0; j < N; j++) {
            cin >> nm >> pc >> hg;
            player temp; // Player
            temp.name = nm;
            temp.percentage = pc;
            temp.height = hg;
            temp.time = 0;
            temp.rate = 0;
            all.push_back(temp);
        }
        sort(all.begin(), all.end(), rateCompare); // sort

        answer.clear();
        for (int j = 0; j < all.size(); j++) { // divide into two team
            all[j].rate= (j+1);
            if (j % 2 == 0) {
                if (fieldFirst.size() != P) fieldFirst.push_back(all[j]);
                else fieldFirstRest.push_back(all[j]);
            } else {
                if (fieldSecond.size() != P) fieldSecond.push_back(all[j]);
                else fieldSecondRest.push_back(all[j]);
            }
        }

        int time = 0;
        while (time < M) {
            // rotate all players in field
            for (int j = 0; j < fieldFirst.size(); j++) fieldFirst[j].time += 1;
            for (int j = 0; j < fieldSecond.size(); j++) fieldSecond[j].time += 1;

            sort (fieldFirst.begin(), fieldFirst.end(), fieldCompare);
            sort (fieldSecond.begin(), fieldSecond.end(), fieldCompare);

            if (fieldFirstRest.size() != 0) {
                sort(fieldFirstRest.begin(), fieldFirstRest.end(), fieldCompare);
                player temp_player = fieldFirst[fieldFirst.size() - 1];
                fieldFirst[fieldFirst.size() - 1] = fieldFirstRest[0];
                fieldFirstRest[0] = temp_player;
            }
            if (fieldSecondRest.size() != 0) {
                sort(fieldSecondRest.begin(), fieldSecondRest.end(), fieldCompare);
                player temp_player = fieldSecond[fieldSecond.size() - 1];
                fieldSecond[fieldSecond.size() - 1] = fieldSecondRest[0];
                fieldSecondRest[0] = temp_player;
            }
            time++;
        }

        for (int j = 0; j < fieldFirst.size(); j++) answer.push_back(fieldFirst[j].name);
        for (int j = 0; j < fieldSecond.size(); j++) answer.push_back(fieldSecond[j].name);

        sort(answer.begin(), answer.end());
        cout << "Case #" << (i+1) << ": ";
        for (int j = 0; j < answer.size(); j++) {
            cout << answer[j];
            if (j != answer.size() - 1) cout << " ";
            else cout << endl;
        }
    }

    return 0;
}
/** Created by freedomofkeima 2013 */
