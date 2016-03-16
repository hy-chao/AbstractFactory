#include"abstractfactory.h"

void main()
{
	//建立一个Access工厂  
	IFactory *sqlserverFactory = new SqlserverFactory();
	IUser *user = sqlserverFactory->CreateUser();
	user->Insert(new User());
	user->GetUser(0);



	/*使用这种设计模式的好处是，
	1.当你需要更换数据库或时只需要更改一个地方
	2.当你需要对其他表进行操作时也只需要改一个地方

	可维护性大大提高
	*/
}