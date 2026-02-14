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
int D[1003];

int main() {
    FIO;

    cin >> N;

    // 2 x i 직사각형을 채우는 방법 수
    // D[1] = 1, D[2] = 2, D[3] = 1+2 = 3 (2x2 정사각형의 개수가 0개, 1개 일때)
    // D[3] 생각해보면 D[2] 에서 1개 늘어난건데..
    // D[4] = 1 + 3 + 1 = 5 (2x2 정사각형의 개수가 0개, 1개, 2개 일때)
    // D[5] = 1 + 4 + 3 = 8 
    // 13 21 34 55 피보나치인데?
    
    D[1] = 1;
    D[2] = 2;
    for (int i = 3; i <= N; i++) {
        D[i] = (D[i - 1] + D[i - 2]) % 10007;
    }

    cout << D[N];


 

    return 0;
}


// - 화식
//     - 가장 왼쪽 타일이 가로로 놓이거나 세로로 놓이거나 2가지밖에 없는데 이걸로 모든 경우의 수가 다 덮여짐
//     - 각각 D[i-1] , D[i-2] 에 해당하는 것이니 이걸 더하면 됨
// - 출력할 때 최종 값을 10007로 나누면 overflow 발생 가능하므로 점화식에서 처리