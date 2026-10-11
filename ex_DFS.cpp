// 무방향 무가중치 그래프에 대한 DFS
// 방향 그래프면 그래프에 저장할 때 G[s].push_back(e)만 실행시키고
// 가중치가 있으면 그래프를 선언할때 vector<vector<pair<int, int>>> G; 이런식으로 G[i].first는 다음 vertex, second는 가중치로 저장하기
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//0.전역변수 선언
vector<vector<int>> G;  //그래프 선언 벡터 안의 구조체를 벡터로 선언해서 인접리스트 방식으로 사용
stack<int> s;   // 한 탐색에서 방문했던 vertex를 저장할 stack
vector<bool> visited;   // 해당 vertex를 방문했는지 확인하는 배열

//3-1. 재귀함수로 DFS 함수 만들기
void DFS_r(int v) {
    visited[v] = true;
    cout << v << '\n'; 
    
    for (int i : G[v]) {    // v랑 연결된 vertex를 전부 순회하면서
        if (!visited[i]) {  // 방문하지 않은 vertex에 대해서 계속 순회
            DFS_r(i);
        }
    }
}
//3-2. stack으로 DFS 함수 만들기
void DFS_s(int v) {
    s.push(v);
    visited[v] = true;
    cout << v << '\n';

    while (!s.empty()) {
        int curr = s.top();
        s.pop();
        for (int i : G[curr]) { //현재 방문했던 vertex 이후를 전부 순회하며
            if (!visited[i]) {
                visited[i] = true;  //인접 vertex를 전부 방문
                cout << i << '\n';
                s.push(curr);   // 부모 노드에서 처리하지 못한 vertex가 있을 수 있기 때문에 저장
                s.push(i);
                break;
            }
        }
    }
}

//1.메인함수에서 그래프 값 저장 및 방문배열 초기화, 2. 메인함수에서 함수를 구현했다고 가정 후 슈도코드 작성
int main() {
    int N,E;    //N = NODE , E = EDGE
    cin >> N >> E;
    G.resize(N+1);  // 그래프의 최대인덱스로 resize 이차원 배열 선언 시 필수
    visited = vector<bool>(N+1, false); // 방문배열을 N+1번 vertex까지 false로 초기화
    int s, e;   // s = 시작 vertex, e = 도착 vertex
    for(int i = 0; i < N; i++) {
        cin >> s >> e;
        G[s].push_back(e);  //무방향 그래프이므로 양방향으로 EDGE 저장하기
        G[e].push_back(s);
    }
    for(int i = 1; i < N+1; i++) {
        if(!visited[i]){    // 방문 배열의 값이 전부 true가 될 때까지 DFS 실행
            DFS_r(i);
        }
    }
}

