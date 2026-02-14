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
int w[100003];

int main() {
    FIO;

    cin >> N;
    for (int i = 0; i < N; i++) cin >> w[i];

    sort(w, w + N, greater<int>());

    int result = -1;

    for (int i = 0; i < N; i++) {
        int temp = w[i] * (i + 1);
        result = max(result, temp);
    }

    cout << result;
   


    return 0;
}


// - 그리디
//     - n개의 로프를 선택하는데에 있어 가장 큰 n 개를 고르는 것이 맞을 것이다 가정
// - 정렬
//     - sort(arr, arr+size, greater<int>())
//         - 내림차순