#include <iostream>

using namespace std;

int n, b, c;
int a[1000001];
long long result;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d %d", &b, &c);
    for(int i = 0; i < n; i++){
        a[i] -= b;              //�ְ����� ���� �����л�
        result++;               //������ + 1
        if(a[i] > 0){
            result += (a[i] / c);   //�ΰ����� ���� �����л�
            if(a[i] % c > 0)        //������ �������� ������
                result++;           //�ΰ����� + 1
        }
    }
    printf("%lld", result);
}