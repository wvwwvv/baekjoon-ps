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
long long D[103];


int main() {
    FIO;

    D[1] = 1;
    D[2] = 1;
    D[3] = 1;
    D[4] = 2;
    D[5] = 2;
    D[6] = 3;

    cin >> T;


    for (int i = 7; i <= 100; i++) {
        D[i] = D[i - 1] + D[i - 5];
    }

    
    while (T--) {
        int N;
        cin >> N;
        cout << D[N]<<'\n';
    }


   

    return 0;
}

// 단순한 피보나치인데 정수 범위값 의심하기
