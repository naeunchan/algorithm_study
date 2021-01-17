#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
char map[501][501];             //����
int out[501][501] = {0};        //����������� ������ ������ ������ ����
bool result[250001] = {false};     //index���� true�̸� Ż�� ������ ����
int u[2] = {-1,0};
int r[2] = {0,1};
int d[2] = {1,0};
int l[2] = {0,-1};
int step = 1;                   //����
int num = 0;                 //Ż�Ⱑ���� ��ǥ ����

void dfs(int i, int j){
    if(!out[i][j])                  //���� �湮���� �ʾҴٸ�
        out[i][j] = step;           //�湮���� step������ ����
    int di, dj;
    switch (map[i][j])          //���ĺ��� ���� ���氪 ����
    {
    case 'U':
        di = i + u[0];      
        dj = j + u[1];
        if(0 <= di && di < n && 0 <= dj && dj < m){ //���� ��ǥ�� ������ ������ ������
            if(!out[di][dj])                        //���� ��ǥ�� ���� �������� ���� ���̸�
                dfs(di,dj);
            else{                                   //�̹� ���������ٸ�
                if(result[out[di][dj]]){            //�ش���ǥ�� �����ִ� ������ Ż�� �������� �Ұ������� �Ǵ�
                    num++;                          //Ż�Ⱑ�� ������ �ִٸ� num�� ����
                    result[step] = true;            //�����ߴ� ��ǥ�� true�� ����
                }
            }
        }
        else{                                       //��ǥ�� ������ �����ٸ�
            num++;
            result[step] = true;
        }
        break;
    case 'R':
        di = i + r[0];
        dj = j + r[1];
        if(0 <= di && di < n && 0 <= dj && dj < m){ //���� ��ǥ�� ������ ������ ������
            if(!out[di][dj])                        //���� ��ǥ�� ���� �������� ���� ���̸�
                dfs(di,dj);
            else{                                   //�̹� ���������ٸ�
                if(result[out[di][dj]]){            //�ش���ǥ�� �����ִ� ������ Ż�� �������� �Ұ������� �Ǵ�
                    num++;                          //Ż�Ⱑ�� ������ �ִٸ� num�� ����
                    result[step] = true;            //�����ߴ� ��ǥ�� true�� ����
                }
            }
        }
        else{                                       //��ǥ�� ������ �����ٸ�
            num++;
            result[step] = true;
        }
        break;
    case 'D':
        di = i + d[0];
        dj = j + d[1];
        if(0 <= di && di < n && 0 <= dj && dj < m){ //���� ��ǥ�� ������ ������ ������
            if(!out[di][dj])                        //���� ��ǥ�� ���� �������� ���� ���̸�
                dfs(di,dj);
            else{                                   //�̹� ���������ٸ�
                if(result[out[di][dj]]){            //�ش���ǥ�� �����ִ� ������ Ż�� �������� �Ұ������� �Ǵ�
                    num++;                          //Ż�Ⱑ�� ������ �ִٸ� num�� ����
                    result[step] = true;            //�����ߴ� ��ǥ�� true�� ����
                }
            }
        }
        else{                                       //��ǥ�� ������ �����ٸ�
            num++;
            result[step] = true;
        }
        break;
    case 'L':
        di = i + l[0];
        dj = j + l[1];
        if(0 <= di && di < n && 0 <= dj && dj < m){ //���� ��ǥ�� ������ ������ ������
            if(!out[di][dj])                        //���� ��ǥ�� ���� �������� ���� ���̸�
                dfs(di,dj);
            else{                                   //�̹� ���������ٸ�
                if(result[out[di][dj]]){            //�ش���ǥ�� �����ִ� ������ Ż�� �������� �Ұ������� �Ǵ�
                    num++;                          //Ż�Ⱑ�� ������ �ִٸ� num�� ����
                    result[step] = true;            //�����ߴ� ��ǥ�� true�� ����
                }
            }
        }
        else{                                       //��ǥ�� ������ �����ٸ�
            num++;
            result[step] = true;
        }
        break;
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> map[i][j];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
                dfs(i,j);
                step++;                 //���� dfs���� �ٸ� ������ ���������
        }
    }
    printf("%d", num);
}