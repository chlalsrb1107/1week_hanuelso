#include <stdio.h>

int n, m;
int maze[200][200]; 

typedef struct {
    int x;
    int y;
} Node;

Node queue[40000]; 
int front = 0;
int rear = 0;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void push(int x, int y) {
    queue[rear].x = x;
    queue[rear].y = y;
    rear++;
}

Node pop() {
    Node temp = queue[front];
    front++;
    return temp;
}

int isEmpty() {
    return front == rear; 
}

int bfs(int start_x, int start_y) {
    push(start_x, start_y);

    while (!isEmpty()) {
        Node current = pop();
        int x = current.x;
        int y = current.y;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (maze[nx][ny] == 0) {
                continue;
            }
            if (maze[nx][ny] == 1) {
                maze[nx][ny] = maze[x][y] + 1;
                push(nx, ny); 
            }
        }
    }
    return maze[n - 1][m - 1];
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }
    printf("%d\n", bfs(0, 0));

    return 0;
}