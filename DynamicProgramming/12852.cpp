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

int N;
int D[1000001];
int navi[1000001];

int main() {
    FIO;

    cin >> N;

    D[1] = 0; // 1 -> 1 로 가는 방법 0회 필요
    navi[1] = 0; //초깃값 0

    for (int i = 2; i <= N; i++) {
        //테이블 완성하기
        D[i] = D[i - 1] + 1;
        navi[i] = i - 1;

        if (i % 2 == 0 && D[i] > D[i/2]+1) {
            D[i] = D[i / 2] + 1;
            navi[i] = i / 2;
        }

        if (i % 3 == 0 && D[i] > D[i / 3] + 1) {
            D[i] = D[i / 3] + 1;
            navi[i] = i / 3;
        }
    }

    cout << D[N] << '\n';
    cout << N << ' ';
    int cur = N;

    while (true) {
        if (cur == 1) break;
        cout << navi[cur]<<' ';
        cur = navi[cur];
        
    }

   

    return 0;
}


// - a 를 최적의 해로 연산한 다음 나타나게 될 숫자를 b 라고 했을 때 navi[a] = b
// - 또한 for 문에서 2나 3으로 나누어 떨어질 때 D와 navi값 갱신하는데, if 조건에 D[i] > D[i/2]+1 같은 조건 추가
//     - 추가하지 않으면, for 내에서 D[i] 를 D[i] 와 D[i/2]+1 중 작은값으로 선택 (이전 코드에서 그렇게 구현) 하였는데, 이번엔 navi도 동시에 갱신해야하니 for 조건 내에 작성하는 것이 편함함