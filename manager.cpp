#include "manager.h"
#include "stdio.h"
#include "time.h"
#include <conio.h>
#include <string>
#include <string.h>
Manager::Manager()
{
	cnt = 0;
	tm localtime;//tm结构体调用现在的时间
	time_t t;//与标准时间的差
	t = time(NULL);
	localtime_s(&localtime, &t);
	today = localtime.tm_mday;
	this->Worker_Array = NULL;
	ifstream ifs;
	ifs.open(FILE, ios::in);
	
	char c;//用于判断文件是否为空
	ifs >> c;
	if (ifs.eof())
	{
		cout << "职工信息文件为空"<<endl;
		this->Worker_Array = NULL;
		this->fileisempty = true;//文件为空的标志
	}
	else {
		cout << "公司总人数为" <<this->getnum() << "人" << endl;
	}
	
	//cout << "构造函数"<<endl;
	ifs.close();
	//初始化员工信息和考勤表
	this->init_Emp();
	this->init_attendance();
	//save_att_file();
}



Manager::~Manager()
{
	if (this->Worker_Array != NULL)
	{
		delete[] this->Worker_Array;
		this->Worker_Array = NULL;
	}
}

void Manager::exitsyetem()
{	system("cls");
cout << "欢迎下次使用," ;
	system("pause");
	
	exit(0);
}
void menu_interface()
{
	
	cout<<setw(30)<<setfill('*')<<"*"<<" 欢迎使用 [人事] [工资] [考勤] 系统 "<<setw(30)<<setfill('*')<<"* "<<endl;
	cout << setw(95)  << setfill('_')<< "_" <<endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "0.退出管理系统" << setw(39) << setfill('<') << "<" <<"||"<<endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "1.增加员工信息" << setw(39) << setfill('<') << "<" << "||" << endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "2.显示员工信息" << setw(39) << setfill('<') << "<" << "||" << endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "3.删除离职员工" << setw(39) << setfill('<') << "<" << "||" << endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "4.修改职工信息" << setw(39) << setfill('<') << "<" << "||" << endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "5.查找职工信息" << setw(39) << setfill('<') << "<" << "||" << endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "6.按照编号排序" << setw(39) << setfill('<') << "<" << "||" << endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "7.退出重新登录" << setw(39) << setfill('<') << "<" << "||" << endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "8.今日考勤情况" << setw(39) << setfill('<') << "<" << "||" << endl;
	cout<< setw(95) << setfill('-') << "-" << endl;
}

void Manager::attendance_interface(Manager& test)
{
	cout << "您好，" << this->Worker_Array[search(login_account)]->getname()<<endl;
	cout << setw(30) << setfill('*') << "*" << " 欢迎使用  [工资]  [考勤] 系统 " << setw(35) << setfill('*') << "* " << endl;
	cout << setw(95) << setfill('*') << "*" << endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "0.退出考勤系统" << setw(39) << setfill('<') << "<" << "||" << endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "1.今日打卡签到" << setw(39) << setfill('<') << "<" << "||" << endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "2.请病假或事假" << setw(39) << setfill('<') << "<" << "||" << endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "3.休假天数查询" << setw(39) << setfill('<') << "<" << "||" << endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "4.本月薪水查询" << setw(39) << setfill('<') << "<" << "||" << endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "5.退出重新登录" << setw(39) << setfill('<') << "<" << "||" << endl;
}

