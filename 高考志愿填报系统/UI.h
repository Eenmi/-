#pragma once
#include <iostream>
#include < conio.h >
#include <graphics.h>
#include <fstream>
#include<windows.h>


#define n 6//ѧ����Ϣ����������txt�ļ�������������壩
#define m 34//ȥ�������ѧУ����������txt�ļ�������������壩


using namespace std;
void pic(IMAGE* img);
void schoolpic1(IMAGE* imgschool1);
void schoolpic2(IMAGE* imgschool2);
void TextKind(LOGFONT& title, LOGFONT& acc, LOGFONT& word);
void ShowScoreKind(LOGFONT& sc);
void TopWord(LOGFONT& totitle);
int initchangeUI(IMAGE* img,HWND &hwnd,int&id);
int initShowMain(IMAGE*img,int&id,HWND& hwnd,bool& choose);        //��ҳ
int initShowScore(IMAGE* img, int& id);       //����1:��ʾ�����ɼ�
int initShowPre(IMAGE* img,IMAGE*imgschool1,int& id);         //����2:��ʾȥ���ѧУ������
int initShowCho(IMAGE* img,IMAGE*imgschool2, int& id, HWND& hwnd,bool& choose);         //����3:�רҵ
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

class Student_Score {//��ѯ�Լ��ɼ�
public:
	string num;          //����
	string name;    //����
	string score[12];
	string Chinese;    //����
	string Math;       //��ѧ
	string English;    //Ӣ��
	string Physical;   //����
	string Chemical;   //��ѧ
	string Biological; //����
	string Political;  //����
	string History;    //��ʷ
	string Geographic; //����
public:
	void Write_Score(Student_Score stu[]);//����ɼ�
	void Lookup_Score(Student_Score stu[], int& id);//��ѯ�ɼ�
};

class Number {//��¼,�޸�����
public:
	string number;//�����˺�
	string password;//��������
	string nu;//��¼�˺�
	string pw;//��¼����
public:
	string npw1;//����������
	string npw2;//�ٴ�����������
	int id;//��¼�Ŀ�����Ӧ���
	void Write_Number(Number num[]);//�����˺ţ�����
	void Login(Number num[]);//��¼
	bool Match(string nu, string pw, int& id);//ƥ��
	bool Match_password(Number num[], string npw1, string npw2);//�ж������Ƿ����
	void Change_password(Number num[], string npw2, int& id);//�޸�����
};

class Score_Line {//ȥ�������
public:
	string school;//��ѧ����
	string A;//A�������
	string B;//B�������
	string C;//C�������
public:
	void Write_Line(Score_Line Line[]);//����ȥ�������
	void Lookup_Line(Score_Line Line[], int& id);//��ѯȥ�������
};

extern Student_Score stu[100];
extern Number Num[100];
extern Score_Line Line[100];

void Trans(string& a, Text_Id& b);
void Display_Password(PassWord& k);
void Display_Account(Text_Id& k, int op=0, TCHAR ch=0);
void Exchange(TCHAR* k, int& length, int num,int wei);
//void exit(int value);//�˳�����
//void Write_Score(Student_Score stu[]);
//void Lookup_Score(Student_Score stu[], int& id);
//void Write_Number(Number num[]);
//bool Match(string nu, string pw, int& id);
//void Change_password(Number num[], int& id);
