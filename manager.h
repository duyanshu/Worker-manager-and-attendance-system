#pragma once//防止头文件重复包含
#include <iostream>
#include <iomanip>
#include "post.h"
#include "worker.h"
#include "admin.h"
#include <fstream>
#include <Windows.h>
#define FILE "worker_ifo.txt"
#define FILE2 "attendance.txt"

using namespace std;
class Manager 
{
public:
	Manager();	
	 ~Manager();
	void exitsyetem();//退出
	friend void menu_interface();//菜单界面
	void attendance_interface(Manager& test);//考勤界面
	void add_member();//添加成员
	void add_situation();//签到
	void save_file();//追加方式保存文件
	int getnum();//更新人数
	void init_Emp();//从文件中读取职工信息并更新数组
	//void test();//测试函数
	void showinfo();  //显示所有员工信息
	int search(string &account);//按编号查找，返回数组下标
	void deletework();//删除员工
	void search_display();//按编号查找
	static void show_time();//显示现在的时间
	static void check_account(Manager& test);
	static char check_password(Manager& test);
	static char* write_password();//星号方式写密码5
	void save_att_file();//保存考勤信息到文件的函数
	void init_attendance();//从文件中读取考勤信息
	void revise_ifo();//修改员工信息
	void SortByAccount();//按编号排序
	void sign(Manager& test);//签到
	void show_today_att();//显示今日考勤情况
	void ask_for_leave();//请假
	void count_leave_day();//计算请假时间
	void enquire_days();//查询带薪休假天数
	template <typename T>
	double hour_to_day(T hour);//小时转化为天
	void show_salay();
protected:
	
	int cnt;//记录新增员工人数
	int totalnum;//员工总数
	int onlinenum;
	int leavenum;
	bool fileisempty;
	int today;//今天日期
	Post** Worker_Array;//对象指针数组的指针，用于添加员工，用于保存父类Post*所动态分配的子类对象指针
	string login_account;
	int cnt_sick;
	int cnt_leave;
};
void menu_interface();
