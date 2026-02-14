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

int d[100001];
int N;

int main() {
    FIO;
    cin >> N;

    d[1] = 0; //점화식 첫째항
    for (int i = 2; i <= N; i++) {
        d[i] = d[i - 1] + 1;
        if (i % 2 == 0) d[i] = min(d[i], d[i / 2] + 1);
        if (i % 3 == 0) d[i] = min(d[i], d[i / 3] + 1);
    }

    cout << d[N];

  

    return 0;
}

// - 점화식 찾기
// - d[1] 부터 규칙이 보이는 곳까지
//     - 이 문제는 d[1]만 있어도 for문을 돌면서 모든 수에 대한 table 작성 가능
// - bfs로 풀어도 됨
