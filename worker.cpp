#include "worker.h"

Saleman::Saleman(string name, int age, string gender, string tel, string account, int depnum)
{
	this->p_name = name;
	this->p_age = age;
	this->p_gender = gender;
	this->p_tel = tel;
	this->p_account = account;
	this->dep_num = depnum;
	for (int i = 0; i < 32; i++)
	{
		this->situation[i] = 0;//全部都先标记为未签到
	}
}

void Saleman::show_info()
{
	cout << this->p_account << '\t' << this->p_name << '\t' << this->p_age << '\t' << this->p_tel << '\t' << this->getdep(dep_num) << endl;
}

string Saleman::getdep(int i)
{
	return string("销售人员");
}

Engineer::Engineer(string name, int age, string gender, string tel, string account, int depnum)
{
	this->p_name = name;
	this->p_age = age;
	this->p_gender = gender;
	this->p_tel = tel;
	this->p_account = account;
	this->dep_num = depnum;
	for (int i = 0; i < 32; i++)
	{
		this->situation[i] = 0;//全部都先标记为未签到
	}
}

void Engineer::show_info()
{
	cout << this->p_account << '\t' << this->p_name << '\t' << this->p_age << '\t' << this->p_tel << '\t' << this->getdep(dep_num) << endl;
}

string Engineer::getdep(int i)
{
	return string("技术人员");
}
