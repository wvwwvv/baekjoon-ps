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

int board[100003];
int D[100003];
int N;

int main() {
    FIO;

    // D[i] = i 번째 항으로 끝나는 연속합 중 최대 : board[i]를 반드시 선택해야함
    // 모든 n번째 항에서 끝나는 부분수열의 최댓값을 구하면, 모든 경우의 수를 전부 훑는 효과

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> board[i];
    }

    for (int i = 1; i <= N; i++) {
        D[i] = max(0, D[i - 1]) + board[i];
    }

    int result = D[1];

    for (int i = 1; i <= N; i++) {
        result = max(result, D[i]);
    }

    cout << result;

 


    return 0;
}


// - D[i]를 구하는 것이 결정적임
// - 처음에 D[i] 는 i번째까지 훑었을 때, 부분수열의 최댓값이라고 설정함
//     - 그러면 얼마나 연속된 수열인지, i번째를 선택한 연속 수열이었는지 정보를 알아야 하고 복잡해짐
// - 모든 경우의 수를 훑을 수 있는 D[i]를 구해야함
//     - D[i] 는 i 번째 값을 선택한, i까지 훑었을 때 부분수열의 최댓값