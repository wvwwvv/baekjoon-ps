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
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    FIO;

    cin >> N;

    int x;
    
    for (int i = 0; i < N * N; i++) {
        cin >> x;

        pq.push(x);

        if (pq.size() > N) {
            pq.pop();
        }
       
    }
   
    cout << pq.top();
  
   
    return 0;
}


