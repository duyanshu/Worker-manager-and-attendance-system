## Welcome to 杜研书‘s GitHub Pages

### introduction 


The system is divided into attendance and management system two parts, can store the employee's number, name, gender, department, level, and wage calculation. Employees are divided into managers, technicians, salespeopes, and sales managers.
Define a class that records the employee's illness and vacation time. These include: the maximum number of days an employee can not work if he or she is ill, the number of days an employee has taken paid leave, and the number of days an employee can take paid leave. The company stipulates that paid leave cannot exceed 24 hours. Sickness can not work for more than 16 hours.
Design a program that manages the leave of company personnel and applies to inheritance, abstract classes, virtual functions, virtual base classes, polymorphisms, and input/output of files.


```javascript
Manager test;//定义对象
	re_login://重新登录接口
	cout << setw(30) << setfill('*') << "*" << " 欢迎登录 [人事] [工资] [考勤] 系统 " << setw(30) << setfill('*') << "* " << endl;
	Manager::show_time();
	cout << endl;
	cout << " " << setw(20) << setfill(' ') << " " << "请输入账号（工号）:"  ;
	Manager::check_account(test);
	cout << " " << setw(20) << setfill(' ') << " " << "       请输入密码:";//密码组成为，第一位部门编号，后面为工号
	char dep_num;//用于接收部门编号
	dep_num = Manager::check_password(test);	
	cout<<endl << "密码正确，";
	system("pause");
	system("cls");	
	if ((dep_num-48) == 1)
	{
		char choice;
			while (true)
			{
		menu_interface();
		cout << "请输入数字，进入相应功能:";
		cin >> choice;//接受用户选择的功能
		switch (choice-48)//将字符型转换为int型防止输入字母时程序崩溃
		{
		case 0:test.exitsyetem();//退出系统
			break;
		case 1:test.add_member();      //增加信息
			break;
		case 2:Post::post_table();  test.showinfo(); //显示信息
			break;
		case 3:  test.deletework();  //删除信息
			break;
		case 4:  test.revise_ifo(); //修改
			break;
		case 5:test.search_display();       //查找
			break;
		case 6:test.SortByAccount();//按编号排序
			break;
		case 7: system("cls"); goto re_login; //退出登录
			break;
		case 8:test.show_today_att();//今日考勤情况
		default :
			cout << "输入错误，重新输入";
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
				cout << "请输入数字，进入相应功能:";
				char choice;
				cin >> choice;
				switch (choice - 48)
				{
				case 0:test.exitsyetem();//退出系统
					break;
				case 1:test.sign(test);//今日打卡签到
					break;
				case 2:test.ask_for_leave();//请病假或事假
					break;
				case 3:test.enquire_days();//休假天数查询
					break;
				case 4:test.show_salay();//本月薪水查询
					break;
				case 5:system("cls"); goto re_login;//退出登录
					break;
				default:
					cout << "输入错误，重新输入";
					system("pause");
					system("cls");
				}
		}		
	}
```

# The Header file 1：manager.h
## The Header file 2: post.h
###  The Header file 3 and 4:admin.h ,worker.h 

## content
1.Description of basic functions
2.Design ideas


**First** and _Italic_ and `Code` text


For more details see [杜研书的主页](https://duyanshu.github.io).

### Under development...
