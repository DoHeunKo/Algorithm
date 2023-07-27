#include<iostream>
#include<cstring>

using namespace std;

const int max_n = 104;
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };

int max_height;
int n;
int a[max_n][max_n];
int visited[max_n][max_n];
int temp[max_n][max_n];


bool isRange(int y, int x) {
    return y >= n || y < 0 || x >= n || x < 0;
}

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (isRange(ny, nx))continue;
        if (temp[ny][nx] && !visited[ny][nx]) {
            dfs(ny, nx);
        }
    }
    
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            
            if (max_height < a[i][j]) {
                max_height = a[i][j];
            }
        }
    }
    
    int ret = 0;
    
    for (int i = 0; i <= max_height; i++) {
        
        int cnt = 0;
        memset(visited, 0, sizeof(visited));
        memset(temp, 0, sizeof(temp));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (a[j][k] <= i) {
                    temp[j][k] = 0;
                }
                else {
                    temp[j][k] = 1;
                }
     
            }
        }
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (temp[j][k] == 1 && !visited[j][k]) {
                    cnt++;
                    dfs(j, k);
                }
            }
        }
        ret = max(ret, cnt);
        
        

    }
    cout << ret << "\n";

    return 0;;
}