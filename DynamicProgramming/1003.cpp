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
int D[42][2];


//int f(int n) {
//    if (n == 0) {
//        return 0;
//    }
//    else if (n == 1) {
//        return 1;
//    }
//    else {
//        return f(n - 1) + f(n - 2);
//    }
//}

int main() {
    FIO;

    cin >> T;

    D[0][0] = 1;
    D[0][1] = 0;

    D[1][0] = 0;
    D[1][1] = 1;

    for (int i = 2; i <= 40; i++) {
        D[i][0] = D[i - 1][0] + D[i - 2][0];
        D[i][1] = D[i - 1][1] + D[i - 2][1];
    }

    while (T--) {
        cin >> N;

        cout << D[N][0] << ' ' << D[N][1] << '\n';
    }

    // 시간초과 - 이게 dp 인 이유 생각해보기
    // 점화식이 있을까?
    // D[i][0] = 0의 횟수 D[i][1] : 1의 횟수

    // D[0] : 1,0
    // D[1] : 0,1
    // D[2] : 1,1
    // D[3] : 1,2
    // D[4] : 2,3  ( return 2 + return 3 으로 => (return 1+return 0) + (return 1+return 2) => D[2] + D[3]




    return 0;
}


// - 단순히 문제에서 주어진대로 피보나치 함수 정의하고, return 될 때마다 zero 와 one 을 +1 하면 시간초과난다는 것을 캐치해야함
// - 결국 0의 횟수와 1의 횟수 2가지 상태만 다루기 때문에 i 번째에서의 0의 횟수, 1의 횟수에 대한 점화식을 찾기
// - 이역시 규칙을 찾아보면 각각의 피보나치이므로 D[] 테이블 생성하면 끝