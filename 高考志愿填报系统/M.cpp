#include <iostream>
#include <graphics.h>
#include < conio.h >
#include <stdlib.h>
#include "UI.h"
using namespace std;
const int HEIGHT = 480, WIDTH = 640;
#define OK 1;
#define FALSE 0;
//IMAGE img[15];

struct STU {
	string name;
}s[100];

void Display_Account(Text_Id &k, int op, TCHAR ch) {
	if (op) {
		k.s1[k.length] = ch;
		k.length++;
	}
	else {
		cout << -1 << endl;
		cout <<"k.length: "<< k.length << endl;
		if (k.length == 0) return;
		k.s1[k.length - 1] = '\0';
		k.length--;
	}
}
void Display_Password(PassWord& k) {
	for (int i = 0; i < k.length; i++) {
		k.s2[i] = '*';
	}
	k.s2[k.length] = '\0';
}
void Trans(string& a, Text_Id& b) {
	for (int i = 0; i < b.length; i++) {
		a += b.s1[i];
	}
}
int login(IMAGE* img) {
	putimage(140, 330, &img[2]);
	EndBatchDraw();
	Sleep(300);
	putimage(140, 330, &img[0]);
	EndBatchDraw();
	return TRUE;
	//return judge(s1,s2);
}
void reset(TCHAR* a, int& length) {
	while (length >= 0) {
		a[length] = '\0';
		length--;
	}
	length = 0;
}
int InitUI(IMAGE* img, HWND& hwnd, int& id) {
	Text_Id pass;
	PassWord wa;
	//setcaption("初始化窗口");
	int Click = 0;  //确认点击的是框框还是登录/修改密码

	LOGFONT title, word, acc;

	BeginBatchDraw();             //开始作画
	TextKind(title, word, acc);
	setbkmode(TRANSPARENT);
	settextstyle(&title);
	setlinecolor(RGB(82, 85, 100));
	setfillcolor(RGB(82, 85, 100));
	fillroundrect(200, 50, 500, 100, 10, 10);
	outtextxy(200, 70, "上海教育考试院");
	settextstyle(&acc);
	fillroundrect(100, 140, 180, 240, 10, 10);
	fillroundrect(100, 240, 180, 340, 10, 10);
	outtextxy(100, 160, "账号");
	outtextxy(100, 240, "密码");
	putimage(200, 150, &img[11]);   //输入框一
	putimage(200, 240, &img[12]);   //输入框二
	putimage(510, 245, &img[19]);   //登录密码(隐藏)
	putimage(140, 330, &img[0]);   //登入
	putimage(340, 330, &img[6]);   //修改密码
	EndBatchDraw();
	bool act = true;// 窗口是否激活
	//bool viss = false;  //密码是否可见
	ExMessage msg;
	int op = 1, num = 0;
	//getmessage(EM_KEY);
	while (act) {
		while (peekmessage(&msg)) {
			BeginBatchDraw();
			switch (msg.message) {
			case WM_MOUSEMOVE:    //鼠标移动
				if (msg.x >= 200 && msg.x <= 546 && msg.y >= 150 && msg.y <= 188) {
					if (Click != 1) putimage(200, 150, &img[4]);
				}
				else if (msg.x >= 200 && msg.x <= 546 && msg.y >= 240 && msg.y <= 278) {
					if (Click != 2) putimage(200, 240, &img[4]);
				}
				else if (msg.x >= 140 && msg.x <= 288 && msg.y >= 330 && msg.y <= 379) {
					putimage(140, 330, &img[1]);
				}
				else if (msg.x >= 340 && msg.x <= 488 && msg.y >= 330 && msg.y <= 379) {
					putimage(340, 330, &img[7]);
				}
				else {
					if (Click != 1) {
						if (pass.length == 0) putimage(200, 150, &img[11]);
						else putimage(200, 150, &img[3]);
					}
					if (Click != 2) {
						if (wa.length == 0) putimage(200, 240, &img[12]);
						else putimage(200, 240, &img[3]);
					}
					putimage(140, 330, &img[0]);
					putimage(340, 330, &img[6]);
				}
				break;
			case WM_CHAR:         //字符串读入
				op = 1;
				if (msg.ch == 8) op = 0;
				if (Click == 1) Display_Account(pass, op, msg.ch);
				else if (Click == 2) {
					Display_Account(wa, op, msg.ch);
					if (wa.visableE == 0) Display_Password(wa);
				}
				break;
			case  WM_LBUTTONDOWN:            //鼠标点击
				if (msg.x >= 200 && msg.x <= 546 && msg.y >= 150 && msg.y <= 188) {
					putimage(200, 150, &img[5]);
					Click = 1;
					if (wa.length)putimage(200, 240, &img[3]);
					else putimage(200, 240, &img[12]);
				}
				else if (msg.x >= 200 && msg.x < 510 && msg.y >= 240 && msg.y <= 278) {
					putimage(200, 240, &img[5]);
					Click = 2;
					if (pass.length) putimage(200, 150, &img[3]);
					else putimage(200, 150, &img[11]);
				}
				else if (msg.x >= 510 && msg.x <=546 && msg.y >= 240 && msg.y <= 278) {  //隐藏密码界面
					putimage(510, 245, &img[18]);
					wa.visableE = !wa.visableE;
					Display_Password(wa);
					//cout << "wa.visableE: " << wa.visableE << endl;
					//cout << "wa.length" << wa.length << endl;
				}
				else if (msg.x >= 140 && msg.x <= 288 && msg.y >= 330 && msg.y <= 379) {
					putimage(140, 330, &img[2]);
					string s1, s2;
					Trans(s1, wa);
					Trans(s2, pass);
					login(img);        //登录的接口
					putimage(140, 330, &img[1]);
					Number k;
					k.Write_Number(Num);
					cout << "round1: " << endl;
					if (k.Match(s1,s2,id)) {
						id = 1;
						EndBatchDraw();
						return 2;
					}
					else {
						MessageBox(hwnd, "账号或密码输入错误!", "", MB_OK);
						reset(pass.s1, pass.length);
						reset(wa.s1, wa.length);
						Display_Account(pass);
						Display_Password(wa);
						fillrectangle(210, 160, 536, 175);
						fillrectangle(210, 250, 536, 265);
						if (Click != 1) putimage(200, 150, &img[12]);
						else putimage(200, 150, &img[5]);
						if (Click != 2)putimage(200, 240, &img[12]);
						else putimage(200, 240, &img[5]);
					}
				}
				else if (msg.x >= 340 && msg.x <= 488 && msg.y >= 330 && msg.y <= 379) {
					putimage(340, 330, &img[8]);
					EndBatchDraw();
					Sleep(200);
					putimage(340, 330, &img[7]);
					string s1, s2;
					Trans(s1, wa);
					Trans(s2, pass);
					Number k;
					k.Write_Number(Num);
					if (k.Match(s1, s2, id)) {
						EndBatchDraw();
						return 1;
					}
					else {
						MessageBox(hwnd, "账号或密码输入错误!", "", MB_OK);
						reset(pass.s1, pass.length);
						reset(wa.s1, wa.length);
						Display_Account(pass);
						Display_Password(wa);
						fillrectangle(210, 160, 536, 175);
						fillrectangle(210, 250, 536, 265);
						if (Click != 1) putimage(200, 150, &img[12]);
						else putimage(200, 150, &img[5]);
						if (Click != 2)putimage(200, 240, &img[12]);
						else putimage(200, 240, &img[5]);
					}
					//initchangeUI(s1,s2,img);
				}
				break;
			}
		}
		if (Click == 1) {
			fillrectangle(210, 160, 536, 175);
			int wid = textwidth(pass.s1);
			if (num < 10)putimage(210 + 2 + wid, 160, &img[9]);
			else putimage(210 + 2 + wid, 160, &img[10]);
			num++;
			num %= 20;
		}
		if (Click == 2) {
			fillrectangle(210, 250, 536, 265);
			int wid;
			if (wa.visableE) wid = textwidth(wa.s1);
			else wid = textwidth(wa.s2);
			if (num < 10)putimage(210 + 2 + wid, 250, &img[9]);
			else putimage(210 + 2 + wid, 250, &img[10]);
			num++;
			num %= 20;
		}
		if (pass.length > 20 || wa.length > 20) {
			MessageBox(hwnd, "输入账号或密码过长!!!", "", MB_OK);
			reset(pass.s1, pass.length);
			reset(wa.s1, wa.length);
			Display_Account(pass);
			Display_Password(wa);
			fillrectangle(210, 160, 536, 175);
			fillrectangle(210, 250, 536, 265);
			if (Click != 1) putimage(200, 150, &img[12]);
			else putimage(200, 150, &img[5]);
			if (Click != 2)putimage(200, 240, &img[12]);
			else putimage(200, 240, &img[5]);
			
		}
		if (wa.visableE) putimage(510, 245, &img[18]);
		else putimage(510, 245, &img[19]);
		settextstyle(&word);
		outtextxy(210, 160, pass.s1);
		if (wa.visableE) outtextxy(210, 250, wa.s1);
		else outtextxy(210, 250, wa.s2);
		EndBatchDraw();
		Sleep(20);
	}
	Sleep(10000);
	closegraph();
	return 0;
}
int main() {
	IMAGE img[40],imgschool1[40],imgschool2[40];
	HWND hwnd = initgraph(WIDTH, HEIGHT);
	bool CHOOSE = 1;
	//MoveWindow(hwnd,100, 50, true);
	setbkcolor(RGB(82, 85, 100));
	cleardevice();
	pic(img);
	schoolpic1(imgschool1);
	schoolpic2(imgschool2);
	int op = 0, id=2;
	while (1) {
		switch (op) {
		case 0:
			op = InitUI(img, hwnd, id);
			break;
		case 1:
			op = initchangeUI(img, hwnd, id);
			break;
		case 2:
			op = initShowMain(img,id,hwnd,CHOOSE);
			break;
		case 3:
			op = initShowScore(img, id);
			break;
		case 4:
			op = initShowPre(img,imgschool1, id);
			break;
		case 5:
			op = initShowCho(img, imgschool2, id, hwnd,CHOOSE);
			break;
		}
		cleardevice();
	}
	return 0;
}
