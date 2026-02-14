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

int D[17];
int board[17][2];


int main() {
    FIO;

    //D[i] : i 번째 날의 상담을 완료했을 때 최댓값

    int N;
    cin >> N;


    for (int i = 1; i <= N; i++) {
        cin >> board[i][0] >> board[i][1];
        if (i + board[i][0]-1 > N) continue;
        else D[i] = board[i][1];
    }

    for (int i = 1; i <= N; i++) {
        int temp = 0;
        for (int j = 1; j < i; j++) {
           
            if (i < j + board[j][0]) continue;
            temp = max(temp, D[j]);

        }

        D[i] += temp;
    }


    int result = -1;
    for (int i = 1; i <= N; i++) {
        result = max(result, D[i]);
    }

    cout << result;
   

    return 0;
}


// - D[i] = i 번째 일을 선택했을 때 보상의 최대값
//     - N 범위 넘는지 체크
// - 2중 for문으로 D[i] 에 D[j] 중 최댓값 더하기
//     - 단, 걸리는 시간 고려해서 continue로 걸러내기