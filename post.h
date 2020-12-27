#pragma once
#include <iostream>
using namespace std;
#include <string>
//�����
class Post {
protected:
	string p_name;
	int p_age;
	string p_gender;
	string p_tel;
	string p_account;
	int dep_num;
	string password;//ÿ���˶����Լ������룬�ܾ�������ɾ��Ϣ����������ǩ��
	int situation[32];//������0������δǩ����1����ǩ����2������,3�����¼٣��ɴ�н�ݼ٣�
public:
	virtual void show_info() = 0;//��ƴ��麯������������д����������������ø������ɶ���ʵ�ֶ�̬��
	virtual string getdep(int) = 0;//��ȡְλ����
	static void post_table();//��ʾ������Ϣ���
	string getname();
	int getage();
	string getgender();
	string gettel();
	string getaccount();
	int* get_situation();
	int get_situation(int today);//���غ��������ؽ���״̬
	int get_depnum();
	void setname(string name);
	void setage(int age);
	void setgender(string gender);
	void settel(string tel);
	void setaccount(string accoun);
	void set_depnum(int num);
	void set_situation(int day,int s);//�������ں�Ҫ�޸ĵ�״̬���

};