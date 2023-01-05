#include <iostream>
#include < conio.h >
#include <graphics.h>
#include "UI.h"
using namespace std;
bool JudgePassword(TCHAR* s2,int length2, TCHAR* s3,int length3) {
	if (length2 != length3) return false;
	else {
		for (int i = 0; i < length2; i++) {
			if (s2[i] != s3[i]) return false;
		}
	}
	return true;
}
int initchangeUI(IMAGE* img,HWND &hwnd,int&id) {
	PassWord wa1,wa2;
	int Click = 0;  //È·ÈÏµã»÷µÄÊÇ¿ò¿ò»¹ÊÇµÇÂ¼/ÐÞ¸ÄÃÜÂë
	BeginBatchDraw();
	setbkcolor(RGB(82, 85, 100));
	cleardevice();
	EndBatchDraw();
	LOGFONT title, word, acc;
	TextKind(title, word, acc);
	setbkmode(TRANSPARENT);
	settextstyle(&title);
	setlinecolor(RGB(82, 85, 100));
	setfillcolor(RGB(82, 85, 100));
	fillroundrect(200, 50, 500, 100, 10, 10);
	outtextxy(200, 70, "ÉÏº£½ÌÓý¿¼ÊÔÔº");
	settextstyle(&acc);
	fillroundrect(100, 140, 180, 240, 10, 10);
	fillroundrect(100, 240, 180, 340, 10, 10);
	outtextxy(70, 160, "ÐÞ¸ÄÃÜÂë");
	outtextxy(70, 240, "È·ÈÏÃÜÂë");
	putimage(200, 150, &img[12]);   //ÊäÈë¿òÒ»
	putimage(510, 155, &img[19]);   //µÇÂ¼ÃÜÂë(Òþ²Ø)
	putimage(200, 240, &img[12]);   //ÊäÈë¿ò¶þ
	putimage(510, 245, &img[19]);   //µÇÂ¼ÃÜÂë(Òþ²Ø)
	putimage(140, 330, &img[15]);   //µÇÈë
	putimage(340, 330, &img[20]);   //ÐÞ¸ÄÃÜÂë
	EndBatchDraw();
	bool act = true;// ´°¿ÚÊÇ·ñ¼¤»î
	ExMessage msg;
	int op = 1, num = 0;
	//getmessage(EM_KEY);
	while (act) {
		while (peekmessage(&msg)) {
			BeginBatchDraw();
			switch (msg.message) {
			case WM_MOUSEMOVE:    //Êó±êÒÆ¶¯
				if (msg.x >= 200 && msg.x <= 546 && msg.y >= 150 && msg.y <= 188) {
					if (Click != 1) putimage(200, 150, &img[4]);
				}
				else if (msg.x >= 200 && msg.x <= 546 && msg.y >= 240 && msg.y <= 278) {
					if (Click != 2) putimage(200, 240, &img[4]);
				}
				else if (msg.x >= 140 && msg.x <= 288 && msg.y >= 330 && msg.y <= 379) {
					putimage(140, 330, &img[16]);
				}
				else if (msg.x >= 340 && msg.x <= 488 && msg.y >= 330 && msg.y <= 379) {
					putimage(340, 330, &img[21]);
				}
				else {
					if (Click != 1) {
						if (wa1.length == 0) putimage(200, 150, &img[12]);
						else putimage(200, 150, &img[3]);
					}
					if (Click != 2) {
						if (wa2.length == 0) putimage(200, 240, &img[12]);
						else putimage(200, 240, &img[3]);
					}
					putimage(140, 330, &img[15]);
					putimage(340, 330, &img[20]);
				}
				break;
			case WM_CHAR:         //×Ö·û´®¶ÁÈë
				op = 1;
				if (msg.ch == 8) op = 0;
				if (Click == 1) {
					Display_Account(wa1, op, msg.ch);
					if (wa1.visableE == 0) Display_Password(wa1);
				}
				else if (Click == 2) {
					Display_Account(wa2, op, msg.ch);
					if (wa2.visableE == 0) Display_Password(wa2);
				}
				break;
			case  WM_LBUTTONDOWN:
				if (msg.x >= 200 && msg.x < 510 && msg.y >= 150 && msg.y <= 188) {
					putimage(200, 150, &img[5]);
					Click = 1;
					if (wa2.length)putimage(200, 240, &img[3]);
					else putimage(200, 240, &img[12]);
				}
				else if (msg.x >= 200 && msg.x < 510 && msg.y >= 240 && msg.y <= 278) {
					putimage(200, 240, &img[5]);
					Click = 2;
					if (wa1.length) putimage(200, 150, &img[3]);
					else putimage(200, 150, &img[12]);
				}
				else if (msg.x >= 510 && msg.x <= 546 && msg.y >= 150 && msg.y <= 188) {
					putimage(510, 155, &img[18]);
					wa1.visableE = !wa1.visableE;
					Display_Password(wa1);
				}
				else if (msg.x >= 510 && msg.x <= 546 && msg.y >= 240 && msg.y <= 278) {  //Òþ²ØÃÜÂë½çÃæ
					putimage(510, 245, &img[18]);
					wa2.visableE = !wa2.visableE;
					Display_Password(wa2);
					//cout << "wa.visableE: " << wa.visableE << endl;
					//cout << "wa.length" << wa.length << endl;
				}
				else if (msg.x >= 140 && msg.x <= 288 && msg.y >= 330 && msg.y <= 379) {
					putimage(140, 330, &img[2]);
					EndBatchDraw();
					Sleep(200);
					putimage(340, 330, &img[7]);
					string s1, s2;
					Trans(s1, wa1);
					Trans(s2, wa2);
					Number k;
					k.Write_Number(Num);
					if (s1 == s2) {
						k.Change_password(Num, s1, id);
						return 2;
					}
					else {
						MessageBox(hwnd, "Á½´ÎÃÜÂëÊäÈë²»Ò»ÖÂ", "", MB_OK);
						while (wa1.length) Display_Account(wa1);
						while (wa2.length) Display_Account(wa2);
						Display_Password(wa1);
						Display_Password(wa2);
						fillrectangle(210, 160, 536, 175);
						fillrectangle(210, 250, 536, 265);
						if (Click != 1) putimage(200, 150, &img[12]);
						else putimage(200, 150, &img[5]);
						if (Click != 2)putimage(200, 240, &img[12]);
						else putimage(200, 240, &img[5]);
					}
				}
				else if (msg.x >= 340 && msg.x <= 488 && msg.y >= 330 && msg.y <= 379) {  //ÖØÖÃÃÜÂë
					putimage(340, 330, &img[22]);
					while (wa1.length) Display_Account(wa1);
					while (wa2.length) Display_Account(wa2);
					Display_Password(wa1);
					Display_Password(wa2);
					//fillroundrect(210, 160, 536, 175, 10, 10);
					fillrectangle(210, 160, 536, 175);
					fillrectangle(210, 250, 536, 265);
					if (Click != 1) putimage(200, 150, &img[12]);
					else putimage(200, 150, &img[5]);
					if (Click != 2)putimage(200, 240, &img[12]);
					else putimage(200, 240, &img[5]);
					Sleep(200);
					//initchangeUI();
					putimage(340, 330, &img[21]);
				}
				break;
			}
		}
		//if (wa1.length) fillroundrect(210, 160, 536, 175, 10, 10);
		//if (wa2.length) fillroundrect(210, 250, 536, 265, 10, 10);
		if (Click == 1) {
			//fillroundrect(210, 160, 536, 175, 10, 10);
			fillrectangle(210, 160, 536, 175);
			int wid;
			if (wa1.visableE) wid = textwidth(wa1.s1);
			else wid = textwidth(wa1.s2);
			if (num < 10)putimage(210 + 2 + wid, 160, &img[9]);
			else putimage(210 + 2 + wid, 160, &img[10]);
			num++;
			num %= 20;
		}
		if (Click == 2) {
			//fillroundrect(210, 250, 536, 265, 10, 10);
			fillrectangle(210, 250, 536, 265);
			int wid;
			if (wa2.visableE) wid = textwidth(wa2.s1);
			else wid = textwidth(wa2.s2);
			if (num < 10)putimage(210 + 2 + wid, 250, &img[9]);
			else putimage(210 + 2 + wid, 250, &img[10]);
			num++;
			num %= 20;
		}
		settextstyle(&word);
		if (wa1.visableE) putimage(510, 155, &img[18]);
		else putimage(510, 155, &img[19]);
		if (wa2.visableE) putimage(510, 245, &img[18]);
		else putimage(510, 245, &img[19]);
		if (wa1.visableE)outtextxy(210, 160, wa1.s1);
		else outtextxy(210, 160, wa1.s2);
		if (wa2.visableE) outtextxy(210, 250, wa2.s1);
		else outtextxy(210, 250, wa2.s2);
		EndBatchDraw();
		Sleep(20);
	}
	Sleep(10000);
	return 0;
}