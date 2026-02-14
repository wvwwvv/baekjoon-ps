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
    
int n;
int wine[10004];
int D[10004];

int main() {
    FIO;

    cin >> n;

    for (int i = 1; i <= n; i++) cin >> wine[i];
    
    // 6 10 13 9 8 1 
    // D[i] = i번째 항까지 검사, 지금까지의 최댓값

    D[1] = wine[1];
    D[2] = wine[1] + wine[2];

    // i번째를 먹는다
        // i-1도 먹는다 : D[i] = wine[i] + wine[i-1] + D[i-3]    i-2 는 먹지 않고 i-3 까지의 최댓값을 더해준다
        // i-1을 먹지 않는다 : D[i] = wine[i] + D[i-2]           i-1 은 먹지 않고 i-2 까지의 최댓값을 더해준다

    // i번째를 먹지 않는다 : D[i] = D[i-1]
        


    for (int i = 3; i <= n; i++) {
        int m1 = max(wine[i] + wine[i - 1] + D[i - 3], wine[i] + D[i - 2]);
        int m2 = max(m1, D[i-1]);
        D[i] = max(m1, m2);
    }

    int result = -1;

    for (int i = 1; i <= n; i++)
        result = max(result, D[i]);

    cout << result;
    


    return 0;
}


// - 점화식 : i 번째까지 검사했을 때, 최댓값
//     - 경우의 수를 나눠서 최댓값 갖도록


// - 처음에 점화식을
//     - D[i] 는 i 번째 포도주를 무조건 마셨을 때, 이때까지의 최대값
//     - 이라고 설정했는데, 모든 케이스를 훑지 못한다
//     - 단적인 예로 100, 100, 1, 1, 100, 100 의 결과를 301로 리턴한다
//     - i 번째를 억지로 마셔야 하기 때문에 그 뒤의 큰 값을 선택할 때 손해를 볼 수 있기 때문