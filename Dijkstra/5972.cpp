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

int N, M; // N:노드  M;간선
vector<pair<int, int>> adj[50005];
const int INF = 0x3f3f3f3f;
int d[50005];
bool vis[20005];

int main() {
    FIO;

    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ c,b });
        adj[b].push_back({ c,a });
    }

    for (int i = 1; i <= N; i++) d[i] = INF; // 최소비용테이블 초기화

    d[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0,1 }); // 시작점

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();

        if (d[cur.Y] != cur.X) continue; // 최소비용테이블과 큐에서 꺼낸 노드(까지의)의 비용이 다르면 더이상 갱신할 필요 없다

        for (auto nxt : adj[cur.Y]) {

            if (nxt.X == 0 && vis[nxt.Y]==false) {
                vis[nxt.Y] = true;
                d[nxt.Y] = d[cur.Y];
                pq.push({ d[nxt.Y], nxt.Y });
                continue;
            }
            

            if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue; // todo 간선 비용 0이 존재하는데, 등호가 들어가면 해당 루트는 스킵되는데..?

            //여기까지 왔다는건 최소비용테이블 값 갱신하고 pq에 push해야한다는 의미
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({ d[nxt.Y], nxt.Y });
        }
    }

    cout << d[N];





    return 0;
}


// - 양방향문제를 단방향처럼 입력받도록 푼다