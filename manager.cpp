#include "manager.h"
#include "stdio.h"
#include "time.h"
#include <conio.h>
#include <string>
#include <string.h>
Manager::Manager()
{
	cnt = 0;
	tm localtime;//tm�ṹ��������ڵ�ʱ��
	time_t t;//���׼ʱ��Ĳ�
	t = time(NULL);
	localtime_s(&localtime, &t);
	today = localtime.tm_mday;
	this->Worker_Array = NULL;
	ifstream ifs;
	ifs.open(FILE, ios::in);
	
	char c;//�����ж��ļ��Ƿ�Ϊ��
	ifs >> c;
	if (ifs.eof())
	{
		cout << "ְ����Ϣ�ļ�Ϊ��"<<endl;
		this->Worker_Array = NULL;
		this->fileisempty = true;//�ļ�Ϊ�յı�־
	}
	else {
		cout << "��˾������Ϊ" <<this->getnum() << "��" << endl;
	}
	
	//cout << "���캯��"<<endl;
	ifs.close();
	//��ʼ��Ա����Ϣ�Ϳ��ڱ�
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
cout << "��ӭ�´�ʹ��," ;
	system("pause");
	
	exit(0);
}
void menu_interface()
{
	
	cout<<setw(30)<<setfill('*')<<"*"<<" ��ӭʹ�� [����] [����] [����] ϵͳ "<<setw(30)<<setfill('*')<<"* "<<endl;
	cout << setw(95)  << setfill('_')<< "_" <<endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "0.�˳�����ϵͳ" << setw(39) << setfill('<') << "<" <<"||"<<endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "1.����Ա����Ϣ" << setw(39) << setfill('<') << "<" << "||" << endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "2.��ʾԱ����Ϣ" << setw(39) << setfill('<') << "<" << "||" << endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "3.ɾ����ְԱ��" << setw(39) << setfill('<') << "<" << "||" << endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "4.�޸�ְ����Ϣ" << setw(39) << setfill('<') << "<" << "||" << endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "5.����ְ����Ϣ" << setw(39) << setfill('<') << "<" << "||" << endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "6.���ձ������" << setw(39) << setfill('<') << "<" << "||" << endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "7.�˳����µ�¼" << setw(39) << setfill('<') << "<" << "||" << endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "8.���տ������" << setw(39) << setfill('<') << "<" << "||" << endl;
	cout<< setw(95) << setfill('-') << "-" << endl;
}

void Manager::attendance_interface(Manager& test)
{
	cout << "���ã�" << this->Worker_Array[search(login_account)]->getname()<<endl;
	cout << setw(30) << setfill('*') << "*" << " ��ӭʹ��  [����]  [����] ϵͳ " << setw(35) << setfill('*') << "* " << endl;
	cout << setw(95) << setfill('*') << "*" << endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "0.�˳�����ϵͳ" << setw(39) << setfill('<') << "<" << "||" << endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "1.���մ�ǩ��" << setw(39) << setfill('<') << "<" << "||" << endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "2.�벡�ٻ��¼�" << setw(39) << setfill('<') << "<" << "||" << endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "3.�ݼ�������ѯ" << setw(39) << setfill('<') << "<" << "||" << endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "4.����нˮ��ѯ" << setw(39) << setfill('<') << "<" << "||" << endl;
	cout << "||" << setw(39) << setfill('>') << ">" << "5.�˳����µ�¼" << setw(39) << setfill('<') << "<" << "||" << endl;
}

