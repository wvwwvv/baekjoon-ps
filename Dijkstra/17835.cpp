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

int N, M, K;
vector<pair<int, int>> adj[100005];
ll d[100005]; // 비용 최대 100억
//const int INF = 0x3f3f3f3f;
const ll INF = 10000000000;
int start[100005];


int main() {
    FIO;

    cin >> N >> M >> K;
    for (int i = 1; i <= M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[b].push_back({ c,a }); // a,b 를 뒤집어서 면접장에서 출발하는 것처럼 구현 유도
    }

    for (int i = 1; i <= N; i++) d[i] = INF;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    for (int i = 1; i <= K; i++) {
        cin >> start[i];
        d[start[i]] = 0;
        pq.push({ 0,start[i] }); // 한번에 모든 출발 노드를 pq 에 넣어도 결국 d[index]는 특정 면접장에서 걸리는 최소 비용
    }

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();

        if (d[cur.Y] != cur.X) continue;

        for (auto nxt : adj[cur.Y]) {
            if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;

            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({ d[nxt.Y], nxt.Y });
        }
    }

    ll result = 0;
    int index = 0;

    for (int i = 1; i <= N; i++) {
        if (result < d[i]) {
            result = d[i];
            index = i;
        }
    }

    cout << index << "\n" << result;


    // 재시도
    // overflow? 

   
    return 0;
}


// - 출발지가 여러개라도 pq에 한번에 넣고 돌려도 d 갱신 잘 이루어진다
// - long long 타입임을 처음에 캐치 못해서 한번 틀렸다