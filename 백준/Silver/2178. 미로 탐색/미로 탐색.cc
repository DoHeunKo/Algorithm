#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
using namespace std;

int n, m,y,x;

const int max_n = 104;
int a[max_n][max_n];
int visited[max_n][max_n];

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

bool inRange(int y, int x) {
    return y >= 0 && y < n&& x >= 0 && x < m;
}

int main() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &a[i][j]);
        }
    }

    queue<pair<int, int>> q;
    int sy = 0;
    int sx = 0;
    visited[sy][sx] = 1;
    q.push({ sy,sx });
    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!inRange(ny, nx) || visited[ny][nx] || a[ny][nx] == 0)continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ ny,nx });
        }
    }

    cout << visited[n - 1][m - 1] << '\n';

    return 0;
}