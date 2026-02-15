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

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 절댓값, 원본수
int N, x;


int main() {
    FIO;

    cin >> N;

    queue<int> q;

    while (N--) {
        cin >> x;
        if (x == 0) {
            if (pq.empty()) {
                q.push(0);
                continue;
            }
            auto cur = pq.top(); pq.pop();
            //cout << cur.Y << "\n";
            q.push(cur.Y);
        }
        else {
            int ab;
            if (x > 0) ab = x;
            else ab = -x;

            pq.push({ ab,x });
        }
    }
    
    while (!q.empty()) {
        cout << q.front() << "\n";
        q.pop();
    }
   
    return 0;
}


// - pq의 X는 절댓값, Y는 원본값
//     - X를 기준으로 내림차순