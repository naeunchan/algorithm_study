#include <iostream>
#include <string>

using namespace std;

string str, tmp;
bool m = false;                 //���̳ʽ��� �����ϴ���
int result = 0;
int main(){
    cin >> str;
    for(int i = 0; i <= str.length(); i++){
        if(str[i] == '+' || str[i] == '-' || str[i] == '\0'){
            if(m)
                result -= stoi(tmp);
            else
                result += stoi(tmp);
            if(str[i] == '-')   
                m = true;
            tmp = "";    
        }
        else
            tmp += str[i];
    }
    printf("%d", result);
    return 0;
}