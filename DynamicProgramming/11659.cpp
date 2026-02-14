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

int N, M;
int sum[100002];

int main() {
    FIO;

    //prefix sum
    //N,M <= 100,000 이므로 O(NM)은 시간초과

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;

        sum[i] = sum[i - 1] + temp;
    }

    //sum[2] 는 1~2 번째까지의 합
    //sum[10] 은 1~10 번째까지의 합
    //2,10 을 구하려면 sum[10] - sum[1] 하면 됨
    //i,j 구하려면 sum[j] - sum[i-1]

    while (M--) {
        int a, b;
        cin >> a >> b;
        cout << sum[b] - sum[a - 1] << "\n";
    }


    return 0;
}

// - 항상 N,M의 범위로 시간복잡도 고려하기
// - 매번 순환보다 효율적으로 sum 배열에 지금까지의 합 넣어두고, sum[i] - sum[j] 유형의 식 떠올리기

