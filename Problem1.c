#include <stdio.h>

int main() {
    int N;
    char plan;
    int x = 1, y = 1;
    int nx = x, ny = y;

    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { -1, 1, 0, 0 };
    char move[4] = { 'L', 'R', 'U', 'D' };

    scanf("%d", &N);
    getchar();

   
    while (1) {
        scanf("%c", &plan);

        if (plan == '\n') {
            break;
        }

        for (int i = 0; i < 4; i++) {
            if (plan == move[i]) {
                nx = x + dx[i];
                ny = y + dy[i];
                break;
            }
        }
        if (nx < 1 || ny < 1 || nx > N || ny > N) {
            continue;
        }
        x = nx;
        y = ny;
    }
    printf("%d %d\n", x, y);

    return 0;
}