#include <iostream>
#include < conio.h >
#include <graphics.h>
#include "UI.h"
int initShowPre(IMAGE* img,IMAGE*imgschool1, int& id) {
	BeginBatchDraw();
	putimage(0, 0, &img[34]);
	//putimage(0, 0, &imgschool1[20]);
	//for (int i = 0; i <= 2; i++) {
	//	putimage(60, 70+120*i, &imgschool1[i]);
	//}
	putimage(0, 444, &img[31]);
	EndBatchDraw();
	bool act = true;// 窗口是否激活
	//bool viss = false;  //密码是否可见
	ExMessage msg;
	int op = 0,i=0;
	//getmessage(EM_KEY);
	Score_Line t;
	t.Write_Line(Line);
	cout << "sedrftgyhuj"<<Line[0].A << endl;
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
				break;
			case WM_MOUSEWHEEL:
				if (msg.wheel > 0) {
					if (i!=0) i--;
				}
				else {
					if (i != 31) i++;
				}
			}

			for (int j = 0; j <= 2; j++) {
				putimage(60, 70 + 120 * j, &imgschool1[i+j]);
				for (int t = 0; t <= 2; t++) {
					setbkcolor(WHITE);
					settextcolor(BLACK);
					if (t == 0) outtextxy(260, 150 + 120 * j, Line[i + j].A.c_str());
					else if (t==1) outtextxy(360, 150 + 120 * j, Line[i + j].B.c_str());
					else if (t==2) outtextxy(460, 150 + 120 * j, Line[i + j].B.c_str());
					setbkcolor(RGB(82, 85, 100));
					settextcolor(WHITE);
				}
			}
		}
		ShowTime(id);
		EndBatchDraw();
		Sleep(20);
	}
	return 1;
}