#include <stdio.h>

int N, M;
int ice[1000][1000];

int dfs(int x, int y) {
    if (x <= -1 || x >= N || y <= -1 || y >= M) {
        return 0;
    }

    if (ice[x][y] == 0) {
        ice[x][y] = 1;

        dfs(x - 1, y); // 상
        dfs(x + 1, y); // 하
        dfs(x, y - 1); // 좌
        dfs(x, y + 1); // 우

        return 1;
    }

    return 0;
}

int main() {
    printf("N과 M 입력 : ");
    scanf("%d %d", &N, &M);

  
    for (int i = 0; i < N; i++) {
        char row[1000];
        scanf("%s", row); 

        for (int j = 0; j < M; j++) {
            ice[i][j] = row[j] - '0';
        }
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (dfs(i, j) == 1) {
                result += 1;
            }
        }
    }

    printf("%d\n", result);

    return 0;
}