void Manager::add_member()
{
	int addNum;//�û�Ҫ��ӵ�Ա������
	cout << "������Ҫ���Ա��������:";
	cin >> addNum;
	while (addNum <= 0)
	{
		cout << "������������������" << endl;
		cin >> addNum;
	}
	if (addNum > 0)//���
	{
		//�������迪���¿ռ�Ĵ�С
		int newsize = this->cnt + addNum;//��������Ҫ�Ĵ�СΪԭ����+����������
		Post** New_Array =new Post* [newsize*2];//��һ��Post**��ָ�����һ��Post*�����ݣ������ݴ���Post*��������
		//��ԭ�������ݣ��򴴽�һ�������飬��ԭ�������ݿ�������������
		for (int i = 0; i < cnt; i++)
		{
			New_Array[i] = this->Worker_Array[i];//����ԭ�е�����
		}
		for (int j = 0; j < addNum; j++)
		{
			//���������
			string name;
			int age;
			string gender;
			string tel;
			string account;
			int dep_num;//��������Ϣ������Ӧ�Ķ���
			cout << "��" << (j+1) << "��Ա��������Ϊ��";
			cin >> name;			
			cout << "���䣺";
			cin >> age;

			cout << "�Ա�1.�� 2.Ů"<<endl;
			int intgen = 1;
			cin >> intgen;
			while (intgen != 1 && intgen != 2)
			{
				cout << "������������������:";
				cin >> intgen;
			}
			if (intgen == 2) gender = "Ů";
			else gender = "��";
			cout << "�绰��";
			cin >> tel;
			cout << "���ţ�";//�����ƹ��ܣ��жϹ����Ƿ��ͻ����ͻ����������
			cin >> account;
			while (this->search(account) != -1)
			{
				cout << "�ù����Ѵ��ڣ�����������:";
				cin >> account;
			}

			cout << "��ѡ��ְ����λ��1.�ܾ��� 2.���۾��� 3.������Ա 4.������Ա "<<endl;
			cin >> dep_num;
			while(dep_num < 1 || dep_num>4)//��ֹ�û��������
			{
				cout << "�Բ���������������������" << endl;
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
			//New_Array�洢����newwork�ĵ�ַ���Բ��ܽ�newwork delete��
		}	
			delete[]this->Worker_Array;//��Worker_Array**ָ���µ�����
			this->cnt = newsize;
			this->Worker_Array =New_Array;

			this->fileisempty = false;//�����ļ���Ϊ��
		cout << "�ɹ����" << addNum << "��" << endl;
	}
	this->save_file();
	this->getnum();   //���øú������������е���Ϣ
	this->init_Emp();//���øú������������е���Ϣ
	system("pause");
	system("cls");
}

void Manager::add_situation()//����ǩ��
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
	while (getline(ifs,line))  //���������м���
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
	
	int i=0;//�������λ��
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
	cout << "����ɾ��Ա���ı��Ϊ����0ȡ������";
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
		cout << "�Բ��𣬸�Ա��������." << endl;
		cout << "���������룺";
		cin >> account;
		index = search(account);
	}
	if(index!=-1)
	{
		Post::post_table();
		this->Worker_Array[index]->show_info();
		cout << endl << "ȷ��ɾ����Ա����������Ϣ�� �� 0ȡ�� 1ȷ�� :";
		cin >> flag;
	}
	if (flag)
	{
		ofstream ofs(FILE, ios::out | ios::trunc);

		for (int i = 0; i < this->totalnum; i++)
		{
			if (this->Worker_Array[i]->getaccount() == account) { continue; }//��дһ���ļ�ʱ�����ö���
			ofs << this->Worker_Array[i]->getname() << ' '
				<< this->Worker_Array[i]->getage() << ' '
				<< this->Worker_Array[i]->getgender() << ' '
				<< this->Worker_Array[i]->gettel() << ' '
				<< this->Worker_Array[i]->getaccount() << ' '
				<< this->Worker_Array[i]->get_depnum() << ' ' << endl;
		}
		ofs.close();
		this->getnum();//��ȡ���ļ�������
		this->init_Emp();//��ȡ���ļ���д�����飻
		cout << "ɾ���ɹ���" << endl;
		
	}
	out1:
		system("pause");
		system("cls");
}

