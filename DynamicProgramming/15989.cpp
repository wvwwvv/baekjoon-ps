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

int T;
int D[10002][4]; 

int main() {
    FIO;

    // D[i][j] : 합이 i, 마지막에 더한값 j, 단 수열은 항상 오름차순

    // D[1][1] = 1, D[1][2] = 0, D[1][3] = 0 -> 1
    // D[2][1] = 1, D[2][2] = 1, D[2][3] = 0 -> 2
    // D[3][1] = 1, D[3][2] = 1, D[3][3] = 1 -> 3
    // D[4][1] = 1, D[4][2] = 2, D[4][3] = 1 -> 4

    // D[i][1] = D[i-1][1]
    // D[i][2] = D[i-2][1] + D[i-2][2]
    // D[i][3] = D[i-3][1] + D[i-3][2] + D[i-3][3]

    D[1][1] = 1, D[1][2] = 0, D[1][3] = 0;
    D[2][1] = 1, D[2][2] = 1, D[2][3] = 0;
    D[3][1] = 1, D[3][2] = 1, D[3][3] = 1;

    for (int i = 4; i <= 10001; i++) {
        D[i][1] = D[i - 1][1];
        D[i][2] = D[i - 2][1] + D[i - 2][2];
        D[i][3] = D[i - 3][1] + D[i - 3][2] + D[i - 3][3];
    }

    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        cout << D[n][1] + D[n][2] + D[n][3] << '\n';


    }

 


    return 0;
}


// - 점화식 D를 2차원으로 세워야 함
// - D[i][j] : i를 만들기 위한 가짓수, 단, 마지막에 사용한 수가 j이며, 모든 수는 오름차순임