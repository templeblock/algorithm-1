#include<iostream>
using namespace std;
 
//�����̰߳�ȫ������;`
class Singelton{
    private:
        Singelton(){
            cout<<"Singelton ���캯��ִ��"<<endl;
        }   
    public:
        static Singelton *getInstance(){
            if(m_psl == NULL){
                m_psl = new Singelton;  //������һ���������ڵ�ַ;
            }   
            return m_psl;
        }   
        static void freeInstance(){
            if(m_psl){
                cout<<"�ͷŶ���ռ�"<<endl;
                delete m_psl;
                m_psl = NULL;
            }
        }
    private:
        static Singelton *m_psl; //��̬����,������������г�ʼ��,��ʱ�Ż�����ڴ�ռ�!!!
};
 
Singelton *Singelton::m_psl = NULL;
 
int main(void){
    Singelton *p1 = Singelton::getInstance();
    Singelton *p2 = Singelton::getInstance();
 
    if(p1 == p2){
        cout<<"��ͬһ������"<<endl;
    }else{
        cout<<"����ͬһ������"<<endl;
    }
 
    Singelton::freeInstance();
    return 0;
}