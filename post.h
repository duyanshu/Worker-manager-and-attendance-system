#pragma once
#include <iostream>
using namespace std;
#include <string>
//虚基类
class Post {
protected:
	string p_name;
	int p_age;
	string p_gender;
	string p_tel;
	string p_account;
	int dep_num;
	string password;//每个人都有自己的密码，总经理能增删信息，其他人能签到
	int situation[32];//数组中0，代表未签到，1代表签到，2代表病假,3代表事假（可带薪休假）
public:
	virtual void show_info() = 0;//设计纯虚函数，让子类重写这个函数，而不能用父类生成对象，实现多态性
	virtual string getdep(int) = 0;//获取职位名称
	static void post_table();//显示个人信息表格
	string getname();
	int getage();
	string getgender();
	string gettel();
	string getaccount();
	int* get_situation();
	int get_situation(int today);//重载函数，返回今日状态
	int get_depnum();
	void setname(string name);
	void setage(int age);
	void setgender(string gender);
	void settel(string tel);
	void setaccount(string accoun);
	void set_depnum(int num);
	void set_situation(int day,int s);//传入日期和要修改的状态编号

};