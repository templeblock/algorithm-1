#include<stdio.h>
#include<string.h>
 
void revStr(char *str, char *tmp);
void revStr(char *str, char *tmp){
    if(str == NULL || tmp == NULL){
        printf("��Ϊ�յ�,�����ܽ���\n");
        return;
    }   
    if(*str == 0){ 
        return;
    }   
    revStr(str+1, tmp); //��ջʵ���ַ���������,�Ƚ����;
 
    strncat(tmp, str, 1); 
}
 
int main(void){
    char str1[80] = "abcdefghijkl";
    char tmp[80];
 
    printf("����ǰ:%s\n", str1);
    revStr(str1, tmp);
    printf("�����:%s\n", tmp);
}