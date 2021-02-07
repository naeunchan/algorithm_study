#include <iostream>
#include <queue>
using namespace std;

int n, k, l, dir = 0, count = 0;
bool end_game;
int board[101][101] = {0};      //������ 1, ����� 2
queue<pair<int,int>> q;

bool move(){
    int x, y;
    y = q.back().first;         
    x = q.back().second;
    if(dir == 0){               //������ ���� ����
        q.push({y, x+1});       //���� �Ӹ��� ��ǥ
        if(0 <= q.back().first && q.back().first < n && 0 <= q.back().second && q.back().second < n){   //���带 ����� �ʾҴٸ�
            if(board[q.back().first][q.back().second] == 1)             //������ ���� ���� ������ �ִٸ�
                return true;
            if(board[q.back().first][q.back().second] == 2)             //������ ���� ����� �ִٸ�
                board[q.back().first][q.back().second] = 0;             //��� ����
            else{                                                       //����� ���ٸ�
                board[q.front().first][q.front().second] = 0;           //���� ���� ����
                q.pop();                                                //������ ��ġ�� ĭ�� �����
            }
            board[q.back().first][q.back().second] = 1;                 //���� �Ӹ� �߰�
        }
        else                    //���带 ����ٸ�
            return true;
    }
    else if(dir == 1){          //�Ʒ� ���� ����
        q.push({y+1, x});
        if(0 <= q.back().first && q.back().first < n && 0 <= q.back().second && q.back().second < n){   //���带 ����� �ʾҴٸ�
            if(board[q.back().first][q.back().second] == 1)             //������ ���� ���� ������ �ִٸ�
                return true;
            if(board[q.back().first][q.back().second] == 2)             //������ ���� ����� �ִٸ�
                board[q.back().first][q.back().second] = 0;             //��� ����
            else{                                                       //����� ���ٸ�
                board[q.front().first][q.front().second] = 0;           //���� ���� ����
                q.pop();                                                //������ ��ġ�� ĭ�� �����
            }
            board[q.back().first][q.back().second] = 1;                 //���� �Ӹ� �߰�
        }
        else                    //���带 ����ٸ�
            return true;
    }
    else if(dir == 2){          //���� ���� ����
        q.push({y, x-1});
        if(0 <= q.back().first && q.back().first < n && 0 <= q.back().second && q.back().second < n){   //���带 ����� �ʾҴٸ�
            if(board[q.back().first][q.back().second] == 1)             //������ ���� ���� ������ �ִٸ�
                return true;
            if(board[q.back().first][q.back().second] == 2)             //������ ���� ����� �ִٸ�
                board[q.back().first][q.back().second] = 0;             //��� ����
            else{                                                       //����� ���ٸ�
                board[q.front().first][q.front().second] = 0;           //���� ���� ����
                q.pop();                                                //������ ��ġ�� ĭ�� �����
            }
            board[q.back().first][q.back().second] = 1;                 //���� �Ӹ� �߰�
        }
        else                    //���带 ����ٸ�
            return true;
    }
    else if(dir == 3){          //���� ���� ����
        q.push({y-1, x});
        if(0 <= q.back().first && q.back().first < n && 0 <= q.back().second && q.back().second < n){   //���带 ����� �ʾҴٸ�
            if(board[q.back().first][q.back().second] == 1)             //������ ���� ���� ������ �ִٸ�
                return true;
            if(board[q.back().first][q.back().second] == 2)             //������ ���� ����� �ִٸ�
                board[q.back().first][q.back().second] = 0;             //��� ����
            else{                                                       //����� ���ٸ�
                board[q.front().first][q.front().second] = 0;           //���� ���� ����
                q.pop();                                                //������ ��ġ�� ĭ�� �����
            }
            board[q.back().first][q.back().second] = 1;                 //���� �Ӹ� �߰�
        }
        else                    //���带 ����ٸ�
            return true;
    }
    return false;               //������ ������ ������ false
}

int main(){
    scanf("%d", &n);
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        int tmp1, tmp2; 
        scanf("%d %d", &tmp1, &tmp2);
        board[tmp1-1][tmp2-1] = 2;
    }
    q.push({0,0});
    board[0][0] = 1;                //1�� ���� ��
    scanf("%d", &l);
    int before_time = 0;
    for(int i = 0; i < l; i++){
        int x;
        char c;
        scanf("%d %c", &x, &c);
        int current_time = x - before_time;
        for(int j = current_time; j > 0; j--){
            count++;
            end_game = move();
            if(end_game){
                printf("%d", count);
                return 0;
            }
        }
        if(c == 'D')                //���� ���� ������ D�϶�
            dir = (dir + 1) % 4;
        else if(c == 'L')           //���� ���� ������ L�϶�
            dir = (dir + 4 - 1) % 4;
        before_time = x;            //���ݱ����� �ð� ���
    }
    while(!end_game){
        count++;
        end_game = move();
    }
    printf("%d", count);
    return 0;
}