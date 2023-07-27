#include<iostream>
#include<tuple>
#include<cstring>
using namespace std;

int t,cnt, n, m;
int px, py;
const int max_n = 54;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };

int a[max_n][max_n];
int visited[max_n][max_n];

bool isRange(int y, int x) {
    return y >= n || y < 0 || x >= m || x < 0;
}

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(isRange(ny,nx))continue;
        if (a[ny][nx] && !visited[ny][nx]) {
            dfs(ny, nx);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        cin >> m >> n >> cnt;
        
        for (int j = 0; j < cnt; j++) {
            cin >> px >> py;
            a[py][px] = 1;
        }

        int ret = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (a[j][k] && !visited[j][k]) {
                    ret++;
                    dfs(j, k);
                }
            }
        }
        cout << ret << "\n";
        memset(visited, 0, sizeof(visited));
        memset(a, 0, sizeof(a));
    }


    return 0;
}