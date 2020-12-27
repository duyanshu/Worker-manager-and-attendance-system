#include "post.h"

void Post::post_table()
{
	cout << "工号\t姓名\t年龄\t电话\t\t所在岗位" << endl;
}

string Post::getname()
{
	return string(this->p_name);
}

int Post::getage()
{
	return this->p_age;
}

string Post::getgender()
{
	return string(this->p_gender);
}

string Post::gettel()
{
	return string(this->p_tel);
}

string Post::getaccount()
{
	return string(this->p_account);
}

int* Post::get_situation()
{
	return this->situation;
}

int Post::get_situation(int today)
{
	return situation[today];
}

int Post::get_depnum()
{
	return Post::dep_num;
}

void Post::setname(string name)
{
	this->p_name = name;
}

void Post::setage(int age)
{
	this->p_age = age;
}

void Post::setgender(string gender)
{
	this->p_gender = gender;
}

void Post::settel(string tel)
{
	this->p_tel = tel;
}

void Post::set_depnum(int num)
{
	this->dep_num = num;
}

void Post::set_situation(int day, int s)
{
	//cout << day;
	this->situation[day] = s;
	//cout << situation[day];
}

void Post::setaccount(string accoun)
{
	this->p_account = accoun;
}




