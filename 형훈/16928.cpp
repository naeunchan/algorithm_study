#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, u, v;
int board[101] = {0};           //������
int visit[101] = {0};           //�湮����, Ƚ��
int dice[6] = {1,2,3,4,5,6};    //�ֻ��� �̵�
queue<int> q;

int bfs(){
    q.push(1);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = 0; i < 6; i++){
            int next = x + dice[i];     //�������� �� �� �ִ� ��
            if(next == 100)
                return visit[x] + 1;            //100�̸� �����̹Ƿ� ���� Ƚ�� + 1�� ���� 
            if(board[next] != next)
                next = board[next];             //next ���� ���̳� ��ٸ��� ���� ���� �����Ƿ� �ٸ��� ���� ����
            if(visit[next] == 0){               //���� �湮���� �ʾҴٸ�
                visit[next] = visit[x] + 1;     //���� Ƚ���� +1
                q.push(next);                   //q�� push
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= 100; i++)
        board[i] = i;           //index i��°�� i�� ����Ŵ
    for(int i = 0; i < n+m; i++){
        scanf("%d %d", &u, &v);
        board[u] = v;           //index u�� v�� �̵��ϹǷ� u��°�� v�� ����Ŵ
    }
    printf("%d", bfs());
    return 0;
}