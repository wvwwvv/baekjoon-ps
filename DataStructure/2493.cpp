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
stack<pair<int, int>> s; //first : height, second: index

int main() {
    FIO;

  
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int h;
        cin >> h;

        // s에 남아있고, 지금 새롭게 받은 탑이 top보다 크면 스택에 있는 탑들은 신호를 못받음
        while (!s.empty() && s.top().X < h) {
            s.pop();
        }

        if (s.empty()) {
            cout << 0 << " ";
        }
        else { // s의 top은 현재 받은 탑의 신호를 받는 탑
            cout << s.top().Y << " ";
        }

        s.push({ h,i }); 
    }






    return 0;
}

// - 처음에 풀지 못했다
// - 현재 받은 탑의 높이가 stack 의 탑의 높이보다 크면, 스택의 탑은 신호를 못받는다
// - 다 pop해버리고 스택에 남아있는 탑(나보다 큰)이 있다면, s.top().Y 출력해서 신호를 받는 탑의 인덱스를 출력한다