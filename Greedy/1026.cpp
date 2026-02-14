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
int a[55];
int b[55];

int main() {
    FIO;

    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) cin >> b[i];


    sort(a, a + N);
    sort(b, b + N, greater<int>());

    int result = 0;

    for (int i = 0; i < N; i++) {
        result += a[i] * b[i];
    }

    cout << result;
   


    return 0;
}

// 직관적으로 가장 큰수에는 가장 작은 수를 곱하는 로직 떠올리기
