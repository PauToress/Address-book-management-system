#include<iostream>
 using  namespace std;
#include<string>
#define MAX  1000
 //1，封装一个shoumeau函数
 void showmeau()
 {
	 cout << "***************************************" << endl;
	 cout << " ******1,添加联系人 ******" << endl;
	 cout << " ******2,显示联系人 ******" << endl;
	 cout << " ******3,删除联系人 ******" << endl;
	 cout << " ******4,查找联系人 ******" << endl;
	 cout << " ******5,修改联系人 ******" << endl;
	 cout << " ******6,清空联系人******" << endl;
	 cout << " ******0,退出通讯录 ******" << endl;
	 cout << "**************************************" << endl;
 }
 //2，创建联系人结构体
 struct person 
 {
	 string m_name;//姓名
	 int m_sex;//1,男性 2,女性
	 int m_age;//年龄
	 string m_Addr;//家庭住址
	 string m_phone;//联系方式




 };
 //3,通讯录结构体；
 struct Addressbook
 {
	 struct person personarry[MAX];//一个容量为1000的联系人数组，每一个数组元素代表一个联系人结构体；
	 int m_size;//表示通讯录的大小
 };
 //4，封装一个传入联系人函数
 void addperson(Addressbook*abs)//用指针来接受结构体变量 Addressbook abs的地址
 {
	if(abs->m_size==MAX)
	 { 
		cout << "通讯录已满";
		return;
	}
	else {//添加姓名

		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personarry[abs->m_size].m_name = name;
		//添加性别
		cout << "请输入性别" << endl;
		int sex=0;
		cin >> sex;
		abs->personarry[abs->m_size].m_sex = sex;
		//添加年龄
		cout << "请输入年龄" << endl;
		int age=0;
		cin >> age;
		abs->personarry[abs->m_size].m_age = age;
		//家庭住址
		 cout << "请输入家庭住址" << endl;
		string Addr;
		cin >>Addr;
		abs->personarry[abs->m_size].m_Addr = Addr;
		//联系方式
		cout << "请输入联系方式" << endl;
		string phone;
		cin >> phone;
		abs->personarry[abs->m_size].m_phone= phone;
		abs->m_size++;
		cout << "添加成功！" << endl;
		system("pause");//请按任意键
		system("cls");//清屏操作符
	}




 }
 //显示联系人，建立一个显示联系人的函数
 void showperson(Addressbook*abs)
 {
	 if (abs->m_size == 0)
	 {
		 cout << "当前的记录为空" << endl;
	 }
	 else {
		 for (int i = 0; i < abs->m_size; i++) {
			 //显示联系人的姓名
			 cout << "姓名：" << abs->personarry[i].m_name << "/t"; //这里可以把换行符换成制表符，即/t

			 //显示联系人的性别
			 cout << "性别：" << (abs->personarry[i].m_sex ==1 ? "男":"女")<< "/t";

			 //显示联系人的年龄
			 cout << "年龄：" << abs->personarry[i].m_age << "/t";
			 //显示联系人的家庭住址
			 cout << "家庭住址：" << abs->personarry[i].m_Addr << "/t";
			 //显示联系人的联系方式
			 cout << "联系方式：" << abs->personarry[i].m_phone << "/t";

		 }

	 }

	 system("pause");
	 system("cls");

 }
 //6,创建删除联系人的函数
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
 //7,删除联系人2.0
 void deleteperson(Addressbook* abs)
 {
	 cout << "请输入要删除的联系人" << endl;
	 string name;
	 cin >> name;
	 int on = isExist(abs, name);
	 for (int i = 0; i < abs->m_size; i++) {

		 if (on != -1) {

			 abs->personarry[i] = abs->personarry[i + 1];
			 abs->m_size--;
			 cout << "删除成功" << endl;

		 }
		 else {


			 cout << "查无此人";
		 }
		 system("pause");
		 system("cls");


		 }





 }
 //8,查找特定联系人的信息
 void findperson(Addressbook* abs) {

	 cout << "请输入你想寻找的联系人的信息" << endl;
	 string name;
	 cin >> name;
	 int on = isExist(abs, name);
	 if (on!= -1) {

		 cout << "姓名：" << abs->personarry[on].m_name << "/t";
		 cout << "性别" << abs->personarry[on].m_sex << "/t";
		 cout << "年龄：" << abs->personarry[on].m_age << "/t";
		 cout << "家庭住址：" << abs->personarry[on].m_Addr << "/t";
		 cout << "联系方式：" << abs->personarry[on].m_phone << "/t";
		
	 }
	 else {


		 cout << "查无此人" << endl;

	 }
	 system("pause");
	 system("cls");



 }
 //9,修改联系人信息
 void modifyperson(Addressbook* abs) {
	 cout << "请输入修改联系人的姓名" << endl;
	 string name;
	 cin >> name;
	 int on = isExist(abs, name);
	 if (on != -1) {

		 string name;
		 cout << "请输入联系人姓名" << endl;
		 cin >> name;
		 abs->personarry[on].m_name = name;
		 //输入性别
		 cout << "请输入性别" << endl;
		 cout << "1---男" << endl;
		 cout << "2---女" << endl;

		 int sex=0;
		 cin >> sex;
		 while (true) {

			 if (sex == 1 || sex == 2) {

				 abs->personarry[on].m_sex = sex;
				 cout << "输入正确" << endl;
				 break;




			 }
			 
				 cout << "输入错误，请重新输入" << endl;
			 
		 }
		 cout << "请输入年龄" << endl;
		 int age = 0;
		 cin >> age;
		 abs->personarry[on].m_age = age;
		 cout << "请输入家庭住址" << endl;
		 string Addr;
		 cin >> Addr;
		 abs->personarry[on].m_Addr = Addr;
		 cout << "联系方式" << endl;
		 string phone;
		 cin >> phone;
		 abs->personarry[on].m_phone = phone;


		 cout << "修改成功!" << endl;

	 }
	 else {
		 cout << "查无此人" << endl;

	 }
	 system("pause");
	 system("cls");


	 }
 //10,封装清空联系人的函数
 void cleanperson(Addressbook* abs)
 {
	 cout << "确定要清空所有联系人吗？" << endl;
	 cout << "下面输入选择，输入1为确定，输入2为否定" << endl;
	 int option;
	 cin >> option;


		
	if(option==1)
	{ 
		abs->m_size = 0;
		cout << "通讯录已被清空" << endl;
		system("pasue");
		system("cls");
	}
	else {

		cout << "通讯录未被删除" << endl;

	}
	system("pause");
	system("cls");





 }





 


 int main() 
 {
	 //创建一个通讯录结构体变量，以便于在main函数中展示出来
	 Addressbook abs;
	 //初始化当前人员个数
	 abs.m_size = 0;


	 while (true)//利用while循环实现菜单重复出现，从而确保当计算机输入0时结束循环，输入其他数字是继续循环
	 {
		 showmeau();
		 int select = 0;
		 cin >> select;
		 switch (select)
		 {
		 case 0:
			 cout << "欢迎下次使用" << endl;
			 system("pause");
			 return 0;
			 break;

		 case 1:
		 addperson(&abs);//如果用值传递，则不能修饰实参，因此需要添加取地址符
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
