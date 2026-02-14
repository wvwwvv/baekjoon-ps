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

int n, m, s, e;
vector<pair<int, int>> adj[1005]; // index : 출발지, X : 비용, Y : 도착지
const int INF = 0x3f3f3f3f;
int d[1005]; //최소비용 테이블
int previous[1005]; // 추적



int T;

int main() {
    FIO;


    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a,b,c;
        cin >> a >> b >> c;

        adj[a].push_back({ c,b }); // 비용을 first 위치에 넣기 : pq 의 top 기준을 비용으로 삼기 위해
    }

    for (int i = 1; i <= n; i++) d[i] = INF;

    cin >> s >> e;

    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 비용, 노드

    d[s] = 0;

    pq.push({ d[s], s });

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();

        if (cur.X != d[cur.Y]) continue; // 테이블 값이랑 다르면 해당 노드 갱신 안해도 됨

        for (auto nxt : adj[cur.Y]) { // 현재 노드에서 갈 수 있는 모든 노드 순회
            // 이미 저장된 값이 더 작으면 갱신할 필요 없음 
            // (추가) "=" 등호가 있어야 한다. 같은 값을 가져도 continue로 빠져나가지 못하면 계속 pq 에 push 된다.
            if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue; 

            //여기까지 왔으면 최소 비용 테이블 갱신하고 해당 노드 pq에 다시 넣기
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({ d[nxt.Y], nxt.Y });
            previous[nxt.Y] = cur.Y;
        }
    }

    cout << d[e] << '\n';

    int num = 1;
    vector<int> st;


    int iter = e;
    while (true) {
        if (iter == s) break;

        iter = previous[iter];
        st.push_back(iter);
        num++;
    }

    cout << num << "\n";

    reverse(st.begin(), st.end());

    for (auto re : st) {
        cout << re << ' ';
   }


    cout << e;


    return 0;
}


// - 기본적인 다익스트라 알고리즘 틀을 따라간다
// - 경로 중 1개를 출력해야 하므로 추적을 위한 previous 배열을 둔다
//     - index 는 출발 노드, 값은 도착 노드
//     - 최소비용 테이블이 갱신되는 시점 (pq에 push가 일어나는 시점)에 previous를 갱신한다
//         - 한 노드가 pq 에 여러번 push 될 수 있으니 previous도 여러번 값이 덮여 쓰일 수 있다
// - 틀린이유 - 개념에 대한 이해 부족
//     - while() 에서 두 번째 continue 등장 구문을 아래와 같이 작성하였다
//     - if (d[nxt.Y] < d[cur.Y] + nxt.X) continue;
//     - < 를 사용하면, 비교하는 두 값이 같은 경우 continue로 빠져나가지 못한다
//         - 결론은 이 때 continue로 빠져나가서 d 테이블 갱신이 이루어지면 안된다
//         - 논리적으로는 최적의 길만 택하면 되므로 비용이 같아 d 값이 갱신되어도 상관 없을 것 같지만 메모리 상의 문제가 발생한다
//         - pq 동작 관점에서, 의미 없게 한 노드가 반복해 push 될 수 있고,  메모리 초과를 유도할 수 있다
//         - 그러면 이는 무한루프에 빠질 가능성이 있다고 볼 수 있을까?
//             - 간선 비용이 음수인 것이 존재하면 가능하다
//             - 간선 비용이 양수이면 무한루프가 발생하지 않고 “충분한” 시간이 지나면 pq는 비워진다
//                 - (노드가) a→b, b→a, a→b … 반복되는 상황에서, 간선 비용이 양수이면, 최소 비용 테이블 갱신값은 증가할 수밖에 없고, if 문에서 continue로 빠져나가게 된다
//     - 이 문제에서 d 값이 같을 때 갱신하면, 간선이 많은 상황에서 매우 넓게 퍼져나가 탐색하고, 쉽게 메모리 초과가 발생할 수 있다
//     - 코드를 아래와 같이 수정한다
//     - if (d[nxt.Y] ≤ d[cur.Y] + nxt.X) continue;