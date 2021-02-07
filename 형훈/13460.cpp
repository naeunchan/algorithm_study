#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int n, m, result = 0;
int rx,ry,bx,by;
char game[11][11];
bool visit[11][11][11][11] = {false,};
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
queue<pair<pair<int,int>,pair<int,int>>> q;
 
int bfs(){
    q.push({{ry,rx}, {by,bx}});                 //���� �ʱ����
    visit[ry][rx][by][bx] = true;
    while(!q.empty()){
        int term = q.size();
        while(term--){
            int red_y = q.front().first.first;
            int red_x = q.front().first.second;
            int blue_y = q.front().second.first;
            int blue_x = q.front().second.second;
            q.pop();
            if(game[red_y][red_x] == 'O' && game[red_y][red_x] != game[blue_y][blue_x])     //�������� ���ۿ� ������ �Ķ����� �Ⱥ�������
                return result;
            for(int i = 0; i < 4; i++){
                int red_dy = red_y;
                int red_dx = red_x;
                int blue_dy = blue_y;
                int blue_dx = blue_x;
                while(game[red_dy+dy[i]][red_dx + dx[i]] != '#' && game[red_dy][red_dx] != 'O'){    //�������� ���� �ε�ġ�ų� ���ۿ� ���� ������
                    red_dy += dy[i];
                    red_dx += dx[i];
                }
                while(game[blue_dy+dy[i]][blue_dx + dx[i]] != '#' && game[blue_dy][blue_dx] != 'O'){//�Ķ����� ���� �ε�ġ�ų� ���ۿ� ���� ������
                    blue_dy += dy[i];
                    blue_dx += dx[i];
                }
                if(red_dy == blue_dy && red_dx == blue_dx){          //���� ��ġ�� ���ٸ�
                    if(game[red_dy][red_dx] == 'O')
                        continue;
                    if(abs(red_dy - red_y) + abs(red_dx - red_x) > abs(blue_dy - blue_y) + abs(blue_dx - blue_x)){  //�������� ������ �Ÿ��� �� ���ٸ�
                        red_dy -= dy[i];
                        red_dx -= dx[i];
                    }
                    else{
                        blue_dy -= dy[i];
                        blue_dx -= dx[i];
                    }
                }
                if (visit[red_dy][red_dx][blue_dy][blue_dx])
                    continue;
                visit[red_dy][red_dx][blue_dy][blue_dx] = true; // �湮 ǥ��
                q.push({ {red_dy, red_dx}, {blue_dy, blue_dx} });
            }
        }
        if (result >= 10) 
            return -1;
        result++;
    }
    return -1;
}
 
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> game[i][j];
            if(game[i][j] == 'R'){
                ry = i;
                rx = j;
            }
            if(game[i][j] == 'B'){
                by = i;
                bx = j;
            }
        }
    }
    printf("%d", bfs());
}