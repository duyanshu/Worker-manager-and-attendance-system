#pragma once
#include <iostream>
#include <iomanip>
#include "post.h"
using namespace std;

class CEO :public Post
{
public:
	CEO(string name, int age, string gender, string tel, string account, int depnum);//���캯��
	virtual void show_info();//��ʾ�������
	virtual string getdep(int i);
protected:

};

class Salemanager :public Post
{
public:
	Salemanager(string name, int age, string gender, string tel, string account, int depnum);//���캯��
	virtual void show_info();//��ʾ�������
	virtual string getdep(int i);
protected:

};