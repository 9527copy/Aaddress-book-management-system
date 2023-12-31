#include <iostream>
using namespace std;
#include<string>

#define MAX 1000

struct Person
{
	string m_Name;

	int m_Sex;

	int m_Age;

	string m_Phone;

	string m_Addr;
};

struct Addressbooks
{
	struct Person personArray[MAX];

	int m_Size;
};

void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//性别
		int sex=0;
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入" << endl;
			}
		}
		

		//年龄
		int age;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//电话
		string phone;
		cout << "请输入电话号码：" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//地址
		string address;
		cout << "请输入地址：" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		abs->m_Size++;

		cout << "添加成功" << endl;
	}
	system("pause");
	system("cls");
}

void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "抱歉，通讯录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex==1?"男":"女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "地址：" << abs->personArray[i].m_Addr << endl;
			
		}
		
	}
	system("pause");
	system("cls");
}

int inExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
		
	}
	return -1;
}

void deletePerson(Addressbooks* abs)
{
	cout << "请输入想要删除联系人的姓名" << endl;
	string name;
	cin >> name;

	int ret = inExist(abs, name);

	if (ret != -1)
	{
		for (int i = ret; i <abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		cout << "删除成功" << endl;
		abs->m_Size--;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	
	
	system("pause");
	system("cls");
}

void findPerson(Addressbooks* abs)
{
	cout << "请输入您想要查找联系人的姓名" << endl;
	string name;
	cin >> name;
	int ret = inExist(abs, name);

	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "地址：" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您想要修改联系人的姓名" << endl;
	string name;
	cin >> name;

	int ret = inExist(abs, name);

	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//性别
		int sex = 0;
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入" << endl;
			}
		}


		//年龄
		int age;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//电话
		string phone;
		cout << "请输入电话号码：" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//地址
		string address;
		cout << "请输入地址：" << endl;
		cin >> address;
		abs->personArray[ret].m_Addr = address;


		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "联系人已全部清空" << endl;

	system("pause");
	system("cls");
}

void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;

}
int main()
{

	int select = 0;

	Addressbooks abs;

	abs.m_Size = 0;
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			return 0;
			system("pause");
		default:
			break;
		}
	}



	system("pause");
	return 0;
}