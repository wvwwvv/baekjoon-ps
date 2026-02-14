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


int board[502][502];
int N;
int D[502][502];


int main() {
    FIO;

    cin >> N;

    //점화식 D[i][j] : 여기까지 오는데 최댓값

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> board[i][j];
        }
    }

    D[1][1] = board[1][1];

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            D[i][j] = max(D[i - 1][j - 1], D[i - 1][j]) + board[i][j];
        }
    }

    int result = 0;
    for (int i = 1; i <= N; i++) {
        result = max(result, D[N][i]);
    }

    cout << result;



    


    return 0;
}


// - i,j 위치에서의 점화식 값은 현재까지 오는데의 최대 점수
// - for 문의 그 다음 계층을 보는 것보다 이전 값을 참조해서 현재 위치 점화식 값을 구하는게 더 편함
// - 바이너리 트리 구조라도 2차원 정사각형 배열 선언하고 i와 j 조절하면서 접근해야 함