#include<stdio.h>
 
void printfInt(int data);
void printfDouble(double data, int count);
 
void printfDouble(double data, int count){
    int d = (int)data;
    double x = data - d;
    int i, tmp;
    int p = 1;
 
    printfInt(d);
    printf(".");
    for(i = 0; i < count; i++){
            p *= 10;
    }
    tmp = (int)(p*x+0.5);//��ǿתʱ�������нض������Լ���0.5����֤��С�������һλ��ȡֵ����ȷ�ġ�
    printfInt(tmp);
}
 
void printfInt(int data){
    int q = 1;
 
    if(data > 1000000000){
            q = 1000000000;
    }else if(data > 100000000){
            q = 100000000;
    }else if(data > 10000000){
            q = 10000000;
    }else if(data > 1000000){
            q = 1000000;
    }else if(data > 100000){
            q = 100000;
    }else if(data > 10000){
            q = 10000;
    }else if(data > 1000){
            q = 1000;
    }else if(data > 100){
            q = 100;
    }else if(data > 10){
            q = 10;
    }
 
    for(; q; q /= 10){
            printf("%c", '0' + (data/q)%10);
    }
}
 
int main(void){
    int number;
    double x_number;
    int bit;
 
    printf("������һ������ : ");
    scanf("%d", &number);
 // printf("������С������С��λ�� : ");
//  scanf("%lf%d", &x_number, &bit);
 
    printfInt(number);
    printf("\n");
//  printfDouble(x_number, bit);
//  printf("\n");
}