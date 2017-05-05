#include<stdio.h>
#include<math.h>
#include<malloc.h>
 
typedef unsigned char boolean;
 
#define    TRUE    1
#define    FALSE    0
 
//λ��������Ч�ʸ���
#define        SET_BIT(byte, i)    (byte |= 1 << (7 ^ (i)))  //��������ֽڵ�ָ��λΪ1
#define        CLR_BIT(byte, i)    (byte &= ~(1 << (7 ^ (i)))) //��������ֽڵ�ָ��λΪ0
#define        GET_BIT(byte, i)    !!((byte) & (1 << (7^(i))))  //�õ�����ֽڵ�ָ��λ
 
// num >> 3  �����±�
// num & 7 <===> num % 8  
void findPrime(int number, char **p);
boolean isPrime(int num, char *p);
boolean Gguess(int userNumber, char *p);
 
boolean Gguess(int userNumber, char *p){
    int num;
    int i;
    int flag = TRUE;
 
    for(num = 6; TRUE == flag && num < userNumber; num += 2){ //��6��ʼ---userNumber���������ֽ��и�°ͺղ���
        flag = FALSE;
        for(i = 3; i < num && FALSE == flag; i += 2){
            if(isPrime(i, p) && isPrime(num-i, p)){
                flag = TRUE;
                printf("%d = %d + %d\n", num, i, num-i);
            }
        }
    }
 
    return flag;
}
 
boolean isPrime(int num, char *p){
    return GET_BIT(p[num >> 3], num & 7) == 0;  //0����ʾΪ����;
}
 
void findPrime(int number, char **p){
    int len = (int)(sqrt(number));
    int i;
    int j;
    char *pool;
 
    pool = (char *)calloc(sizeof(char), (number+7)>>3);
    for(i = 2; i < len; i++){  //��2�жϵ�����number�ĳ��ȼ���
        if(GET_BIT(pool[i >> 3], i & 7) == 0){  
            for(j = i*i; j < number; j += i){  //ǰ��Ķ��ظ����жϹ���
                SET_BIT(pool[j >> 3], j & 7);//���������Ϊ1
            }    
        }
    }
 
    *p = pool;
}
 
void main(void){
    int num;
    char *p;
 
    printf("������һ���߽���: ");
    scanf("%d", &num);
 
    findPrime(num, &p);
    if(FALSE == Gguess(num, p)){
        printf("��°ͺղ���ʧ��\n");
    }else{
        printf("��°ͺղ���ɹ���\n");
    }
}