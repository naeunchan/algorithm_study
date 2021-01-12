#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n, l;
int x1, y1, x2, y2;
int visit[301][301] = {0};          //�湮�ϱ���� �ɸ� �Ÿ�
int dy[8] = {-2,-2,-1,-1,1,1,2,2};  //����Ʈ�� ������ �� �ִ� y��ǥ
int dx[8] = {1,-1,2,-2,2,-2,1,-1};  //����Ʈ�� ������ �� �ִ� x��ǥ

int bfs(int y, int x){
    queue<pair<int,int>> q;
    q.push({y,x});
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(y == y2 && x == x2)          //�����ϸ� ���� �Ÿ��� ���� �ּҰŸ� ����
            return visit[y][x];
        for(int i = 0; i < 8; i++){
            int yy = y + dy[i];
            int xx = x + dx[i];
            if(0 <= yy && yy < l && 0 <= xx && xx < l){
                if(visit[yy][xx] == 0){
                    q.push({yy,xx});
                    visit[yy][xx] = visit[y][x] + 1;    //��������Ÿ� + 1
                }
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &l);
        scanf("%d %d", &y1, &x1);
        scanf("%d %d", &y2, &x2);
        if(y1 == y2 && x1 == x2)          //��������� ���������� ������ �Ÿ� 0����
            printf("0\n");
        else
            printf("%d\n", bfs(y1, x1));
        memset(visit, 0, sizeof(visit)); // visit �ʱ�ȭ
    }
}