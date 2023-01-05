#pragma once
#include <iostream>
#include < conio.h >
#include <graphics.h>
#include <fstream>
#include<windows.h>


#define n 6//学生信息个数（根据txt文件里的数量来定义）
#define m 34//去年分数线学校个数（根据txt文件里的数量来定义）


using namespace std;
void pic(IMAGE* img);
void schoolpic1(IMAGE* imgschool1);
void schoolpic2(IMAGE* imgschool2);
void TextKind(LOGFONT& title, LOGFONT& acc, LOGFONT& word);
void ShowScoreKind(LOGFONT& sc);
void TopWord(LOGFONT& totitle);
int initchangeUI(IMAGE* img,HWND &hwnd,int&id);
int initShowMain(IMAGE*img,int&id,HWND& hwnd,bool& choose);        //主页
int initShowScore(IMAGE* img, int& id);       //功能1:显示考生成绩
int initShowPre(IMAGE* img,IMAGE*imgschool1,int& id);         //功能2:显示去年各学校分数线
int initShowCho(IMAGE* img,IMAGE*imgschool2, int& id, HWND& hwnd,bool& choose);         //功能3:填报专业
void ShowTime(int&id);
class Text_Id {
public:
	int length;
	TCHAR s1[100];
	Text_Id() {
		memset(s1, 0, sizeof(s1));
		length = 0;
	}
};

class PassWord :public Text_Id {
public:
	bool visableE;
	TCHAR s2[100];
	using Text_Id::Text_Id;
	PassWord() {
		visableE = 0;
		memset(s2, 0, sizeof(s2));
	}
};

class Student_Score {//查询自己成绩
public:
	string num;          //考号
	string name;    //姓名
	string score[12];
	string Chinese;    //语文
	string Math;       //数学
	string English;    //英语
	string Physical;   //物理
	string Chemical;   //化学
	string Biological; //生物
	string Political;  //政治
	string History;    //历史
	string Geographic; //地理
public:
	void Write_Score(Student_Score stu[]);//读入成绩
	void Lookup_Score(Student_Score stu[], int& id);//查询成绩
};

class Number {//登录,修改密码
public:
	string number;//考生账号
	string password;//考生密码
	string nu;//登录账号
	string pw;//登录密码
public:
	string npw1;//输入新密码
	string npw2;//再次输入新密码
	int id;//登录的考生对应编号
	void Write_Number(Number num[]);//读入账号，密码
	void Login(Number num[]);//登录
	bool Match(string nu, string pw, int& id);//匹配
	bool Match_password(Number num[], string npw1, string npw2);//判断密码是否相等
	void Change_password(Number num[], string npw2, int& id);//修改密码
};

class Score_Line {//去年分数线
public:
	string school;//大学名字
	string A;//A类分数线
	string B;//B类分数线
	string C;//C类分数线
public:
	void Write_Line(Score_Line Line[]);//读入去年分数线
	void Lookup_Line(Score_Line Line[], int& id);//查询去年分数线
};

extern Student_Score stu[100];
extern Number Num[100];
extern Score_Line Line[100];

void Trans(string& a, Text_Id& b);
void Display_Password(PassWord& k);
void Display_Account(Text_Id& k, int op=0, TCHAR ch=0);
void Exchange(TCHAR* k, int& length, int num,int wei);
//void exit(int value);//退出函数
//void Write_Score(Student_Score stu[]);
//void Lookup_Score(Student_Score stu[], int& id);
//void Write_Number(Number num[]);
//bool Match(string nu, string pw, int& id);
//void Change_password(Number num[], int& id);
