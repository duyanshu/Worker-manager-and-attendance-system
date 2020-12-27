#include "admin.h"
enum {CEO，saleman,salemanager,engineer };
CEO::CEO(string name, int age, string gender, string tel, string account, int depnum)
{
	this->p_name = name;
	this->p_age = age;
	this->p_gender = gender;
	this->p_tel = tel;
	this->p_account = account;
	this->dep_num = depnum;
	for (int i = 0; i < 32; i++)
		this->situation[i] = 1;
}

void CEO::show_info()
{
	
	cout << this->p_account<<'\t' << this->p_name<<'\t' << this->p_age<<'\t' <<this->p_tel<<'\t'<< this->getdep(dep_num) << endl;
}

string CEO::getdep(int i)
{

	return string("总经理");
}

Salemanager::Salemanager(string name, int age, string gender, string tel, string account, int depnum)
{

	this->Post::p_name =name;
	this->Post::p_age = age;
	this->Post::p_gender = gender;
	this->Post::p_tel = tel;
	this->Post::p_account = account;
	this->Post::dep_num = depnum;
	for (int i = 0; i < 32; i++)
	{
		this->situation[i] = 0;//全部都先标记为未签到
	}
}


void Salemanager::show_info()
{
	
	cout << this->Post::p_account << '\t' << this->Post::p_name << '\t' << this->Post::p_age << '\t' << this->Post::p_tel << '\t' << this->getdep(dep_num) << endl;
}

string Salemanager::getdep(int i)
{
	return string("销售经理");
}
