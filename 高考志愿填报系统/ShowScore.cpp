#include <iostream>
#include < conio.h >
#include <graphics.h>
#include "UI.h"
string k[12] = { "语文","数学","英语","物理","地理","生物","化学","政治","历史","附加分","总分" };
int initShowScore(IMAGE* img, int& id) {
	BeginBatchDraw();
	putimage(0, 0, &img[33]);
	Student_Score a;
	a.Write_Score(stu);
	setbkcolor(WHITE);
	settextcolor(BLACK);
	int t = 0;
	ShowTime(id);
	for (int i = 0; i <= 11; i++) {
		cout << "i: " << i << endl;
		TCHAR s[100],j1 = 0;
		string s1;
		char ss[100];
		if (stu[id].score[i] != "0"||i==9) {
			s1 = k[i];
			strcpy(ss, stu[id].score[i].c_str());
			for (int j = 0; j <= 20; j++) s[j] = (TCHAR)ss[j];
			EndBatchDraw();
			//settextcolor(BLACK);
			outtextxy(85+t*62, 250, s1.c_str());
			outtextxy(88+t*62, 290, s);
			t++;
		}
	}
	putimage(0, 444, &img[31]);
	EndBatchDraw();
	bool act = true;// 窗口是否激活
	//bool viss = false;  //密码是否可见
	ExMessage msg;
	int op = 0, num = 0;
	//getmessage(EM_KEY);
	setbkcolor(RGB(82, 85, 100));
	settextcolor(WHITE);
	while (act) {
		while (peekmessage(&msg)) {
			BeginBatchDraw();
			switch (msg.message) {
			case WM_MOUSEMOVE:    //鼠标移动
				if (msg.x >= 0 && msg.x <= 67 && msg.y >= 444 && msg.y <= 480) {
					putimage(0, 444, &img[32]);
				}
				else putimage(0, 444, &img[31]);
				break;
			case  WM_LBUTTONDOWN:
				if (msg.x >= 0 && msg.x <= 67 && msg.y >= 444 && msg.y <= 480) {
					
					return 2;
				}
			}
		}
		ShowTime(id);
		EndBatchDraw();
		Sleep(20);
	}
	return 1;
}