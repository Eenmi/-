#include <iostream>
#include < conio.h >
#include <graphics.h>
#include "UI.h"
Student_Score stu[100];
Number Num[100];
Score_Line Line[100];
#define n 6
#define m 34
void Student_Score::Write_Score(Student_Score stu[]) {//读入考生成绩文件
	ifstream in("考生成绩.txt");
	for (int i = 0; i < n; i++) {
		in >> stu[i].num >> stu[i].name;
		for (int j = 0; j <= 10; j++)
			in >> stu[i].score[j];
	}
	in.close();
	//cin.get();
}
void Student_Score::Lookup_Score(Student_Score stu[], int& id) {//查询考生成绩函数
	if (id != -1) {
		//输出对应学生成绩
		//考号 姓名 语文 数学 英语 物理 化学 生物 政治 历史 地理
		cout << stu[id].num << "\t" << stu[id].name << "\t" << stu[id].Chinese << "\t" << stu[id].Math << "\t" << stu[id].English << "\t" << stu[id].Physical << "\t" << stu[id].Chemical << "\t" << stu[id].Biological << "\t" << stu[id].Political << "\t" << stu[id].History << "\t" << stu[id].Geographic << endl;
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------登录,修改密码类的成员函数-----------------------------------------------------------------------------------
void Number::Write_Number(Number num[]) {//读入考生账号密码文件
	ifstream in("考生账号密码.txt");
	for (int i = 0; i < n; i++)
		in >> num[i].number >> num[i].password;
	cout << num[0].number << num[0].password << endl;
	in.close();
	cout << 2 << endl;
	//cin.get();
	cout << 1 << endl;
}
bool Number::Match(string pw, string nu, int& id) {//匹配函数
	int i;
	for (i = 0; i < n; i++) {
		cout << Num[i].number << " " << Num[i].password << endl;
		if (nu == Num[i].number && pw == Num[i].password) {//登录成功
			id = i;
			return TRUE;
			break;
		}
	}
	return FALSE;
}
//void Login(Number num[]) {//登录函数
//	cin >> num->nu;//输入账号
//	cin >> num->pw;//输入密码
//	Match(num->nu, num->pw, num->id);
//}
void Number::Change_password(Number num[], string npw2, int& id) {//修改密码函数
	cout << "id: " << id << endl;
	if (id != -1) {
		ofstream out("考生账号密码.txt");
		for (int i = 0; i < n; i++) {
			cout << num[i].number << " " << num[i].password << "\n";
			if (i != id)
				out << num[i].number << " " << num[i].password << "\n";
			else if (i == id)
				out << num[i].number << " " << npw2 << "\n";
			
			//cin.get();
		}
		out.close();
	}
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------查询去年分数线类的成员函数----------------------------------------------------------------------------------
void Score_Line::Write_Line(Score_Line Line[]) {//读入去年分数线文件
	ifstream in("去年分数线.txt");
	for (int i = 0; i < m; i++)
		in >> Line[i].school >> Line[i].A >> Line[i].B >> Line[i].C;
	in.close();
	//cin.get();
}
//void Lookup_Line(Score_Line Line[], int& id) {//查询去年分数线函数
//	if (id != -1) {
//		int i = 0;
//		while (i < m) {
//			//去年录取分数线为
//						//大学名称 A类最低分 B类最低分 C类最低分
//			cout << Line[i].school << "\t" << "\t" << Line[i].A << "\t" << "\t" << Line[i].B << "\t" << "\t" << Line[i].C << endl;
//			i++;
//		}
//	}
//}