void Manager::add_member()
{
	int addNum;//用户要添加的员工数量
	cout << "请输入要添加员工的人数:";
	cin >> addNum;
	while (addNum <= 0)
	{
		cout << "输入有误，请重新输入" << endl;
		cin >> addNum;
	}
	if (addNum > 0)//添加
	{
		//计算所需开辟新空间的大小
		int newsize = this->cnt + addNum;//数组所需要的大小为原来的+新增的人数
		Post** New_Array =new Post* [newsize*2];//用一个Post**的指针接收一个Post*的数据，该数据存在Post*的数组中
		//若原来有数据，则创建一个新数组，把原来的数据拷贝到新数组中
		for (int i = 0; i < cnt; i++)
		{
			New_Array[i] = this->Worker_Array[i];//拷贝原有的数据
		}
		for (int j = 0; j < addNum; j++)
		{
			//添加新数据
			string name;
			int age;
			string gender;
			string tel;
			string account;
			int dep_num;//用以上信息创建对应的对象
			cout << "第" << (j+1) << "个员工的姓名为：";
			cin >> name;			
			cout << "年龄：";
			cin >> age;

			cout << "性别：1.男 2.女"<<endl;
			int intgen = 1;
			cin >> intgen;
			while (intgen != 1 && intgen != 2)
			{
				cout << "输入有误，请重新输入:";
				cin >> intgen;
			}
			if (intgen == 2) gender = "女";
			else gender = "男";
			cout << "电话：";
			cin >> tel;
			cout << "工号：";//待完善功能：判断工号是否冲突，冲突则重新输入
			cin >> account;
			while (this->search(account) != -1)
			{
				cout << "该工号已存在，请重现输入:";
				cin >> account;
			}

			cout << "请选择职工岗位：1.总经理 2.销售经理 3.销售人员 4.技术人员 "<<endl;
			cin >> dep_num;
			while(dep_num < 1 || dep_num>4)//防止用户输入错误
			{
				cout << "对不起输入有误，请重新输入" << endl;
				cin >> dep_num;
			}
			Post* newwork=NULL;
			switch (dep_num)
			{
			case 1:newwork = new CEO(name, age, gender, tel, account, dep_num); break;
			case 2:newwork = new Salemanager(name, age, gender, tel, account, dep_num); break;
			case 3:newwork = new Saleman(name, age, gender, tel, account, dep_num); break;
			case 4:newwork = new Engineer(name, age, gender, tel, account, dep_num); break;
			}
			New_Array[j + cnt] = newwork;
			//New_Array存储的是newwork的地址所以不能将newwork delete掉
		}	
			delete[]this->Worker_Array;//将Worker_Array**指向新的数组
			this->cnt = newsize;
			this->Worker_Array =New_Array;

			this->fileisempty = false;//更新文件不为空
		cout << "成功添加" << addNum << "人" << endl;
	}
	this->save_file();
	this->getnum();   //调用该函数更新数组中的信息
	this->init_Emp();//调用该函数更新数组中的信息
	system("pause");
	system("cls");
}

void Manager::add_situation()//今日签到
{

}

void Manager::save_file()
{
	ofstream ofs;
	ofs.open(FILE, ios::app);
	for (int i = 0; i < this->cnt; i++)
	{
		ofs << this->Worker_Array[i]->getname() << ' '
			<< this->Worker_Array[i]->getage()<< ' '
			<< this->Worker_Array[i]->getgender() << ' '
			<< this->Worker_Array[i]->gettel() << ' '
			<< this->Worker_Array[i]->getaccount()<< ' ' 
			<< this->Worker_Array[i]->get_depnum() << ' ' << endl;
	}
	ofs.close();
}

int Manager::getnum()
{
	int num=0;
	
	ifstream ifs;
	ifs.open(FILE, ios::in);
	string line;
	while (getline(ifs,line))  //计算数据有几行
	{
		num++;		
	}
	
	totalnum = num;
	return num;
}

void Manager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILE, ios::in);
	string p_name;
	int p_age;
	string p_gender;
	string p_tel;
	string p_account;
	int dep_num;
	
	int i=0;//标记数组位置
	this->Worker_Array = new Post * [totalnum*2];
	while (ifs >> p_name && ifs >> p_age && ifs >> p_gender && ifs >> p_tel && ifs >> p_account && ifs >> dep_num)
	{
		Post* inwork=NULL;
		switch (dep_num)
		{
		case 1: inwork = new CEO(p_name, p_age, p_gender, p_tel, p_account, dep_num); break;
		case 2:inwork = new Salemanager(p_name, p_age, p_gender, p_tel, p_account, dep_num); break;
		case 3:inwork = new Saleman(p_name, p_age, p_gender, p_tel, p_account, dep_num); break;
		case 4:inwork = new Engineer(p_name, p_age, p_gender, p_tel, p_account, dep_num); break;
		}
		this->Worker_Array[i++] = inwork;
		//inwork->show_info();
		//this->Worker_Array[0]->show_info();
	}
	
	ifs.close();
}

