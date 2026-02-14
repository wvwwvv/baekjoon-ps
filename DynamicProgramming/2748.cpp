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

int n;
long long D[95];

int main() {
    FIO;

    cin >> n;

    D[0] = 0; D[1] = 1;

    if (n == 1) {
        cout << 1;
        return 0;
    }

    for (int i = 2; i <= 90; i++) {
        D[i] = D[i - 1] + D[i - 2];
        if (i == n) {
            cout << D[i];
            return 0;
        }
    }

   


    return 0;
}


// - 이제는 익숙하다
//     - n이 90이하의 자연수임을 보자마자 overflow를 의심한다
//     - 제출하기 전 n=90 과 같이 기준이 되는 지점들을 테스트 해본다
//     - long 과 long long이 유의미한 런타임 차이가 나지는 않으므로 맘편하게 long long 먼저 쓰는게 일반적으로 맞을 듯하다
//         - 타이트한 문제라면 예외가 있을수도