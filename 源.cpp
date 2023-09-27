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
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//�Ա�
		int sex=0;
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
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
				cout << "������������������" << endl;
			}
		}
		

		//����
		int age;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//�绰
		string phone;
		cout << "������绰���룺" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//��ַ
		string address;
		cout << "�������ַ��" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		abs->m_Size++;

		cout << "��ӳɹ�" << endl;
	}
	system("pause");
	system("cls");
}

void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��Ǹ��ͨѶ¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex==1?"��":"Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "��ַ��" << abs->personArray[i].m_Addr << endl;
			
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
	cout << "��������Ҫɾ����ϵ�˵�����" << endl;
	string name;
	cin >> name;

	int ret = inExist(abs, name);

	if (ret != -1)
	{
		for (int i = ret; i <abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		cout << "ɾ���ɹ�" << endl;
		abs->m_Size--;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	
	
	system("pause");
	system("cls");
}

void findPerson(Addressbooks* abs)
{
	cout << "����������Ҫ������ϵ�˵�����" << endl;
	string name;
	cin >> name;
	int ret = inExist(abs, name);

	if (ret != -1)
	{
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "��ַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks* abs)
{
	cout << "����������Ҫ�޸���ϵ�˵�����" << endl;
	string name;
	cin >> name;

	int ret = inExist(abs, name);

	if (ret != -1)
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//�Ա�
		int sex = 0;
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
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
				cout << "������������������" << endl;
			}
		}


		//����
		int age;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//�绰
		string phone;
		cout << "������绰���룺" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//��ַ
		string address;
		cout << "�������ַ��" << endl;
		cin >> address;
		abs->personArray[ret].m_Addr = address;


		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "��ϵ����ȫ�����" << endl;

	system("pause");
	system("cls");
}

void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
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
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;
			system("pause");
		default:
			break;
		}
	}



	system("pause");
	return 0;
}