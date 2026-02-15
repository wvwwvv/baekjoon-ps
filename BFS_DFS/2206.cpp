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
string board[1004];
int dist[1004][1004][2]; //x,y,부순횟수
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main() {
    FIO;

    cin >> N >> M;

    for (int i = 0; i < N; i++) cin >> board[i];

    dist[0][0][0] = 1;
    queue<tuple<int, int, int>> q;

    q.push({0,0,0}); // 시작점 0,0 으로 간주, 도착지는 board[N-1][M-1]

    while (!q.empty()) {
        auto [x, y, broken] = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            // 방문하지 않은 0
            if (board[nx][ny] == '0' && dist[nx][ny][broken] == 0) {
                dist[nx][ny][broken] = dist[x][y][broken] + 1;
                q.push({ nx,ny,broken });
            }

            // 벽을 만났고 부순 기록이 없으며 부수고이동한 적이 없는 경우
            if (board[nx][ny] == '1' && dist[nx][ny][1] == 0 && broken == 0) {
                dist[nx][ny][broken + 1] = dist[x][y][broken] + 1;
                q.push({ nx,ny,broken + 1 });
            }
        }
    }

    int result = -1;

    int re1 = dist[N - 1][M - 1][0];
    int re2 = dist[N - 1][M - 1][1];

    if (re1 != 0 && re2 != 0) {
        result = min(re1, re2);
    }
    else if (re1 != 0 && re2 == 0) {
        result = re1;
    }
    else if (re1 == 0 && re2 != 0) {
        result = re2;
    }

    cout << result;

   
    return 0;
}


// - boj 1162 번을 풀고 옛날에 못푼 문제가 생각나서 풀어보았다
// - 벽을 부쉈는지를 저장하는 정보를 dist 와 q에 추가한다
// - 기본 로직을 따라 q에 push 하는 것 뒤에, “벽을 부술 수 있는 상황이면 부수고 이동한다”의 조건부 로직을 적용해 q에 push한다