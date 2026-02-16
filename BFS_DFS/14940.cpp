#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
#define X first
#define Y second
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0);
typedef long long ll;

int N, M;
int board[1004][1004];
int dist[1004][1004];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
    FIO;

    cin >> N >> M;

    queue<pair<int, int>> q;


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dist[i][j] = -1; // 못가는 땅
            cin >> board[i][j];
            if (board[i][j] == 2) {
                q.push({ i,j });
                dist[i][j] = 0;
            }
            else if (board[i][j] == 0) {
                dist[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        auto cur = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (board[nx][ny] != 1) continue;
            if (dist[nx][ny] > 0) continue;

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({ nx,ny });
        }
    }
   
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
  
   
    return 0;
}

