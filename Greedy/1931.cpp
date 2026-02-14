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
pair<int, int> s[100003];

int main() {
    FIO;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s[i].Y >> s[i].X;
    }
    sort(s, s + N); // pair 의 first 로 먼저 정렬, 같으면 second로 정렬되는데, 회의 끝나는 시각을 X, 시작 시각을 Y에 넣으면서, 오름차순 정렬 우선순위를 끝나는 시각으로

    // 그리디 풀이가 과연 올바른가?
    // 현재 시각 t 에 대해 t 보다 크거나 같은 (끝나는)시각을 다음 해로 택한다
    // 귀류법으로 증명하는데, t보다 큰 두 회의중 끝나는 시각이 더 큰 회의를 선택하는 것이 그렇지 않은 회의를 택하는 것보다 적어도 효율적이진 않다

    int ans = 0;
    int t = 0;

    for (int i = 0; i < N; i++) {
        if (t > s[i].Y) continue; // 시작 시간이 t보다 크거나 같아야 다음 선택지로 정함
        ans++;
        t = s[i].X; // 끝나는 시각 X를 t로 설정
    }
    cout << ans;

   


    return 0;
}


// - 핵심
//     - 현재까지 회의가 끝난 시각 t 기준
//         - 시작시각이 t 이상이며
//             - 그 중 끝나는 시각이 가장 작은 회의를 택하는 것이 최적의 해일 것이다 가정

// - 이 문제에서는 끝나는 시각이 각각 t= 3, t=5 인 회의 중 t=5를 택하는 것이 t=3을 택하는 것과 같은 최적의 해는 가질 수 있어도, 적어도 그보다 낫지는 않다 논리로, 부정을 부정한다

// - 또한 시각시각과 끝나는시각을 pair 쌍에서 거꾸로 받아
//     - sort 할때 끝나는 시각을 우선순위로 정렬하도록 한다