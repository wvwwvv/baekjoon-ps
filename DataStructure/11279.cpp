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

int N;
priority_queue<int> pq;

int main() {
    FIO;

    cin >> N;

    while (N--) {
        int x;
        cin >> x;

        if (x == 0) {
            if (pq.empty()) {
                cout << 0 << "\n";
                continue;
            }
            else {
                int cur = pq.top(); pq.pop();
                cout << cur << "\n";
            }
           
        }
        else {
            pq.push(x);
        }
    }
  
   
    return 0;
}


