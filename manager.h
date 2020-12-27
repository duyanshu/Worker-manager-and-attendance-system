#pragma once//��ֹͷ�ļ��ظ�����
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
	void exitsyetem();//�˳�
	friend void menu_interface();//�˵�����
	void attendance_interface(Manager& test);//���ڽ���
	void add_member();//��ӳ�Ա
	void add_situation();//ǩ��
	void save_file();//׷�ӷ�ʽ�����ļ�
	int getnum();//��������
	void init_Emp();//���ļ��ж�ȡְ����Ϣ����������
	//void test();//���Ժ���
	void showinfo();  //��ʾ����Ա����Ϣ
	int search(string &account);//����Ų��ң����������±�
	void deletework();//ɾ��Ա��
	void search_display();//����Ų���
	static void show_time();//��ʾ���ڵ�ʱ��
	static void check_account(Manager& test);
	static char check_password(Manager& test);
	static char* write_password();//�Ǻŷ�ʽд����5
	void save_att_file();//���濼����Ϣ���ļ��ĺ���
	void init_attendance();//���ļ��ж�ȡ������Ϣ
	void revise_ifo();//�޸�Ա����Ϣ
	void SortByAccount();//���������
	void sign(Manager& test);//ǩ��
	void show_today_att();//��ʾ���տ������
	void ask_for_leave();//���
	void count_leave_day();//�������ʱ��
	void enquire_days();//��ѯ��н�ݼ�����
	template <typename T>
	double hour_to_day(T hour);//Сʱת��Ϊ��
	void show_salay();
protected:
	
	int cnt;//��¼����Ա������
	int totalnum;//Ա������
	int onlinenum;
	int leavenum;
	bool fileisempty;
	int today;//��������
	Post** Worker_Array;//����ָ�������ָ�룬�������Ա�������ڱ��游��Post*����̬������������ָ��
	string login_account;
	int cnt_sick;
	int cnt_leave;
};
void menu_interface();
