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
vector<pair<int, int>> adj[10005];
ll d[10005][22]; // K : 몇개의 도로를 포장했는지 저장
const ll INF = 10000000000;

int main() {
    FIO;

    cin >> N >> M >> K;
    for (int i = 1; i <= M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ c,b });
        adj[b].push_back({ c,a });
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) { // 도로 포장 개수는 0개부터 시작, 최대 K개
            d[i][j] = INF;
        }
    }

    // 시작지 1, 도착지 N

    for (int i=0; i<=K; i++) d[1][i] = 0;

    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq; //비용, 노드, 포장개수
    pq.push({ 0,1,0 });

    while (!pq.empty()) {
        auto [cost, node, cnt] = pq.top(); pq.pop();

        if (d[node][cnt] != cost) continue;

        for (auto nxt : adj[node]) {
            //if (d[nxt.Y][cnt] <= d[node][cnt] + nxt.X) continue; // 지금은 포장 안하는 경우도 조건으로 걸러서 처리해야 하기 때문에 여기서 continue하면 안됨

            // 포장 안하는 경우 처리
            if (d[nxt.Y][cnt] > d[node][cnt] + nxt.X) {
                d[nxt.Y][cnt] = d[node][cnt] + nxt.X;
                pq.push({ d[nxt.Y][cnt], nxt.Y, cnt });
            }

            // cnt < K 인 경우 포장 하는 상황 분기 pq에 추가
            if (cnt < K  && d[nxt.Y][cnt+1] > d[node][cnt]) {
                d[nxt.Y][cnt + 1] = d[node][cnt];
                pq.push({ d[nxt.Y][cnt + 1], nxt.Y, cnt + 1 });
            }

        }
    }

    ll result = INF;

    for (int i = 0; i <= K; i++) {
        result = min(result, d[N][i]);
    }

    cout << result;
   
    return 0;
}


// - 비용 테이블에 사용한 포장 도로의 개수 정보도 포함시키도록 추가
//     - 포장 안하는 경우는 기존 다익스트라에서 pq에 push하는 과정임
//     - 추가로, cnt < K 일때 해당 위치에서 포장한 결과도 pq에 push
//         - 엄밀히 따지만 “포장 한 상황”, “포장 가능할 경우 포장 한 상황” 두 경우 모두 pq에 push하면서 모든 경우를 훑는 것이다
// - c++ 17 버전부터 tuple 구조의 vector 에 push() 할 수 있다
// - pq도 cnt 저장해야하므로 vector<tuple<ll, int,int>>로 사용한다
// - 비용 관련 자료형은 long long을 사용한다