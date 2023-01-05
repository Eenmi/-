#include <iostream>
#include <algorithm>
#include < conio.h >
#include <graphics.h>
#include "UI.h"
void Exchange(string&k, int& length, int num,int wei) {
	string h;
	for (int i = 1,t=10; i <= wei; i++) {
		h+=num % t + '0';
		num /= 10;
		//cout << "num: " << num << endl;
	}
	//cout << "t: " << h << endl;
	reverse(h.begin(), h.end());
	k += h;
}
void ShowTime(int&id) {
	time_t timep;
	struct tm* p;
	time(&timep); //获取从1970至今过了多少秒，存入time_t类型的timep
	p = localtime(&timep);//用localtime将秒数转化为struct tm结构体
	string k;
	int a = 1900 + p->tm_year,start=0,b=1+p->tm_mon,c=p->tm_mday,d=p->tm_hour,e=p->tm_min;
	Exchange(k, start, a,4);
	k += "年";
	Exchange(k, start, b,2);
	k+= "月";
	Exchange(k, start, c,2);
	k+= "日";
	Exchange(k, start, d,2);
	k += ":";
	Exchange(k, start, e,2);
	k += " ";
	k += " ";
	k += " ";
	k += "考";
	k += "生";
	k += "(";
	Student_Score t;
	t.Write_Score(stu);
	k += stu[id].name;
	k += ")";
	//outtextxy(245, 30, k);
	//Student_Score t;
	//t.Write_Score(stu);
	//TCHAR na[20];
	//_stprintf(na, _T("%s"), stu[id].name.c_str());
	//cout << na[0] << " " << na[1] << " " << na[2] << " " << na[3] << endl;
	//na[4] = '\0';
	//outtextxy(265, 200,na);
	//cout << "id: " << id << endl;
	//cout << "name: " << stu[id].name << endl;
	//strcpy(na, stu[id].name.c_str());
	//string n1;
	//n1 = "啊啊啊";
	//cout << n1 << endl;
	//cout << "0000000: " << (char)na[0] << endl;
	//for (int i = 0; i <= 10; i++) {
	//	if (na[i] == '\0') break;
	//	cout <<"tyu: "<< na[i] << endl;
	//	k[start++] = (TCHAR)na[i];
	//}
	setlinecolor(WHITE);
	rectangle(0, 0, 640, 60);
	setlinecolor(RGB(82, 85, 100));
	setfillcolor(RGB(82, 85, 100));
	fillrectangle(245, 10, 500, 50);
	outtextxy(245, 30, k.c_str());
	//printf("%d/%d/%d %02d:%02d:%02d\n", 1900 + p->tm_year, 1 + p->tm_mon,p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);//2021/5/11 14:04:44

}
int initShowMain(IMAGE*img,int&id, HWND& hwnd,bool&choose) {
	BeginBatchDraw();
	putimage(0, 0, &img[24]);
	putimage(129, 167, &img[25]);
	putimage(301, 167, &img[27]);
	putimage(472, 167, &img[29]);
	EndBatchDraw();
	bool act = true;// 窗口是否激活
	ExMessage msg;
	int op = 0, num = 0;
	while (act) {
		while (peekmessage(&msg)) {
			BeginBatchDraw();
			switch (msg.message) {
			case WM_MOUSEMOVE:
				if (msg.x >= 129 && msg.x <= 238 && msg.y >= 167 && msg.y <= 363) {
					putimage(129, 167, &img[26]);
				}
				else if (msg.x >= 301 && msg.x <= 410 && msg.y >= 167 && msg.y <= 363) {
					putimage(301, 167, &img[28]);
				}
				else if (msg.x >= 472 && msg.x <= 581 && msg.y >= 167 && msg.y <= 363) {
					putimage(472, 167, &img[30]);
				}
				else {
					putimage(129, 167, &img[25]);
					putimage(301, 167, &img[27]);
					putimage(472, 167, &img[29]);
				}
				break;
			case WM_LBUTTONDOWN:
				if (msg.x >= 129 && msg.x <= 238 && msg.y >= 167 && msg.y <= 363) {
					EndBatchDraw();
					return 3;
				}
				else if (msg.x >= 301 && msg.x <= 410 && msg.y >= 167 && msg.y <= 363) {
					EndBatchDraw();
					return 4;
				}
				else if (msg.x >= 472 && msg.x <= 581 && msg.y >= 167 && msg.y <= 363) {
					if (choose == 0) {
						MessageBox(hwnd, "您已填报完志愿", "", MB_OK);
						return 2;
					}
					EndBatchDraw();
					return 5;
				}
			}
			

		}
		ShowTime(id);
		EndBatchDraw();
		Sleep(20);
	}
	return 2;
}