//void Manager::test()
//{
//	this->Worker_Array[1]->show_info();
//}

void Manager::showinfo()
{
	for (int i = 0; i < this->totalnum; i++)
	{
		this->Worker_Array[i]->show_info();
	}
	system("pause"); system("cls");
}

int Manager::search(string &account)
{
	int index=-1 ;

	for (int i = 0; i < this->totalnum; i++)
	{
		if (this->Worker_Array[i]->getaccount() == account)
		{
			index = i;
			break;
		}

	}

	return index;
}

void Manager::deletework()
{
	bool flag=false;
	string account;
	cout << "您想删除员工的编号为（按0取消）：";
	cin >> account;
	if (account == "0")
	{
		system("pause");
		system("cls");
		return;
	}
	int index = search(account);
	while(index == -1)
	{
		cout << "对不起，该员工不存在." << endl;
		cout << "请重新输入：";
		cin >> account;
		index = search(account);
	}
	if(index!=-1)
	{
		Post::post_table();
		this->Worker_Array[index]->show_info();
		cout << endl << "确认删除该员工的所有信息吗？ 按 0取消 1确认 :";
		cin >> flag;
	}
	if (flag)
	{
		ofstream ofs(FILE, ios::out | ios::trunc);

		for (int i = 0; i < this->totalnum; i++)
		{
			if (this->Worker_Array[i]->getaccount() == account) { continue; }//重写一个文件时跳过该对象
			ofs << this->Worker_Array[i]->getname() << ' '
				<< this->Worker_Array[i]->getage() << ' '
				<< this->Worker_Array[i]->getgender() << ' '
				<< this->Worker_Array[i]->gettel() << ' '
				<< this->Worker_Array[i]->getaccount() << ' '
				<< this->Worker_Array[i]->get_depnum() << ' ' << endl;
		}
		ofs.close();
		this->getnum();//读取新文件的行数
		this->init_Emp();//读取新文件并写入数组；
		cout << "删除成功！" << endl;
		
	}
	out1:
		system("pause");
		system("cls");
}

void Manager::search_display()
{
	string account;
	cout << "您想查找的职工编号为：";
	cin >> account;
	int index = search(account);
	if (index == -1)
	{
		cout << "对不起，该员工不存在。" << endl;
	}
	else
	{
		Post::post_table();
		this->Worker_Array[index]->show_info();
	}
	system("pause");
	system("cls");
}

void Manager::show_time()
{
	struct tm local;//结构体的指针
	time_t t;//与标准时间相差的秒数
	t = time(NULL);
	 localtime_s(&local, &t);
	cout << "现在是星期"<<local.tm_wday<<" 北京时间" << local.tm_hour << ":" << local.tm_min;

}

void Manager::check_account(Manager& test)
{	
	string account;
	cin >> account;
	while (test.search(account) == -1)
	{
		cout << "对不起，输入有误请重新输入！";
		Sleep(5000);//暂停五秒
		cout << "请输入：";
		cin >> account;
	}
	test.login_account = account;//记录登录员工的账号
}

char Manager::check_password(Manager& test)
{
	char c;
	char passwor[100] = { '\0' };
	int index = 0;
	while (1)
	{
		c = _getch();
		if (c == '\b')
		{
			if (index != 0)
			{
				cout << '\b' << ' ' << '\b';
				index--;
			}
		}
		else if (c == '\r')
		{
			passwor[index] = '\0';
			break;
		}
		else
		{
			cout << '*';
			passwor[index++] = c;
		}
	}
	
	string password(&passwor[1], &passwor[strlen(passwor)]);
	
		while (test.search(password) == -1)
	{
	try{
		cout <<endl<< "对不起，密码错误请重新输入！";
		Sleep(3000);//暂停3秒
		cout << "请输入：";
		password = write_password();
		goto out;
	}
	catch(char)
	{
		return c;
	}
	}
	while ((passwor[0]- 48) != test.Worker_Array[test.search(password)]->get_depnum())
	{
		cout <<endl<< "对不起，密码错误请重新输入！";
		Sleep(3000);//暂停3秒
		cout << "请输入：";
		password=write_password();		
		goto out;
	}
	out:	
	return passwor[0];
}

