#include <stdio.h>

int N;
int cells[30][30];

int main()
{
    int num_tests; scanf("%d", &num_tests);

    for (int test = 0; test < num_tests; test++) {
        scanf("%d", &N);

        int top = N, bottom = 0;
        int left = N, right = 0;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                char ch; scanf(" %c", &ch);
                if (ch == '.')
                    cells[i][j] = 0;
                else {
                    cells[i][j] = 1;
                    if (i < top) top = i;
                    if (i > bottom) bottom = i;
                    if (j < left) left = j;
                    if (j > right) right = j;
                }
            }

        bool sq = true;

        for (int i = top; i <= bottom; i++)
            for (int j = left; j <= right; j++)
                if (cells[i][j] == 0)
                    sq = false;
        if (bottom - top != right - left)
            sq = false;

        printf("Case #%d: %s\n", test + 1, sq ? "YES" : "NO");
    }

    return 0;
}
