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

int N, D;

// X 에 비용넣는 이유 : 우선순위 큐의 오름차순 정렬에 "비용"을 사용하기 위해 - 비용이 적은 것부터 꺼내야 하기 때문
vector<pair<int, int>> adj[10005]; // index : 시작 노드, X : 비용, Y : 도착 노드
int d[10005]; // 최단 거리 테이블
const int INF = 0x3f3f3f3f;


int main() {
    FIO;

    cin >> N >> D;

    for (int i = 0; i <= D; i++) {
        adj[i].push_back({ 1, i + 1 });
    }

    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ c,b }); // 비용부터 넣기
    }

    for (int i = 0; i <= D; i++) d[i] = INF;

    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 저장 형식은 int,int : 비용, 도착노드

    d[0] = 0; // 시작 노드의 비용 0 
    pq.push({ d[0], 0 });

    while (!pq.empty()) {
        auto cur = pq.top();  pq.pop(); // {비용, 정점 번호}

        // 꺼낸 cur 의 비용이 d 에 저장된 값과 다르면 continue
        if (cur.X != d[cur.Y]) continue;

        for (auto nxt : adj[cur.Y]) {
            if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue; // 이미 최단 거리 테이블 값이 더 작으면 갱신 안해도 됨

            // nxt 노드를 거치는게 더 빠를 때
            d[nxt.Y] = d[cur.Y] + nxt.X; // d 테이블 갱신
            pq.push({ d[nxt.Y], nxt.Y }); // 갱신한 {비용, 정점 번호} 를 다시 우선순위 큐에 넣고, 또 검사
        }
    }

    // pq 다 검사하고, d 갱신 완료

    cout << d[D];


    return 0;
}

// - dp로 당장 떠올려지지 않아서 다익스트라로 풀었다
// - 이 문제는 모든 노드가 연결되어 있지 않으므로 사전작업이 필요
//     - n → n+1 로 가는데 비용이 1 임을 입력받기 전에 0~D 에 대해 초기화 필요