char* Manager::write_password()
{
	char c;
	char passwor[100] = { '\0' };
	int index = 0;
	while (1)
	{
		c = _getch();
		if (c == '\b')
		{
			if (index != 0)
			{
				cout << '\b' << ' ' << '\b';
				index--;
			}
		}
		else if (c == '\r')
		{
			passwor[index] = '\0';
			break;
		}
		else
		{
			cout << '*';
			passwor[index++] = c;
		}
	}
	throw(c);
	return passwor;
}

void Manager::save_att_file()
{
	ofstream ofs(FILE2,  ios::trunc);
	if (!ofs)
	{
		cout << "文件打开失败。" << endl;
	}
	for (int i = 0; i < this->totalnum; i++)
	{
		ofs << this->Worker_Array[i]->getaccount()<<' ';
		int *a=this->Worker_Array[i]->get_situation();
		for (int j = 1; j <= 31; j++)
		{
			ofs << a[j]<<' ';
			//if (j == 21)cout << a[j]<<' ';
		}
		ofs << endl;
	}

	ofs.close();
}

void Manager::init_attendance()
{
	ifstream ifs(FILE2, ios::in);
	string account;
	int situation;
	for (int i = 0; i < this->totalnum; i++)
	{
		ifs>>account;
		for (int j = 1; j <= 31; j++)
		{
			ifs >> situation;
			this->Worker_Array[search(account)]->set_situation(j, situation);
		}
	}
	ifs.close();
}

void Manager::revise_ifo()
{
	cout << "您想修改的职工编号为：";
	string account;
	cin >> account;
	if (this->search(account) == -1)
	{
		cout << "对不起，该员工不存在。" << endl;
		return;
	}
	cout << "该员工信息如下" << endl;
	Post::post_table();
	this->Worker_Array[search(account)]->show_info();
	cout << "要修改的信息是：1.姓名 2.年龄 3.电话 4.所属部门" << endl << "请输入一个相应编号：";
	int choice;
	cin >> choice;
	string name;
	int age;
	string gender;
	string tel;
	string account1;
	int dep_num;//用以上信息创建对应的对象
	switch (choice)
	{
	case 1:cout << "新姓名："; cin >> name; this->Worker_Array[search(account)]->setname(name);
		break;
	case 2:cout << "新年龄："; cin >> age; this->Worker_Array[search(account)]->setage(age);
		break;
	case 3:cout << "新电话："; cin >> tel; this->Worker_Array[search(account)]->settel(tel);
		break;	
	case 4:cout << "新部门代码："; cin >> dep_num; this->Worker_Array[search(account)]->set_depnum(dep_num);
		break;
	default:return;
	}
	ofstream ofs(FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->totalnum; i++)
	{
		//重写文件
		ofs << this->Worker_Array[i]->getname() << ' '
			<< this->Worker_Array[i]->getage() << ' '
			<< this->Worker_Array[i]->getgender() << ' '
			<< this->Worker_Array[i]->gettel() << ' '
			<< this->Worker_Array[i]->getaccount() << ' '
			<< this->Worker_Array[i]->get_depnum() << ' ' << endl;
	}
	ofs.close();
	this->init_Emp();//读取新文件并写入数组；
	cout << "修改成功！" << endl;
	system("pause");
	system("cls");
}

