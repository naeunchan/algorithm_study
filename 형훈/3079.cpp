#include <iostream>
#include <algorithm>

using namespace std;

long long n, m;
long long arr[100001];
long long low, high, result;

int main(){
    scanf("%lld %lld", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);
    sort(arr, arr + n);
    low = 0;
    high = m * arr[n - 1];                  
    result = m * arr[n - 1];
    while(low <= high){
        long long mid = (low + high) / 2;
        long long sum = 0;
        for(int i = 0; i < n; i++)
            sum += mid / arr[i];        //mid�ð��ȿ� ����� �Ա��ɻ�븦 ����� �� �ֳ�
        if (sum >= m) {                 //����� �� �ִ� ����� ����ؾ��� ������� ���ٸ�
            result = min(result, mid); 
            high = mid - 1; 
        }
        else
            low = mid + 1;
    }
    printf("%lld", result);
}