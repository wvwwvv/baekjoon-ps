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
int arr[1003];
int D[1003];

int main() {
    FIO;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        D[i] = 1;
    }

    // D[i] : i 번째 항을 무조건 포함했을 때 부분수열의 길이
    // D[1] = 1 D[2] = 2 D[3] = 1 D[4] = 3 D[5] = 2 D[6] = 4

    int result = -1;
     
    for (int i =0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            // 앞의 i-1개 보면서, arr[i]>arr[j] 이면 각 D[j]+1 는 확실히 가져감
            if (arr[i] > arr[j]) D[i] = max(D[i], D[j] + 1);
        }
        result = max(result, D[i]);
    }

    cout << result;

    return 0;
}


// - boj 11055 와 비슷하게 D[i] 는 해당 항을 포함했을 때 가장 긴 수열의 길이 이어야 한다.
// - 2중 for문으로, arr[i]>arr[j] 일때, D[j]을 무조건 가져갈 수 있으므로 D[j]+1 의 값과 현재 i위치의 D[i] 중 큰 값으로 갱신한다.