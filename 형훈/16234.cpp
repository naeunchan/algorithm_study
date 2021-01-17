#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int n, l, r;
int contry[51][51];
bool visit[51][51];
int dy[4] = {1,0,0,-1};
int dx[4] = {0,1,-1,0};
bool roop = true;
int result = 0;                         //�����

void bfs(int y, int x){
    int sum = 0;
    vector<pair<int,int>> v;            //������ǥ
    queue<pair<int,int>> q;
    v.push_back({y,x});
    q.push({y,x});
    visit[y][x] = true;
    while(!q.empty()){
        int yy = q.front().first;
        int xx = q.front().second;
        sum += contry[yy][xx];          //�������� �̷���� ��ǥ���� ���� ������
        q.pop();
        for(int i = 0; i < 4; i ++){
            int yyy = yy + dy[i];
            int xxx = xx + dx[i];
            int dif = abs(contry[yy][xx] - contry[yyy][xxx]);   //����������ǥ�� �̵�������ǥ ������ ����
            if(0 <= yyy && yyy < n && 0 <= xxx && xxx < n && visit[yyy][xxx] == false && l <= dif && dif <= r){     //�����ȿ��ְ�, �����湮�����ʾ��� ��, ���̰� l�� r����
                v.push_back({yyy,xxx});
                q.push({yyy,xxx});
                visit[yyy][xxx] = true;
            }
        }
    }
    //while�� ������ bfs() �� ������ ����� ���ճ������ ������
    if(v.size() >= 2){                          //���ձ��� �ִٴ� ��
        for(int i = 0; i < v.size(); i++)
            contry[v[i].first][v[i].second] = sum / v.size();
        roop = true;
    }
}

int main(){
    scanf("%d %d %d", &n, &l, &r);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &contry[i][j]);
    while(roop){
        roop = false;                           //bfs�� �ѹ��� ������� �ʾҴٸ� roop���� false�̹Ƿ� while���� �ȵ��ư�
        memset(visit, false, sizeof(visit));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(visit[i][j] == false)
                    bfs(i,j);
        if(!roop)
            break;
        result++;
    }
    printf("%d", result);
}