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
typedef long long ll;

int N, X;
int board[250002];


int main() {
    FIO;

    cin >> N >> X;
    for (int i = 0; i < N; i++) cin >> board[i];

    int sum = 0;
    int same = 1;

    for (int i = 0; i < X; i++) {
        sum += board[i];
    }

    int maxSum = sum;

    for (int i = X; i < N; i++) {
        sum = sum + board[i] - board[i - X];

        if (sum > maxSum) {
            maxSum = sum;
            same = 1;
        }
        else if (sum == maxSum) {
            same++;
        }
    }

   
    if (maxSum == 0) {
        cout << "SAD";
        return 0;
    }
    else {
        cout << maxSum << "\n" << same;
    }
   
    return 0;
}


