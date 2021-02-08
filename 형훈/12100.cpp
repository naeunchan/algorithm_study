#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, result = 0;
int sudoku[21][21] = {0};
int d[4] = {0,1,2,3};     //0:��, 1:��, 2:��, 3:��

void move(int dir, int count){
    if(count == 5){                 //5�� ������
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                result = max(result, sudoku[i][j]);
        return;
    }
    int copy_sudoku[21][21] = {0};
    for(int i = 0; i < n; i++)              
            for(int j = 0; j < n; j++)
                copy_sudoku[i][j] = sudoku[i][j];   //���� �迭 ����
    if(dir == 0){                   //��
        for(int i = 0; i < n; i++){
            queue<int> q;
            for(int j = 0; j < n; j++){
                if(copy_sudoku[j][i])
                    q.push(copy_sudoku[j][i]);        //���� ������ ���� q�� ����
                sudoku[j][i] = 0;                           //�������� �ʱ�ȭ
            }
            int j = 0;
            while(!q.empty()){
                if(q.size() >= 2){                          //queue�� 2�� �̻��� ��
                    int tmp = q.front();
                    q.pop();
                    if(tmp == q.front()){                   //�ΰ��� ���� ���� ��
                        sudoku[j++][i] = q.front() * 2;     //ù��° �� * 2 ����
                        q.pop();
                    }
                    else                                    //�ΰ��� ���� �ٸ� ��
                        sudoku[j++][i] = tmp;
                }
                else{                                       //queue�� 1���� ��
                    sudoku[j++][i] = q.front();             //ù��° �� ����
                    q.pop();
                }
            }
        }
    }
    else if(dir == 1){              //��
        for(int i = 0; i < n; i++){
            queue<int> q;
            for(int j = n-1; j >= 0; j--){
                if(copy_sudoku[j][i])
                    q.push(copy_sudoku[j][i]);
                sudoku[j][i] = 0;
            }
            int j = n-1;
            while(!q.empty()){
                if(q.size() >= 2){
                    int tmp = q.front();
                    q.pop();
                    if(tmp == q.front()){
                        sudoku[j--][i] = q.front() * 2;
                        q.pop();
                    }
                    else
                        sudoku[j--][i] = tmp;
                }
                else{
                    sudoku[j--][i] = q.front();
                    q.pop();
                }
            }
        }
    }
    else if(dir == 2){              //��
        for(int i = 0; i < n; i++){
            queue<int> q;
            for(int j = 0; j < n; j++){
                if(copy_sudoku[i][j])
                    q.push(copy_sudoku[i][j]);
                sudoku[i][j] = 0;
            }
            int j = 0;
            while(!q.empty()){
                if(q.size() >= 2){
                    int tmp = q.front();
                    q.pop();
                    if(tmp == q.front()){
                        sudoku[i][j++] = q.front() * 2;
                        q.pop();
                    }
                    else
                        sudoku[i][j++] = tmp;
                }
                else{
                    sudoku[i][j++] = q.front();
                    q.pop();
                }
            }
        }
    }
    else if(dir == 3){              //��
        for(int i = 0; i < n; i++){
            queue<int> q;
            for(int j = n-1; j >= 0; j--){
                if(copy_sudoku[i][j])
                    q.push(copy_sudoku[i][j]);
                sudoku[i][j] = 0;
            }
            int j = n-1;
            while(!q.empty()){
                if(q.size() >= 2){
                    int tmp = q.front();
                    q.pop();
                    if(tmp == q.front()){
                        sudoku[i][j--] = q.front() * 2;
                        q.pop();
                    }
                    else
                        sudoku[i][j--] = tmp;
                }
                else{
                    sudoku[i][j--] = q.front();
                    q.pop();
                }
            }
        }
    }
    for(int i = 0; i < 4; i++)
        move(i, count+1);
    for(int k = 0; k < n; k++)              
        for(int j = 0; j < n; j++)
            sudoku[k][j] = copy_sudoku[k][j];           //���� ������ �迭 ����
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &sudoku[i][j]);
    for(int i = 0; i < 4; i++)
        move(i, 0);
    printf("%d", result);
}