#include<stdio.h>
#include<malloc.h>
 
void yusf(char **str, int count, int doom, int start){
    int *person;
    int i;
    int pre = start-2;
    int cur = start-1;
    int alive = count;
    int doomNumber = 0;
 
    if(start == 1){
        pre = count-1;
    }
 
    person = (int *)malloc(sizeof(int) * count);
    for(i = 0; i < count; i++){
        person[i] = (i+1)%count;  //ѭ������
    }
 
    for(; alive > 0; cur = person[cur]){
        if(++doomNumber >= doom){
            printf("%s->��Ȧ\n", str[cur]);
            alive--;
            doomNumber = 0;
            person[pre] = person[cur]; //��Ȧʱ��pre�ı���
        }else{
            pre = cur;
        }
    }
}
 
int main(void){
    char *str[] = {"���", "���", "����", "����", "����", "����", "����", "���", "���"};
    int count = sizeof(str)/sizeof(char *);
    int doom;  //��������
    int start;  //�ӵڼ����˿�ʼ
 
    scanf("%d%d", &doom, &start);
    if(doom > count || doom <= 0 || start > count|| start <= 0){
        return;
    }
 
    yusf(str, count, doom, start); //count��Ԫ��,doom����������,�ӵ�start��ʼ;
 
    return 0;
}