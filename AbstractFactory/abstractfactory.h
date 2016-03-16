#pragma once
/*
	���󹤳�ģʽ���:һ�������ӿڣ������Ʒ�ӿ�
	�������������ݿ��ά��Ϊ��������������һ��������Ŀ��һ�����õ�
	Access��SqlServer���������ݿ����һ�֣����Ǵ˹��������ݿ����ر��Ѿ�������
	��Ϊ��Access��Sqlserver�Ĳ���������ͬ����ʱΪ��ά���������ǿ���ʹ�ó��󹤳�ģʽ
*/
#include<iostream>
using namespace std;
/*�û�*/
class User
{

};

/*����*/
class Department
{

};

//����User��ĳ���ӿ�
class IUser
{
public:
	//��Iuser���в���һ��user
	virtual void Insert(User* user) = 0;
	virtual User* GetUser(int id) = 0; //����id��ȡuser
};

//Access�е�User�����壩
class AccessUser : public IUser
{
public:
	void Insert(User *user)
	{
		cout << "��Access���ݿ��е�IUser���в���һ��User����¼��" << endl;
	}
	User* GetUser(int id)
	{
		cout << "��Access���ݿ��IUser���и���id��ȡһ����¼" << endl;
		return NULL;
	}
};

class SqlserverUser : public IUser
{
public:
	void Insert(User *user)
	{
		cout << "��Sqlserver���ݿ��е�IUser���в���һ��User(��¼)" << endl;
	}


	User* GetUser(int id)
	{
		cout << "��Sqlserver���ݿ��IUser���и���id��ȡһ����¼" << endl;
		return NULL;
	}
};

//����Department��ĳ���ӿ�
class IDepartment
{
public:
	virtual void Insert(Department* department) = 0;
	virtual Department *GetDepartment(int id) = 0;
};

//Access���ݿ��е�Department��
class AccessDepartment : public IDepartment
{
public:
	void Insert(Department* department)
	{
		cout << "��Access���ݿ��IDepartment���в���һ����¼" << endl;
	}
	Department* GetDepartment(int id)
	{
		cout << "��Access���ݿ��IDpartment�����id��ȡһ����¼" << endl;
		return NULL;
	}
};

//Sqlserver���ݿ��е�Department��  
class SqlserverDepartment : public IDepartment
{
public:
	void Insert(Department* department)
	{
		cout << "��Sqlserver���ݿ��IDepartment���в���һ����¼" << endl;
	}

	Department* GetDepartment(int id)
	{
		cout << "��Sqlserver���ݿ��IDepartment�����id��ȡһ����¼" << endl;
		return NULL;
	}
};
//�����ӿ�
class IFactory
{
public:
	virtual IUser * CreateUser() = 0;
	virtual IDepartment * CreateDepartment() = 0;
};

//Access������
class AccessFactory : public IFactory
{
public:
	IUser * CreateUser()
	{
		return new AccessUser();
	}
	IDepartment * CreateDepartment()
	{
		return new AccessDepartment();
	}
};

//sqlserver������
class SqlserverFactory : public IFactory
{
public:
	IUser * CreateUser()
	{
		return new SqlserverUser();
	}
	IDepartment * CreateDepartment()
	{
		return new SqlserverDepartment();
	}
};