#include <iostream>

using namespace std;

string str;
string bomb;
char result[1000000];

int main(){
    cin >> str >> bomb;
    int j = 0;
    for(int i = 0; i < str.length(); i++){                //str�� �ϳ��� result�� ����
        result[j++] = str[i];
        if(result[j - 1] == bomb[bomb.length() - 1]){     //���� ���ڿ��� ��ź���ڿ��� �������� ���ٸ�
            bool find = true;
            if (j - bomb.length() < 0)                  //��ź���̺��� ������ �ƹ��͵� �ƴ�
                continue;
            for(int k = 0; k < bomb.length(); k++){                   //�ڿ������� ��
                if(result[j - 1 - k] != bomb[bomb.length() - 1 - k]){ //��ź���ڿ��̾ƴϸ� �׸�
                    find = false;
                    break;
                }
            }
            if(find)                //��ź���ڿ��� �����ϰ� ������
                j -= bomb.length();
        }
    }
    if(j != 0)
        for(int i = 0; i < j; i++)  //j���� ���
            printf("%c", result[i]);
    else
        printf("FRULA");
}