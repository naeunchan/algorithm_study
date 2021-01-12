#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int k,v,e;
int tmp1,tmp2;
bool result = true;
vector<vector<int>> vec;
vector<int> visit;

void bfs(int a){
    queue<int> q;   
    q.push(a);           //���������� ������ �� �Ѱ��� queue�� ����
    visit[a] = 1;        //�湮���θ�  üũ
    while(!q.empty()){
        int next = q.front();   //q�� ù��° ��
        q.pop();                //q���� ����
        for(int i = 0; i < vec[next].size(); i++){      //�ش� ���� ������ִ� �� ���� ��ŭ
            if(visit[vec[next][i]] == 0){       //���� �湮�� ���ߴٸ�
                q.push(vec[next][i]);
                visit[vec[next][i]] = 3 - visit[next];    //3 ���� ���� ���� �� �ϸ� 1�� 2�� �ϳ��� ���� �ݺ��Ǹ� ����
            }
            else{   //�̹� �湮�ߴ� ���̶��
                if(visit[vec[next][i]] != 3 - visit[next])  //3���� ������ �ٸ��ٸ� �̺б׷����� �ƴ�
                    result = false;
            }
        }
    }
}

int main(){
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        scanf("%d %d", &v, &e);
        vec.assign(v+1, vector<int>(0,0));      //vec �ʱ�ȭ
        visit.assign(v+1, 0);                   //visit �ʱ�ȭ
        result = true;
        for(int j = 0; j < e; j++){
            scanf("%d %d", &tmp1, &tmp2);
            vec[tmp1].push_back(tmp2);
            vec[tmp2].push_back(tmp1);
        }
        for(int j = 1; j <= v; j++)
            if(visit[j] == 0 && vec[j].size() > 0)
                bfs(j);
        if(result)
            printf("YES\n");
        else
            printf("NO\n");
    }
}