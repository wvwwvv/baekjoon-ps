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

int score[301];
int N;
int D[301][3];

int main() {
    FIO;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> score[i];

    //점화식 구해야하는데, 현재 몇개 개단을 연속으로 밟았는지 정보를 알아야하므로 D 배열은 2차원이 되어야함
    //무조건 D[i][j] 에서 i번째 계단을 밟았다는 상황이라고 가정하고 그 시점에 밟은 계단의 수가 j임
    //D[i][j] 에서 j는 1 또는 2밖에 되지 못함
    //D[i][1] 을 먼저 구해보면, 현재 연속된 계단 밟음이 아니므로 i-2 번째 계단을 밟음 -> max(D[i-2][1], D[i-2][2]) + score[i]
    //D[i][2] -> D[i-1][1] + score[i]
    
    D[1][1] = score[1];
    D[1][2] = 0;

    D[2][1] = score[2];
    D[2][2] = score[1] + score[2];


    for (int i = 3; i <= N; i++) {
        D[i][1] = max(D[i - 2][1], D[i - 2][2]) + score[i];
        D[i][2] = D[i-1][1] + score[i];
;    }

    
    int result = max(D[N][1], D[N][2]);

    cout << result;
   

 
   


    return 0;
}


// - 현재 연속된 계단이 1번째인지 2번째인지에 따라 이전 시행에 확정을 줄 수 있음
// - 점화식을 2차원으로 확장
// - N==1 일때 예외처리 필요할수도