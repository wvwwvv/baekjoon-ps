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
int arr[1002];
int D[1002];
int P[1002];

int main() {
    FIO;

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    // D[i] : i 번째 항의 숫자를 택한, 가장 긴 수열의 길이
    // P[i] : i 번째 항의 숫자를 택한, 가장 긴 수열에서 i-1 번째 숫자의 index

    D[1] = 1; P[1] = 0;

    for (int i = 2; i <= N; i++) {
        int len = -1;
        int idx = -1; // j 로 갱신, j는 1부터 시작

        for (int j = 1; j < i; j++) {
            if (arr[i] > arr[j]) {
                if (D[j] > len) {
                    len = D[j];
                    idx = j;
                }
            }
        }

        // j 전부 검사
        if (idx != -1) {
            D[i] = len + 1;
            P[i] = idx;
        }
        else {
            D[i] = 1;
            P[i] = i;
        }
    }

    int maxLen = -1;
    int startIdx = -1;

    for (int i = 1; i <= N; i++) {
        if (D[i] > maxLen) {
            maxLen = D[i];
            startIdx = i;
        }
    }

    cout << maxLen << '\n';

    stack<int> s;

    for (int iter = 0; iter < maxLen; iter++) {
        s.push(arr[startIdx]);
        startIdx = P[startIdx];
    }

    while(!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
   


    return 0;
}


// - 같은 이름의 이전 문제에서, i 에 대한 D[j] 의 최댓값을 구할 때, 해당 위치의 index를 저장하는 로직이 추가되어야 역추적이 가능해진다
//     - P 배열 추가
// - 이중 for 문에서 len 와 idx 를 초깃값 -1 가지게 했는데, 업데이트가 일어나지 않는 경우 처리를 하지 않았다
//     - j 전부 검사하고
//      else {
//             D[i] = 1;
//             P[i] = i;
//         }
// - 를 추가하지 않아서 틀렸다
// - arr[i] 가 모든 arr[j]보다 클 경우에 대한 D와 P값 처리이다        