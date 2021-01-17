#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
int s[20][20] = {0};
int team[20] = {0};  //������ ǥ��
int value = 10000;
void maketeam(int a, int num){
    int sum_start = 0, sum_link = 0;
    vector<int> start_v;
    vector<int> link_v;
    if(num == n/2){       //n/2���� �������� ��������
        for(int i = 0; i < n; i++){
            if(team[i])     //���������� �Ѻ��Ϳ� �ֱ�
                start_v.push_back(i);
            else{
                link_v.push_back(i);
            }       
        }
        for(int i = 0; i < n/2; i++){
            for(int j = 0; j < n/2; j++){
                sum_start += s[start_v[i]][start_v[j]];
                sum_link += s[link_v[i]][link_v[j]];
            }
        }
        value = min(value, abs(sum_start-sum_link));    //���� ���� ���ɷ�ġ�� ������ �������� ����
        return;
    }
    for(int i = a; i < n; i++){
        if(team[i])
            continue;
        else{
            team[i] = 1;
            maketeam(i, num+1);
            team[i] = 0;
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &s[i][j]);
    maketeam(0,0);
    printf("%d", value);
    return 0;
}