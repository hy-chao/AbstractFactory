#include"abstractfactory.h"

void main()
{
	//����һ��Access����  
	IFactory *sqlserverFactory = new SqlserverFactory();
	IUser *user = sqlserverFactory->CreateUser();
	user->Insert(new User());
	user->GetUser(0);



	/*ʹ���������ģʽ�ĺô��ǣ�
	1.������Ҫ�������ݿ��ʱֻ��Ҫ����һ���ط�
	2.������Ҫ����������в���ʱҲֻ��Ҫ��һ���ط�

	��ά���Դ�����
	*/
}