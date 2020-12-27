#pragma once
#include "admin.h"
class Saleman :public Post
{
public:
	Saleman(string name, int age, string gender, string tel, string account, int depnum);//构造函数
	virtual void show_info();//显示个人身份
	virtual string getdep(int i);
protected:
};

class Engineer :public Post
{
public:
	Engineer(string name, int age, string gender, string tel, string account, int depnum);//构造函数
	virtual void show_info();//显示个人身份
	virtual string getdep(int i);
protected:
};
