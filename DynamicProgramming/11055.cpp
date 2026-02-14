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

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        D[i] = arr[i];
    }

    // D[i] = i 번째 항을 무조건 선택했을 때, 여기까지의 최대 연속 합 : 그래야 모든 경우의 수를 전부 훑을 수 있음
    // D[1]=1, D[2]=101, D[3]=3, D[4]=53, D[5]=113



    int result = -1;
    
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < i; j++) {
            // D[i] 에 처음부터 훑으면서 arr[i]보다 작은수 있으면 계속 더함
            if (arr[i] > arr[j]) D[i] = max(D[i], D[j] + arr[i]);
       }
        result = max(result, D[i]);
    }


    cout << result;



    return 0;
}


// - D[i] 를 설계할 때 모든 경우의 수를 훑을 수 있는지 고민해야 한다
//     - “i 까지 훑었을 때, 부분수열의 최대값” 으로 설정하면 어떤 숫자들을 더해서 나온 수인지 추적이 불가능하다
//     - “i 번째를 포함한, i 까지 훑었을 때, 부분수열의 최대값” 은 끝나는 숫자가 정해져 있고, D[1] ~ D[N] 까지의 배열은 모든 경우의 수를 추적 가능한 형태로 접근할 수 있다
// - D[i] = arr[i] 로 초기화 하고, 각 i번째 항을 포함한 부분 수열의 최대값을 구하기 위해, 2중 for문으로 맨 앞부터 다시 훑어, arr[i] 가 arr[j] 보다 큰 경우에만 D[i] 에 해당 값을 더한다
//     - 자연스럽게 D[i]는 점화식 조건을 만족하게 된다