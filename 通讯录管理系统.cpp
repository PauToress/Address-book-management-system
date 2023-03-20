#include<iostream>
 using  namespace std;
#include<string>
#define MAX  1000
 //1����װһ��shoumeau����
 void showmeau()
 {
	 cout << "***************************************" << endl;
	 cout << " ******1,�����ϵ�� ******" << endl;
	 cout << " ******2,��ʾ��ϵ�� ******" << endl;
	 cout << " ******3,ɾ����ϵ�� ******" << endl;
	 cout << " ******4,������ϵ�� ******" << endl;
	 cout << " ******5,�޸���ϵ�� ******" << endl;
	 cout << " ******6,�����ϵ��******" << endl;
	 cout << " ******0,�˳�ͨѶ¼ ******" << endl;
	 cout << "**************************************" << endl;
 }
 //2��������ϵ�˽ṹ��
 struct person 
 {
	 string m_name;//����
	 int m_sex;//1,���� 2,Ů��
	 int m_age;//����
	 string m_Addr;//��ͥסַ
	 string m_phone;//��ϵ��ʽ




 };
 //3,ͨѶ¼�ṹ�壻
 struct Addressbook
 {
	 struct person personarry[MAX];//һ������Ϊ1000����ϵ�����飬ÿһ������Ԫ�ش���һ����ϵ�˽ṹ�壻
	 int m_size;//��ʾͨѶ¼�Ĵ�С
 };
 //4����װһ��������ϵ�˺���
 void addperson(Addressbook*abs)//��ָ�������ܽṹ����� Addressbook abs�ĵ�ַ
 {
	if(abs->m_size==MAX)
	 { 
		cout << "ͨѶ¼����";
		return;
	}
	else {//�������

		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personarry[abs->m_size].m_name = name;
		//����Ա�
		cout << "�������Ա�" << endl;
		int sex=0;
		cin >> sex;
		abs->personarry[abs->m_size].m_sex = sex;
		//�������
		cout << "����������" << endl;
		int age=0;
		cin >> age;
		abs->personarry[abs->m_size].m_age = age;
		//��ͥסַ
		 cout << "�������ͥסַ" << endl;
		string Addr;
		cin >>Addr;
		abs->personarry[abs->m_size].m_Addr = Addr;
		//��ϵ��ʽ
		cout << "��������ϵ��ʽ" << endl;
		string phone;
		cin >> phone;
		abs->personarry[abs->m_size].m_phone= phone;
		abs->m_size++;
		cout << "��ӳɹ���" << endl;
		system("pause");//�밴�����
		system("cls");//����������
	}




 }
 //��ʾ��ϵ�ˣ�����һ����ʾ��ϵ�˵ĺ���
 void showperson(Addressbook*abs)
 {
	 if (abs->m_size == 0)
	 {
		 cout << "��ǰ�ļ�¼Ϊ��" << endl;
	 }
	 else {
		 for (int i = 0; i < abs->m_size; i++) {
			 //��ʾ��ϵ�˵�����
			 cout << "������" << abs->personarry[i].m_name << "/t"; //������԰ѻ��з������Ʊ������/t

			 //��ʾ��ϵ�˵��Ա�
			 cout << "�Ա�" << (abs->personarry[i].m_sex ==1 ? "��":"Ů")<< "/t";

			 //��ʾ��ϵ�˵�����
			 cout << "���䣺" << abs->personarry[i].m_age << "/t";
			 //��ʾ��ϵ�˵ļ�ͥסַ
			 cout << "��ͥסַ��" << abs->personarry[i].m_Addr << "/t";
			 //��ʾ��ϵ�˵���ϵ��ʽ
			 cout << "��ϵ��ʽ��" << abs->personarry[i].m_phone << "/t";

		 }

	 }

	 system("pause");
	 system("cls");

 }
 //6,����ɾ����ϵ�˵ĺ���
 int isExist(Addressbook* abs,string name)
 {
	 for (int i = 0; i < abs->m_size; i++) {


		 if (abs->personarry[i].m_name == name) {


			 return i;

		 }
		 else {
			 return -1;

		 }

	 }


 }
 //7,ɾ����ϵ��2.0
 void deleteperson(Addressbook* abs)
 {
	 cout << "������Ҫɾ������ϵ��" << endl;
	 string name;
	 cin >> name;
	 int on = isExist(abs, name);
	 for (int i = 0; i < abs->m_size; i++) {

		 if (on != -1) {

			 abs->personarry[i] = abs->personarry[i + 1];
			 abs->m_size--;
			 cout << "ɾ���ɹ�" << endl;

		 }
		 else {


			 cout << "���޴���";
		 }
		 system("pause");
		 system("cls");


		 }





 }
 //8,�����ض���ϵ�˵���Ϣ
 void findperson(Addressbook* abs) {

	 cout << "����������Ѱ�ҵ���ϵ�˵���Ϣ" << endl;
	 string name;
	 cin >> name;
	 int on = isExist(abs, name);
	 if (on!= -1) {

		 cout << "������" << abs->personarry[on].m_name << "/t";
		 cout << "�Ա�" << abs->personarry[on].m_sex << "/t";
		 cout << "���䣺" << abs->personarry[on].m_age << "/t";
		 cout << "��ͥסַ��" << abs->personarry[on].m_Addr << "/t";
		 cout << "��ϵ��ʽ��" << abs->personarry[on].m_phone << "/t";
		
	 }
	 else {


		 cout << "���޴���" << endl;

	 }
	 system("pause");
	 system("cls");



 }
 //9,�޸���ϵ����Ϣ
 void modifyperson(Addressbook* abs) {
	 cout << "�������޸���ϵ�˵�����" << endl;
	 string name;
	 cin >> name;
	 int on = isExist(abs, name);
	 if (on != -1) {

		 string name;
		 cout << "��������ϵ������" << endl;
		 cin >> name;
		 abs->personarry[on].m_name = name;
		 //�����Ա�
		 cout << "�������Ա�" << endl;
		 cout << "1---��" << endl;
		 cout << "2---Ů" << endl;

		 int sex=0;
		 cin >> sex;
		 while (true) {

			 if (sex == 1 || sex == 2) {

				 abs->personarry[on].m_sex = sex;
				 cout << "������ȷ" << endl;
				 break;




			 }
			 
				 cout << "�����������������" << endl;
			 
		 }
		 cout << "����������" << endl;
		 int age = 0;
		 cin >> age;
		 abs->personarry[on].m_age = age;
		 cout << "�������ͥסַ" << endl;
		 string Addr;
		 cin >> Addr;
		 abs->personarry[on].m_Addr = Addr;
		 cout << "��ϵ��ʽ" << endl;
		 string phone;
		 cin >> phone;
		 abs->personarry[on].m_phone = phone;


		 cout << "�޸ĳɹ�!" << endl;

	 }
	 else {
		 cout << "���޴���" << endl;

	 }
	 system("pause");
	 system("cls");


	 }
 //10,��װ�����ϵ�˵ĺ���
 void cleanperson(Addressbook* abs)
 {
	 cout << "ȷ��Ҫ���������ϵ����" << endl;
	 cout << "��������ѡ������1Ϊȷ��������2Ϊ��" << endl;
	 int option;
	 cin >> option;


		
	if(option==1)
	{ 
		abs->m_size = 0;
		cout << "ͨѶ¼�ѱ����" << endl;
		system("pasue");
		system("cls");
	}
	else {

		cout << "ͨѶ¼δ��ɾ��" << endl;

	}
	system("pause");
	system("cls");





 }





 


 int main() 
 {
	 //����һ��ͨѶ¼�ṹ��������Ա�����main������չʾ����
	 Addressbook abs;
	 //��ʼ����ǰ��Ա����
	 abs.m_size = 0;


	 while (true)//����whileѭ��ʵ�ֲ˵��ظ����֣��Ӷ�ȷ�������������0ʱ����ѭ�����������������Ǽ���ѭ��
	 {
		 showmeau();
		 int select = 0;
		 cin >> select;
		 switch (select)
		 {
		 case 0:
			 cout << "��ӭ�´�ʹ��" << endl;
			 system("pause");
			 return 0;
			 break;

		 case 1:
		 addperson(&abs);//�����ֵ���ݣ���������ʵ�Σ������Ҫ���ȡ��ַ��
		 break;

		 case 2:
			 showperson(&abs);
			 break;

		 case 3:
			 deleteperson(&abs);
			 break;
		 case 4:
			 findperson(&abs);
			 break;
		 case 5:
			 modifyperson(&abs);
			 break;
		 case 6:
			 cleanperson(&abs);
			 break;
		 default:break;

		 }




	 }
	
	
	 system("pause");
	 return 0;

 }
