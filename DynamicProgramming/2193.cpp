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
long long D[92][2];


int main() {
    FIO;


    cin >> N;

    // 1자리 : 1  (0,1) 이걸로 2자리 D 구할때 first*2 + second = 1
    // 2자리 : 10 
    // 3자리 : 100 101 
    // 4자리 : 1000 1001 1010 
    // 5자리 : 10000 10001 10010 10100 10101 
    // 6자리 : 100001 100000 100010 100100 100101 101000 101001 101010

    // 점화식 D[i] = i 자리의 이친수

    D[1][0] = 0;
    D[1][1] = 1;

    D[2][0] = 1;
    D[2][1] = 0;

    


    for (int i = 3; i <= N; i++) {
        D[i][0] = D[i - 2][0] + D[i - 1][0];
        D[i][1] = D[i - 2][1] + D[i - 1][1];
    }
  
    if (N == 1) {
        cout << 1;
        return 0;
    }
    else if (N == 2) {
        cout << 1;
        return 0;
    }


    cout << D[N - 1][0] * 2 + D[N - 1][1];


    return 0;
}


// - D[i][0] 은 i자리수인데 끝자리가 0인 수의 개수
// - D[i][1] 은 i자리수인데 끝자리가 1인 수의 개수
// - D[i][0] * 2 + D[i][1]  = i+1 자리의 이친수 개수
// - N이 1,2 일때 예외로 출력
// - N이 90이면 매우 큰수라 long long 사용