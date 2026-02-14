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
int D[1002];


int main() {
    FIO;

    cin >> N;

    // D[i] : 2 x i 크기의 사각형을 채우는 경우의 수
    // 2 x 2 타일이 없는 경우의 점화식은 D[i] = D[i-1] + D[i-2] : 맨 왼쪽에 2 x 1 이 있는 경우와 없는 경우
    // 여기서는 맨 왼쪽에 각 사각형이 오는 3가지 경우 존재
    // D[i] = D[i-1] + D[i-2] + D[i-2]
    // 10007 로 나눈 나머지면

    D[1] = 1;
    D[2] = 3;
    
    for (int i = 3; i <= N; i++) {
        D[i] = (D[i - 1] + 2 * D[i - 2]) % 10007;
    }

    cout << D[N];


    return 0;
}

// - 결국 점화식 생각할 때 기준을 정해놓고 모든 경우의 수 훑어볼 수 있게
// - 여기선 맨 왼쪽부터 채울 때
//     - 1x2
//     - 2x1
//     - 2x2
// - 3가지 경우가 올 수 있으니까
// - D[i] = D[i-1] + D[i-2] + D[i-2]
// - 문제조건에 10007로 나눈 나머지
//     - D[i] 갱신할 때 10007로 나눈 나머지로
