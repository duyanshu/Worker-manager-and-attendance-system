#include <iostream>
#include "manager.h"
//#include <Windows.h>
#include "admin.h"
//#include "worker.h"
#include <iomanip>

using namespace std;
int main()
{
	Manager test;//�������
	re_login://���µ�¼�ӿ�
	cout << setw(30) << setfill('*') << "*" << " ��ӭ��¼ [����] [����] [����] ϵͳ " << setw(30) << setfill('*') << "* " << endl;
	Manager::show_time();
	cout << endl;
	cout << " " << setw(20) << setfill(' ') << " " << "�������˺ţ����ţ�:"  ;
	Manager::check_account(test);
	cout << " " << setw(20) << setfill(' ') << " " << "       ����������:";//�������Ϊ����һλ���ű�ţ�����Ϊ����
	char dep_num;//���ڽ��ղ��ű��
	dep_num = Manager::check_password(test);
	
	cout<<endl << "������ȷ��";
	system("pause");
	system("cls");
	
	if ((dep_num-48) == 1)
	{
		char choice;
	
		while (true)
	
		{
		menu_interface();
		cout << "���������֣�������Ӧ����:";
		cin >> choice;//�����û�ѡ��Ĺ���
		switch (choice-48)//���ַ���ת��Ϊint�ͷ�ֹ������ĸʱ�������
		{
		case 0:test.exitsyetem();//�˳�ϵͳ
			break;
		case 1:test.add_member();      //������Ϣ
			break;
		case 2:Post::post_table();  test.showinfo(); //��ʾ��Ϣ
			break;
		case 3:  test.deletework();  //ɾ����Ϣ
			break;
		case 4:  test.revise_ifo(); //�޸�
			break;
		case 5:test.search_display();       //����
			break;
		case 6:test.SortByAccount();//���������
			break;
		case 7: system("cls"); goto re_login; //�˳���¼
			break;
		case 8:test.show_today_att();//���տ������
		default :
			cout << "���������������";
			system("pause");
			system("cls");
		}
		}
	}	
	else
	{
		while (true)
		{
		test.attendance_interface(test);
				cout << "���������֣�������Ӧ����:";
				char choice;
				cin >> choice;
				switch (choice - 48)
				{
				case 0:test.exitsyetem();//�˳�ϵͳ
					break;
				case 1:test.sign(test);//���մ�ǩ��
					break;
				case 2:test.ask_for_leave();//�벡�ٻ��¼�
					break;
				case 3:test.enquire_days();//�ݼ�������ѯ
					break;
				case 4:test.show_salay();//����нˮ��ѯ
					break;
				case 5:system("cls"); goto re_login;//�˳���¼
					break;
				default:
					cout << "���������������";
					system("pause");
					system("cls");

				}
		}
		
	}
	
	
	//������Ϣ��ʾ����
	/*Post* sale = new Salemanager("������", 20, "��", "15059807469", "10002", 1);
	sale->post_table();
	sale->show_info();
	delete (sale); 

	Post* ceo = new CEO("������", 20, "��", "15059807469", "10002", 1);
	ceo->show_info();
	delete(ceo);
	  
	Post* saleman =new Saleman("������", 20, "��", "15059807469", "10003", 1);
	saleman->show_info();
	delete(saleman);*/
	
	system("pause"); 
	return 0;
}