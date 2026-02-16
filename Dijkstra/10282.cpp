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

vector<pair<int, int>> adj[10005];
int dist[10005];
const int INF = 0x3f3f3f3f;
int T, n, d, s;

void algo() {
    cin >> n >> d >> s;

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        dist[i] = INF;
    }

    for (int i = 0; i < d; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[b].push_back({ c,a });
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[s] = 0;
    pq.push({ 0,s });

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();

        if (dist[cur.Y] != cur.X) continue;

        for (auto nxt : adj[cur.Y]) {
            if (dist[nxt.Y] <= dist[cur.Y] + nxt.X) continue;

            dist[nxt.Y] = dist[cur.Y] + nxt.X;
            pq.push({ dist[nxt.Y], nxt.Y });
        }
    }

    int result = 0;
    int time = 0;

    for (int i = 1; i <= n; i++) {
        if (dist[i] != INF) {
            result++;
            if (dist[i] > time) time = dist[i];
        }
    }

    cout << result << " " << time << "\n";
}


int main() {
    FIO;

    cin >> T;

    while (T--) {
        algo();
    }
  
   
    return 0;
}


