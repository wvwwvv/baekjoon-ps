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
int arr[1000003];

int main() {
    FIO;

    cin >> T;

    while (T--) {
        cin >> N;

        for (int i = 1; i <= N; i++) cin >> arr[i];

        long long result = 0; // 수익
        int biggest = 0;

        for (int i = N; i > 0; i--) {
            if (biggest < arr[i]) { // 최고가
                biggest = arr[i];
            }
            else { // 최고가보다 낮은 주식가격으로 샀으므로 판매
                result += biggest - arr[i];
            }
        }

        cout << result << '\n';
    }
  
    





    return 0;
}


// - arr 맨 뒤부터 접근한다
// - 뒤부터 보면서 최댓값 갱신하고
//     - 최댓값보다 arr 값이 작으면, 주식을 파는 것으로 이해한다
// - 뒤에서 접근할 생각을 못했다