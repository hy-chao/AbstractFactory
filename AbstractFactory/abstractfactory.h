#pragma once
/*
	抽象工厂模式简介:一个工厂接口，多个产品接口
	这里我们以数据库的维护为例，假设现在有一个工程项目不一定会用到
	Access和SqlServer这两种数据库的哪一种，但是此工程中数据库的相关表已经被定下
	因为对Access和Sqlserver的操作并不相同，此时为了维护方便我们可以使用抽象工厂模式
*/
#include<iostream>
using namespace std;
/*用户*/
class User
{

};

/*部门*/
class Department
{

};

//定义User表的抽象接口
class IUser
{
public:
	//向Iuser表中插入一个user
	virtual void Insert(User* user) = 0;
	virtual User* GetUser(int id) = 0; //根据id获取user
};

//Access中的User表（具体）
class AccessUser : public IUser
{
public:
	void Insert(User *user)
	{
		cout << "在Access数据库中的IUser表中插入一个User（记录）" << endl;
	}
	User* GetUser(int id)
	{
		cout << "从Access数据库的IUser表中根据id获取一条记录" << endl;
		return NULL;
	}
};

class SqlserverUser : public IUser
{
public:
	void Insert(User *user)
	{
		cout << "在Sqlserver数据库中的IUser表中插入一个User(记录)" << endl;
	}


	User* GetUser(int id)
	{
		cout << "从Sqlserver数据库的IUser表中根据id获取一条记录" << endl;
		return NULL;
	}
};

//定义Department表的抽象接口
class IDepartment
{
public:
	virtual void Insert(Department* department) = 0;
	virtual Department *GetDepartment(int id) = 0;
};

//Access数据库中的Department表
class AccessDepartment : public IDepartment
{
public:
	void Insert(Department* department)
	{
		cout << "在Access数据库的IDepartment表中插入一条记录" << endl;
	}
	Department* GetDepartment(int id)
	{
		cout << "从Access数据库的IDpartment表根据id获取一条记录" << endl;
		return NULL;
	}
};

//Sqlserver数据库中的Department表  
class SqlserverDepartment : public IDepartment
{
public:
	void Insert(Department* department)
	{
		cout << "在Sqlserver数据库的IDepartment表中插入一条记录" << endl;
	}

	Department* GetDepartment(int id)
	{
		cout << "从Sqlserver数据库的IDepartment表根据id获取一条记录" << endl;
		return NULL;
	}
};
//工厂接口
class IFactory
{
public:
	virtual IUser * CreateUser() = 0;
	virtual IDepartment * CreateDepartment() = 0;
};

//Access工厂类
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

//sqlserver工厂类
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