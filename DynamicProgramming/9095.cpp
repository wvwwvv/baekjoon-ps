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
int N;

int D[20];

int main() {
    FIO;

    D[1] = 1;
    D[2] = 2;
    D[3] = 4;

    for (int i = 4; i <= 11; i++) {
        D[i] = D[i - 1] + D[i - 2] + D[i - 3];
    }
   
    cin >> T;

    while (T--) {
        cin >> N;

        // D[i] = i 인 점화식 찾기
        // D[1] = 1, D[2] = 2, D[3] = 4
        // D[4] = 7, D[5] = 13
        // 1+1+1+1 같이 끝이 1로 끝나는 것의 개수 : D[3] 의 개수 - 맨 뒤 1을 떼면 D[3] 의미
        // D[i] = D[i-1] + D[i-2] + D[i-3]


        cout << D[N] << '\n';
        
    }
   


    return 0;
}

// - N이 매우 크면 while 안에서 매번 점화식 구하는 것 비효율적
// - 미리 구해두고 사용

