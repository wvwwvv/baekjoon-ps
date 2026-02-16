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

priority_queue<int, vector<int>, greater<int>> pq;
int N;

int main() {
    FIO;
    cin >> N;
    while (N--) {
        int x;
        cin >> x;
        pq.push(x);
    }

    int sum = 0;

    if (pq.size() == 1) {
        cout << 0;
        return 0;
    }


    while (pq.size() >1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        sum = sum + a + b;
        pq.push(a + b);
    }
    
    cout << sum;
   
    return 0;
}


// - 핵심은 top에서 뽑은 두 수를 더해서 다시 pq에 push 하는 것
// - 가장 작은 두 수를 더하는 것이 답일 것이라고 가정하고 풀었다
//     - 그리디