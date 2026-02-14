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

int N, E, v1, v2;
vector<pair<int, int>> adj[802];
const int INF = 0x3f3f3f3f;
int d[802];

void clearD() {
    for (int i = 1; i <= N; i++) d[i] = INF;
}

void algo(int st) {
    clearD();

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

    d[st] = 0;
    pq.push({ 0,st });

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();

        if (d[cur.Y] != cur.X) continue;

        for (auto nxt : adj[cur.Y]) {
            if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;

            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({ d[nxt.Y], nxt.Y });
        }
    }
    

}

int main() {
    FIO;

   // 1 ~ N 까지 가되, v1과 v2를 반드시 거쳐야 한다
   // 쉽게 생각해보면 (1 ~ v1), (v1 ~ v2), (v2 ~ N)  서로다른 시작점을 3개 둬서 다익스트라를 구한다
   // 물론 처음에 1~v2 로 가는 것으로, 순서를 바꾸는 경우도 생각해야 할듯

    cin >> N >> E;

    for (int i = 1; i <= E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ c,b });
        adj[b].push_back({ c,a });
    }

    cin >> v1 >> v2;

    long long result1 = 0;
    long long result2 = 0;
    

    algo(1);
    result1 += d[v1];
    algo(v1);
    result1 += d[v2];
    algo(v2);
    result1 += d[N];

    algo(1);
    result2 += d[v2];
    algo(v2);
    result2 += d[v1];
    algo(v1);
    result2 += d[N];


    if (result1 >= INF && result2 >= INF) {
        cout << -1;
        return 0;
    }

    cout << min(result1, result2);



   return 0;
}


// - 출발지를 여러개 놓고 다 구해서 비교한다
// - result1,2 값은 INF가 최대 3번 더해질 수 있는 값이므로 넉넉하게 long long으로 설정한다
// - 틀린이유
//     - result1, 2 를 INF와 비교해서 -1 출력후 return을 안했다