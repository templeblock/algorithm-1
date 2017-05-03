#include<iostream>
using namespace std;
 
//����ʽ,�̰߳�ȫ
class Singelton{
    private:
        Singelton(){
            cout<<"Singelton ���캯��ִ��"<<endl;
        }   
    public:
        static Singelton *getInstance(){
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
        static Singelton *m_psl; //��ʱC++��������û�з����ڴ�!!!
};
 
Singelton *Singelton::m_psl = new Singelton;
 
int main(void){
    cout<<"*********************"<<endl;  //ִ��˳����ִ�о�̬�����ĳ�ʼ��(��ʱҲ���ǹ��캯��),��ִ>
���������еĴ���!!!
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