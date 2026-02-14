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
long long D[101][11];

int main() {
    FIO;
    
    // D[i][j] : i 자리의 수이며, 가장 마지막 수가 j인 수의 계단수 개수
    // ex) D[2][7] :  67, 87 
    
    // D[1][1] ~ D[1][9] 는 전부 1
    // D[1][0] = 0 예외

    // D[2][1] = 2, D[2][2] ~ D[2][8] 는 2 D[2][9] = 1, D[2][0] = 1  
    // 즉, 끝 수가 1~8이면 D는 2,     0 or 9 이면 D는 1
    
    // 끝 수 1~8 => D[n][i] = D[n-1][i-1] + D[n-1][i+1]
    // 끝 수 0 => D[n][0] = D[n-1][1]
    // 끝 수 9 => D[n][9] = D[n-1][8]


    cin >> N;

    // 초기 고정값 세팅
    for (int i = 1; i <= 9; i++) D[1][i] = 1;
    D[1][0] = 0;

    for (int n = 2; n <= N; n++) {
        for (int i = 0; i <= 9; i++) {
            if (i == 0) {
                D[n][0] += D[n - 1][1] % 1000000000;
                continue;
            }

            if (i == 9) {
                D[n][9] += D[n - 1][8] % 1000000000;
                continue;
            }

            D[n][i] += (D[n - 1][i - 1] + D[n - 1][i + 1]) % 1000000000;
        }
    }

    long long result = 0;
    for (int i = 0; i <= 9; i++) result += D[N][i] % 1000000000;

    cout << result % 1000000000;



    return 0;
}


// - 점화식 D[n][i] = n자리수 && 맨 끝이 i로 끝나는 계단수의 개수
//     - 점화식을 D[n] 으로만 설정하기에는 정보를 다 표현할 수 없다
//     - 점화식에 사용하는 “모든 케이스를 훑을 수 있는 정보”를 맨 뒷 숫자로 잡았다
//         - 맨 앞자리는 0이 오면 안되기 때문에 한 단계 더 복잡하기 때문
// - i가 0 이냐 1이냐 2~8이냐 9이냐 로 크게 나눠서 고민해본다
//     - (0) , (1~8), (9) 3가지 경우의 수로 나눠진다
//     - 각 경우의 수에 대해 D[i] 와 D[i-1] 의 관계를 고민해본다
// - 10억으로 나눈 나머지를 다루는 만큼 최소한 long을 사용한다
// - D 갱신, result 갱신, result 출력의 모든 경우에서 10억으로 나눠준다
//     - result 도 long 타입을 잊어서 틀렸었다