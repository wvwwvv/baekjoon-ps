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

int N, M; // 세로, 가로
string board[102];
vector<pair<int, pair<int, int>>> adj[102][102];
int d[102][102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
const int INF = 0x3f3f3f3f;


int main() {
    FIO;

    cin >> M >> N;

    for (int i = 0; i < N; i++) cin >> board[i]; // 0 빈방

    // (a,b) -> (다음 노드) 로 가는데 드는 비용은 0 or 1 이고,
    // (N,M) 까지 도착하는데 드는 최소 비용

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            //i,j 상하좌우 board 범위 맞는지 확인하고 adj에 push
            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

                int price = 0; 
                if (board[nx][ny] == '1') price = 1;
                adj[i][j].push_back({ price, {nx , ny} });
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            d[i][j] = INF;
        }
    }

    d[0][0] = 0;

    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

    pq.push({ 0, { 0,0 } });

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();

        if (d[cur.Y.X][cur.Y.Y] != cur.X) continue;

        for (auto nxt : adj[cur.Y.X][cur.Y.Y]) {
            if (d[nxt.Y.X][nxt.Y.Y] <= d[cur.Y.X][cur.Y.Y] + nxt.X) continue;

            d[nxt.Y.X][nxt.Y.Y] = d[cur.Y.X][cur.Y.Y] + nxt.X;
            pq.push({ d[nxt.Y.X][nxt.Y.Y], {nxt.Y.X, nxt.Y.Y} });
        }
    }

    cout << d[N-1][M-1];
    
   
   return 0;
}


// - 이게 될까 싶은 마음으로 pq와 adj 사용했는데 답은 나옴
// - 주의할 점은 spring은 index 0부터 시작한다는 점
//     - 보통 다익스트라의 노드는 1부터 시작하는데 이 문제에서 헷갈리지 말자