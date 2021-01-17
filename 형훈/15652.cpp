#include <iostream>

using namespace std;

int n, m;
int arr[8] = {1,2,3,4,5,6,7,8};
int result[8] = {0};

void backtracking(int a){
    if(a == m){
        for(int j = 0; j < m; j++){
            printf("%d ", result[j]);
        }
        printf("\n");
    }
    else{
        for(int i = 0; i < n; i++){
            if(a == 0){
                result[a++] = arr[i];
                backtracking(a--);
            }
            if(a > 0 && arr[i] >= result[a-1]){     //�񳻸������� ���ϴ°��̱� ������ �������� ���� ���� ������� ���� �ʴ´�.
                result[a++] = arr[i];
                backtracking(a--);
            }
        }
    }
}

int main(){
    scanf("%d %d",&n, &m);
    backtracking(0);
    return 0;
}