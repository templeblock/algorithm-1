#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//��ʮ����ת��Ϊ�������
//����������ʮ���Ƶ�ת��--->����ÿλ�ĳ˻���ͼ���
//�ڽ��Ƶ�ת������ʮ�������м������;
int main(void){
	vector<char> v1;
	int number;
	int r;
	char tmp;

	printf("������Ҫת��������: ");
	scanf("%d", &number);
	printf("�����������: ");
	scanf("%d", &r);

	while(number){
		tmp = "0123456789ABCDEF"[number%r];
		v1.push_back(tmp);
		number /= r;
	}
	reverse(v1.begin(), v1.end());
	vector<char>::iterator it = v1.begin();
	for(; it != v1.end(); it++){
		cout<<*it;
	}
	cout<<endl;


	return 0;
}