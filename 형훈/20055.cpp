#include <iostream>
#include <deque>

using namespace std;

int n, k, input, down, count = 0, stage = 0;
deque<pair<int,bool>> dq;

void rotate(){
    int tmp;                    
    tmp = dq[input].first;              //2n�� ������
    dq.pop_back();
    dq.push_front({tmp, false});        //��Ʈ ���� ������ �ö��
    dq[down].second = false;            //N�� �ִ� �κ��� ������ ������
    for(int i = down - 1; i > 0; i--)   //�����ö� �κ�����
        if(dq[i].second == true && dq[i+1].second == false && dq[i+1].first >= 1){  //i��°�� �κ��� �ְ� ���� ��Ʈ�� �κ��� ���� ���� ��Ʈ�� �������� 1�̻�         
            dq[i].second = false;                           //���� ĭ����
            dq[i+1].second = true;                          //���� ĭ���� �κ��̵�
            dq[i+1].first--;                                //���� ĭ ������ - 1
        }
    if(dq[0].first >= 1){               //������ �ö���� ��Ʈ�� �������� 1�̻��̸�
        dq[0].second = true;            //�κ��� �ø�
        dq[0].first--;                  //������ - 1
    }
    for(int i = 0; i <= input; i++)
        if(dq[i].first == 0)
            count++;
}

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n*2; i++){
        scanf("%d", &input);
        dq.push_back({input,false});
    }
    input = dq.size() - 1;              //��Ʈ ������ �ε���
    down = input/2;                     //�������� �� �ε���
    while(count < k){                   //0�� ������ k���� ������
        count = 0;                      //count �� �ʱ�ȭ
        stage++;                        //�ܰ� 1����
        rotate();
    }
    printf("%d", stage);
}