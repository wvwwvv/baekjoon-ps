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
int board[1002][3]; // 0:R 1:G 2:B
int D[1002][3];


int main() {
    FIO;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> board[i][j];
        }
    }
    //점화식  D[i][j] : i번째까지 색칠한 누적 값, j : RGB 
    // D[1][0] = board[1][0] (R)
    // D[1][1] = board[1][1] (G)
    // D[1][2] = board[1][2] (B)

    //D[2][0] = board[1][0] + min(D[1][1], D[1][2])


    D[1][0] = board[1][0];
    D[1][1] = board[1][1];
    D[1][2] = board[1][2];

    for (int i = 2; i <= N; i++) {
            D[i][0] = board[i][0] + min(D[i - 1][1], D[i - 1][2]);
            D[i][1] = board[i][1] + min(D[i - 1][0], D[i - 1][2]);
            D[i][2] = board[i][2] + min(D[i - 1][1], D[i - 1][0]);
    }



    int result = D[N][0];
    result = min(result, D[N][1]);
    result = min(result, D[N][2]);

    cout << result;
 
   


    return 0;
}


// - i 번째 집을 칠하는 경우의 수는 3가지
//     - D[i][0] ~ D[i][2] 까지 for 문으로 각각 점화식을 통해 구함
// - 최종 D[N][ ] 에는 N번째를 R로 칠하는 것과 G, B로 칠하는 것 3가지 경우에 대해 모두 가지고 있음
