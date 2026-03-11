#include <stdio.h>

#define INFINITE 1000000000 


int main() {
    int n, m,i, j, a, b;
    int city[105][105];
    int x, k, temp;

    scanf("%d %d", &n, &m);
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j) 
                city[i][j] = 0;
            else 
                city[i][j] = INFINITE;
        }
    }

    for (i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        city[a][b] = 1;
        city[b][a] = 1;
    }


    scanf("%d %d", &x, &k);
    for (temp = 1;temp <= n; temp++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (city[i][temp] + city[temp][j] < city[i][j]) {
                    city[i][j] = city[i][temp] + city[temp][j];
                }
            }
        }
    }

    int distance = city[1][x] + city[x][k];
    if (distance >= INFINITE) {
        printf("-1\n");
    }
    else {
        printf("%d\n", distance);
    }
    return 0;

}
