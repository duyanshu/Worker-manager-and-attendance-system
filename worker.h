#pragma once
#include "admin.h"
class Saleman :public Post
{
public:
	Saleman(string name, int age, string gender, string tel, string account, int depnum);//���캯��
	virtual void show_info();//��ʾ�������
	virtual string getdep(int i);
protected:
};

class Engineer :public Post
{
public:
	Engineer(string name, int age, string gender, string tel, string account, int depnum);//���캯��
	virtual void show_info();//��ʾ�������
	virtual string getdep(int i);
protected:
};