void Manager::SortByAccount()
{	
	Post* tem = NULL;
	for(int i=0;i<this->totalnum-1;i++)
		for (int j = 0; j < this->totalnum - 1 - i; j++)
		{
			if (this->Worker_Array[j]->getaccount() > this->Worker_Array[j + 1]->getaccount())
			{
				tem = Worker_Array[j];
				Worker_Array[j] = Worker_Array[j + 1];
				Worker_Array[j + 1] = tem;
			}
		}
	Post::post_table();
	for (int i = 0; i < this->totalnum; i++)
	{
		this->Worker_Array[i]->show_info();
	}
	system("pause"); system("cls");

}

void Manager::sign(Manager&test)
{
		this->Worker_Array[search(login_account)]->set_situation(today, 1);//签到
	this->save_att_file();
	cout << "签到成功！"<<endl;
	system("pause");
	system("cls");
}

void Manager::show_today_att()
{
	cout << "今日签到情况如下：" << endl;
	cout << "姓名\t" << "工号\t" << "签到情况\t" << endl;
	for (int i = 0; i < totalnum; i++)
	{
		cout << this->Worker_Array[i]->getname() << '\t' << this->Worker_Array[i]->getaccount() << '\t';
		switch (this->Worker_Array[i]->get_situation(today))
		{
		case 0:cout << "未签到" << endl; break;
		case 1:cout << "已签到" << endl; break;
		case 2:cout << "病假中" << endl; break;
		case 3:cout << "事假中" << endl; break;
		}
	}
	system("pause");
	system("cls");
}

void Manager::ask_for_leave()
{
	cout << "您想请假的类型是？1.病假 2.事假" << endl;
	int choice;
	cin >> choice;
	choice += 1;
	cout << "请假天数(单次不超过五天):" ;
	int days;
	cin >> days;
	while (days > 5)
	{
		cout << "输入天数过大，请重新输入:";
		cin >> days;
	}
	for(int i=0;i<days;i++)
	this->Worker_Array[search(login_account)]->set_situation(today+i, choice);
	this->save_att_file();
	cout << "请假成功！" << endl;
	system("pause");
	system("cls");
}

void Manager::count_leave_day()
{
	cnt_sick = 0;
	cnt_leave = 0;
	for (int i = 1; i <= 31; i++)
	{
		if (this->Worker_Array[search(login_account)]->get_situation(i) == 2)
			cnt_sick++;
		if (this->Worker_Array[search(login_account)]->get_situation(i) == 3)
			cnt_leave++;
	}
	
}

void Manager::enquire_days()
{
	count_leave_day();
	int hour1;
	//cout << cnt_sick << " " << cnt_leave;
	hour1 = 24 - 8 * cnt_leave;
	if (hour1 < 0) {
		hour1 = 0;
	}
	cout << "您本月剩余带薪休假小时数为:" << hour1 << "小时"<<'('<<hour_to_day(hour1)<<"天)"<<endl;
	int hour2;
	hour2 = 16 - 8 * cnt_sick;
	if (hour2 < 0)
	{
		hour2 = 0;
	}

	cout << "您本月剩余生病可以带薪休假小时数为：" << hour2 << "小时" << '(' << hour_to_day(hour2) << "天)" <<endl;
	system("pause");
	system("cls");
}
template <typename T>
double Manager::hour_to_day(T hour)
{
	return hour/8.0;
}

void Manager::show_salay()
{
	const int base_salay = 3000;
	const int pre_day_salary = 50;
	int att_day = 0;
	int sum = 0;
	cout << "本月基础工资\t" << "绩效考勤\t" << "总计\t" << endl;
	for (int i = 1; i <= 31; i++)
	{
		if (this->Worker_Array[search(login_account)]->get_situation(i) == 1)
		{
			att_day++;
		}
		
	}
	if (cnt_leave > 3)
	{
		cnt_leave = 3;
	}
	if (cnt_sick > 2)
	{
		cnt_sick = 2;
	}
	att_day += cnt_leave + cnt_sick;
	sum = att_day * pre_day_salary;
	cout << base_salay << "\t\t" << sum << "\t\t" << (sum + base_salay) << "\t\t"<<endl;
	system("pause");
	system("cls");
}

