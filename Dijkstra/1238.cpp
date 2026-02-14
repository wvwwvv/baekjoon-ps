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

int N, M, X;
vector<pair<int, int>> adj[1005];
const int INF = 0x3f3f3f3f;
int d1[1005]; // 파티가 끝나고 돌아가는 길
int d2[1005]; // 파티까지 가는 비용

int main() {
    FIO;


    cin >> N >> M >> X;

    for (int i = 1; i <= M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ c,b });
    }

    // X를 시작점으로 d 테이블을 만들면, d는 파티가 끝나고 돌아가는 비용
    // 파티를 위해 X로 가는건 어떻게 구하지?
    // N개의 노드에서 X로 도착하는 비용도 구해야하는데.. 노드가 1000개니까 시간복잡도 1000 * 10000 * log 1000 = 3천만

    for (int i = 1; i <= N; i++) d1[i] = INF;

    d1[X] = 0; 

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 비용, 노드

    pq.push({ d1[X], X }); 

    // 파티 끝나고 돌아가는 비용 다익스트라

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();

        if (d1[cur.Y] != cur.X) continue;

        for (auto nxt : adj[cur.Y]) {
            if (d1[nxt.Y] <= d1[cur.Y] + nxt.X) continue;

            d1[nxt.Y] = d1[cur.Y] + nxt.X;
            pq.push({ d1[nxt.Y], nxt.Y });
        }
    }

    // d1[3] 하면  3번친구가 돌아가는 비용

    int person = 1; // 노드 번호
    int cost = 0; // 최대 비용

    for (int i = 1; i <= N; i++) { // N 명의 X까지 가는 비용 구하기
        for (int j = 1; j <= N; j++) d2[j] = INF;

        if (i == X) continue;

        d2[i] = 0;
        pq.push({ d2[i], i });

        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();

            if (d2[cur.Y] != cur.X) continue;

            for (auto nxt : adj[cur.Y]) {
                if (d2[nxt.Y] <= d2[cur.Y] + nxt.X) continue;

                d2[nxt.Y] = d2[cur.Y] + nxt.X;
                pq.push({ d2[nxt.Y], nxt.Y });
            }
        }

        int totalCost = d2[X] + d1[i];
        //cout << i<<"사람 갈때: " << d2[X] << " 올때: " << d1[i] << '\n';
        if (cost < totalCost) {
            cost = totalCost;
            person = i;
        }
    }

    cout << cost;
    //cout << person;



    return 0;
}


// 다익스트라 (우선순위큐)의 시간복잡도는 O(간선 log 노드) 인데, 이 문제는 N명의 사람이 각각 X로 가는 최소비용테이블을 작성하고, 매번 최대 cost를 갱신해야 하므로 O(NM log N) 이며, 이는 3천만이다

//(추가)
// - 파티 위치로 가는 비용 구할 때 시작점을 한 사람의 위치로 잡아 다익스트라를 노드의 개수만큼 추가로 돌렸는데,
// - 단방향 간선의 (시작, 도착)을 바꾸고, 파티 위치를 시작점으로 두어 새로운 d 를 다익스트라 1번만 돌려서 구하는 방식이 더 효율적이다