void Manager::search_display()
{
	string account;
	cout << "������ҵ�ְ�����Ϊ��";
	cin >> account;
	int index = search(account);
	if (index == -1)
	{
		cout << "�Բ��𣬸�Ա�������ڡ�" << endl;
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
	struct tm local;//�ṹ���ָ��
	time_t t;//���׼ʱ����������
	t = time(NULL);
	 localtime_s(&local, &t);
	cout << "����������"<<local.tm_wday<<" ����ʱ��" << local.tm_hour << ":" << local.tm_min;

}

void Manager::check_account(Manager& test)
{	
	string account;
	cin >> account;
	while (test.search(account) == -1)
	{
		cout << "�Բ��������������������룡";
		Sleep(5000);//��ͣ����
		cout << "�����룺";
		cin >> account;
	}
	test.login_account = account;//��¼��¼Ա�����˺�
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
		cout <<endl<< "�Բ�������������������룡";
		Sleep(3000);//��ͣ3��
		cout << "�����룺";
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
		cout <<endl<< "�Բ�������������������룡";
		Sleep(3000);//��ͣ3��
		cout << "�����룺";
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
		cout << "�ļ���ʧ�ܡ�" << endl;
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
	cout << "�����޸ĵ�ְ�����Ϊ��";
	string account;
	cin >> account;
	if (this->search(account) == -1)
	{
		cout << "�Բ��𣬸�Ա�������ڡ�" << endl;
		return;
	}
	cout << "��Ա����Ϣ����" << endl;
	Post::post_table();
	this->Worker_Array[search(account)]->show_info();
	cout << "Ҫ�޸ĵ���Ϣ�ǣ�1.���� 2.���� 3.�绰 4.��������" << endl << "������һ����Ӧ��ţ�";
	int choice;
	cin >> choice;
	string name;
	int age;
	string gender;
	string tel;
	string account1;
	int dep_num;//��������Ϣ������Ӧ�Ķ���
	switch (choice)
	{
	case 1:cout << "��������"; cin >> name; this->Worker_Array[search(account)]->setname(name);
		break;
	case 2:cout << "�����䣺"; cin >> age; this->Worker_Array[search(account)]->setage(age);
		break;
	case 3:cout << "�µ绰��"; cin >> tel; this->Worker_Array[search(account)]->settel(tel);
		break;	
	case 4:cout << "�²��Ŵ��룺"; cin >> dep_num; this->Worker_Array[search(account)]->set_depnum(dep_num);
		break;
	default:return;
	}
	ofstream ofs(FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->totalnum; i++)
	{
		//��д�ļ�
		ofs << this->Worker_Array[i]->getname() << ' '
			<< this->Worker_Array[i]->getage() << ' '
			<< this->Worker_Array[i]->getgender() << ' '
			<< this->Worker_Array[i]->gettel() << ' '
			<< this->Worker_Array[i]->getaccount() << ' '
			<< this->Worker_Array[i]->get_depnum() << ' ' << endl;
	}
	ofs.close();
	this->init_Emp();//��ȡ���ļ���д�����飻
	cout << "�޸ĳɹ���" << endl;
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
		this->Worker_Array[search(login_account)]->set_situation(today, 1);//ǩ��
	this->save_att_file();
	cout << "ǩ���ɹ���"<<endl;
	system("pause");
	system("cls");
}

void Manager::show_today_att()
{
	cout << "����ǩ��������£�" << endl;
	cout << "����\t" << "����\t" << "ǩ�����\t" << endl;
	for (int i = 0; i < totalnum; i++)
	{
		cout << this->Worker_Array[i]->getname() << '\t' << this->Worker_Array[i]->getaccount() << '\t';
		switch (this->Worker_Array[i]->get_situation(today))
		{
		case 0:cout << "δǩ��" << endl; break;
		case 1:cout << "��ǩ��" << endl; break;
		case 2:cout << "������" << endl; break;
		case 3:cout << "�¼���" << endl; break;
		}
	}
	system("pause");
	system("cls");
}

void Manager::ask_for_leave()
{
	cout << "������ٵ������ǣ�1.���� 2.�¼�" << endl;
	int choice;
	cin >> choice;
	choice += 1;
	cout << "�������(���β���������):" ;
	int days;
	cin >> days;
	while (days > 5)
	{
		cout << "����������������������:";
		cin >> days;
	}
	for(int i=0;i<days;i++)
	this->Worker_Array[search(login_account)]->set_situation(today+i, choice);
	this->save_att_file();
	cout << "��ٳɹ���" << endl;
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
	cout << "������ʣ���н�ݼ�Сʱ��Ϊ:" << hour1 << "Сʱ"<<'('<<hour_to_day(hour1)<<"��)"<<endl;
	int hour2;
	hour2 = 16 - 8 * cnt_sick;
	if (hour2 < 0)
	{
		hour2 = 0;
	}

	cout << "������ʣ���������Դ�н�ݼ�Сʱ��Ϊ��" << hour2 << "Сʱ" << '(' << hour_to_day(hour2) << "��)" <<endl;
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
	cout << "���»�������\t" << "��Ч����\t" << "�ܼ�\t" << endl;
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

