#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int n, m;
int map[51][51], tmp_map[51][51];   //������, �ӽ÷� ����� ����
int dx[4] = {-1,0,0,1};
int dy[4] = {0,1,-1,0};
vector<pair<int,int>> v;            //���̷��� ��ǥ �� ����
bool check[11] = {false};           //���̷��� ����
int result = 2500;                  //�����

int find_max(){                     //�迭���� ���� ū �� ã��
    int value = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            value = max(value, tmp_map[i][j]);
    return value;
}
bool check_zero(){                  //�����������
    bool final = true;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(tmp_map[i][j] == 0)
                final = false;      
    return final;                   //false�� - 1 ���
}
void bfs(){
    bool visit[51][51] = {false};                   //�湮����
    memcpy(tmp_map, map, sizeof(map));              //�ӽ������� ��������
    queue<pair<int,int>> q;
    for(int i = 0; i < 11; i++){
        if(check[i] == true){                       //���̷����� �ִ� ��ġ�̸�
            q.push({v[i].first,v[i].second});       //ť�� ��ǥ�߰�
            visit[v[i].first][v[i].second] = true;
        }
    }
    //������� ���̷����� �����ϴ� m������ ��ǥ�� q�� ���ִ�. �������� ��ü Ȯ���ϵ� �ɸ��� �ð� ���ϸ� �˴ϴ�.
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int yy = y + dy[i];
            int xx = x + dx[i];
            if(0 <= yy && yy < n && 0 <= xx && xx < n){
                if(visit[yy][xx] == false && tmp_map[yy][xx] != 1){ //���� �湮���� �ʾҰ� ���� �ƴѰ��
                    tmp_map[yy][xx] = tmp_map[y][x] + 1;            //�̵����� �־��� ���� + 1
                    visit[yy][xx] = true;                           //�湮���� check
                    q.push({yy,xx});
                }
            }
        }
    }
}

void virus_dfs(int index, int cnt){
    if(cnt == m){
        bfs();
        if(check_zero())                        //���̷����� ��� �����ٸ�
            result = min(result, find_max());   //�� �迭���� ã�� �ִ�(���̷����� �����µ� �ɸ��°�)�� �������� ����������
        return;
    }
    for(int i = index; i < v.size(); i++){
        check[i] = true;                //q���� ���̷��� �������ΰ� üũ
        virus_dfs(i+1,cnt+1);
        check[i] = false;
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 2)
                v.push_back({i,j});
        }
    virus_dfs(0,0);

    if(result == 2500)              //result�� ���۰��� ���ٸ� ���̷����� ������ �����Ƿ�
        printf("-1");
    else
        printf("%d", result - 2);   //0���Ͱ��ƴ϶� 2���� ���� ���������Ƿ� -2
}