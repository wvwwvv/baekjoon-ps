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
    
int T, N;
long long D[1000003];

int main() {
    FIO;

    cin >> T;

    // D[1] = 1, D[2] = 2, D[3] = 4, D[4] = 7, D[5] = 13

    D[1] = 1; D[2] = 2; D[3] = 4;

    for (int i = 4; i <= 1000001; i++) {
        D[i] = D[i - 1] % 1000000009 + D[i - 2] % 1000000009 + D[i - 3] % 1000000009;
        D[i] %= 1000000009;
    }

    while (T--) {
        cin >> N;

        cout << D[N] << '\n';

    }


    return 0;
}


// - long long 타입
// - D 갱신하는 과정에서 overflow 생각하며 % 사용