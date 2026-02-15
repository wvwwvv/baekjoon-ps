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
int st, en;
vector<pair<int, int>> adj[1005];
const int INF = 0x3f3f3f3f;
int d[1005];

int main() {
    FIO;

    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ c,b });
    }

    for (int i = 1; i <= N; i++) d[i] = INF;

    cin >> st >> en;

    d[st] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 비용, 노드

    pq.push({ 0, st });

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();

        if (d[cur.Y] != cur.X) continue;

        for (auto nxt : adj[cur.Y]) {
            if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;

            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({ d[nxt.Y], nxt.Y });
        }
    }

    cout << d[en];

 
   
    return 0;
}


