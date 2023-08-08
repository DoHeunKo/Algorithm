#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int max_n = 104;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };

int a[max_n][max_n];
int visited[max_n][max_n];

int m, n, k;
int sy, sx, ey, ex;
int ret;
int cnt;
vector<int> val;
bool isRange(int y, int x) {
    return y >= m || y < 0 || x >= n || x < 0;
}

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (isRange(ny, nx))continue;
        if (a[ny][nx] && !visited[ny][nx]) {
            cnt++;
            dfs(ny, nx);
        }
    }
}

int main() {

    cin >> m >> n >> k;


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 1;
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> sx >> sy >> ex >> ey;
        for (int j = sy; j <ey; j++) {
            for (int k =sx; k < ex; k++) {
                a[j][k] = 0;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1 && !visited[i][j]) {
                cnt = 1;
                dfs(i, j);
                ret++;
                val.push_back(cnt);
                
            }
        }
    }
    sort(val.begin(), val.end());
    cout << ret << "\n";
    for (int ele : val) {
        cout << ele << ' ';
    }
    cout << "\n";
    return 0;
}