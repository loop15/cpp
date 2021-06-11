

#include <iostream>
#include <string>
using namespace std;
class Base
{
    //���麯��������Ƕ�̬����
public:
    virtual ~Base() {}
};
class Derived : public Base
{
public:
    char *m_szName[100];
};
int main()
{
    Base b;
    Derived d;
    Derived *pd;
    pd = reinterpret_cast <Derived *>(&b);
    if (pd == NULL)
        //�˴�pd����Ϊ NULL��reinterpret_cast����鰲ȫ�ԣ����ǽ���ת��
        cout << "unsafe reinterpret_cast" << endl; //����ִ��

    pd = dynamic_cast <Derived *>(&b); //����ָ����࣬����ȫ�� �����Щ��Ա��������û�У�����m_szName
    if (pd == NULL)  //�������NULL����Ϊ &b ��ָ����������󣬴�ת������ȫ
        cout << "unsafe dynamic_cast1" << endl;  //��ִ��

    pd = dynamic_cast <Derived *>(&d);  //��ȫ��ת��
    if (pd == NULL)  //�˴� pd ����Ϊ NULL
        cout << "unsafe dynamic_cast2" << endl;  //����ִ��
    return 0;
}