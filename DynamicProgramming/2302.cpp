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
    
int N, M;
bool vip[43];
int D[43];

int main() {
    FIO;

    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        int temp;
        cin >> temp;
        vip[temp] = true;
    }

    // D[i] : 좌석 i 개일때 가짓수
    // D[1] = 1, D[2] = 2, D[3] = 3, D[4] = 5
    // D[3] : (1,2,3), (2,1,3), (1,3,2)
    // D[4] : (1,2,3,4) , (2,1,3,4), (2,1,4,3), (1,3,2,4), (1,2,4,3)
    // D[5] : (1,2,3,4,5), 

    // D[5] 에서 맨 뒤의 수를 바꾸는 쌍에 들어가는 것으로 간주한다면, 4는 무조건 택해야 하므로 D[3]
    // D[5] 에서 맨 뒤의 수를 바꾸는 쌍에 들어가지 않게 간주한다면, (1,2,3,4) 의 가짓수이므로 D[4]

    // 위는 vip 고려 안했을 때이고 이 떄 D[i] = D[i-1] + D[i-2]

    // 그럼 i가 vip 가 아니면 D[i] = D[i-1] + D[i-2]
    // i가 vip 이면 선택 못하니까, D[i] = D[i-1]

    if (vip[1] == false) D[1] = 1;
    else D[1] = 0;

    // D[2] 초기화 필요
    

    for (int i = 3; i <= N; i++) {
        if (vip[i] == false) D[i] = D[i - 1] + D[i - 2];
        else D[i] = D[i - 1];
    }

    cout << D[N];
    


    return 0;
}


