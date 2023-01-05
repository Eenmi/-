#include <iostream>
#include < conio.h >
#include <graphics.h>
#include "UI.h"
int scores_this_year[120];
bool is_chosen[120];
int choose_list[5] = { -1,-1,-1,-1,-1 };
int choosemajor(int x) {//输入x,加入志愿
    
    bool flag = false;
    for (int i = 0; i < 5; ++i) {
        if (choose_list[i] == -1)flag = true;
    }

    bool flag2 = false;
    for (int i = 0; i < 5; i++) {
        if (choose_list[i] == x) {
            flag2 = true;
        }
    }

    if (!flag && !flag2)return 0;
    is_chosen[x] = 1 - is_chosen[x];
    if (!flag2) {
        for (int i = 0; i < 5; ++i) {
            if (choose_list[i] == -1) {
                choose_list[i] = x;
                break;
            }
        }
    }
    else {
        int t = x;
        for (int i = 0; i < 4; ++i) {
            if (choose_list[i] == t) {
                t = choose_list[i + 1];
                choose_list[i] = t;
            }
        }
        choose_list[4] = -1;
    }
    return 1;
}

void readinthisscores(int scores_this_year[]) {//读入今年分数线
    ifstream in("今年分数线.txt");
    char school_name[1024] = { 0 };
    for (int i = 0; i < 34; i++) {
        in >> school_name >> scores_this_year[i * 3] >> scores_this_year[i * 3 + 1] >> scores_this_year[i * 3 + 2];
        cout << school_name << endl;
    }
    in.close();
}





int finall_sure(int scores_this_year[], string scores_now) {//输出被录取的学校
    int scores_now_int = atoi(scores_now.c_str());
    for (int i = 0; i < 5; i++) {
        if (scores_this_year[choose_list[i]] <= scores_now_int) {
            return choose_list[i];
        }
    }
    return -1;
}
int initShowCho(IMAGE* img,IMAGE*imgschool2, int& id, HWND& hwnd,bool &choose) {
    
    Score_Line pp;
    pp.Write_Line(Line);
    //memset(is_chosen, 0, sizeof(is_chosen));
    readinthisscores(scores_this_year);
    //for (int i = 0; i < 102; i++) {
    //    cout << scores_this_year[i] << ' ';
    //}
    cout << endl;
	BeginBatchDraw();
	putimage(0, 0, &img[35]);
	putimage(540, 400, &img[36]);
	EndBatchDraw();
	bool act = true;// 窗口是否激活
	//bool viss = false;  //密码是否可见
	ExMessage msg;
	int op = 0, i = 0;
	//getmessage(EM_KEY);
	while (act) {
		while (peekmessage(&msg)) {
			BeginBatchDraw();
			switch (msg.message) {
			case WM_MOUSEMOVE:    //鼠标移动
				if (msg.x >= 0 && msg.x <= 67 && msg.y >= 444 && msg.y <= 480) {
					putimage(0, 444, &img[32]);
				}
                else if (msg.x >= 540 && msg.x <= 638 && msg.y >= 400 && msg.y <= 432) {
                    putimage(540, 400, &img[39]);
                }
                else {
                    putimage(0, 444, &img[31]);
                    putimage(540, 400, &img[36]);
                }
				break;
			case  WM_LBUTTONDOWN:
				if (msg.x >= 0 && msg.x <= 67 && msg.y >= 444 && msg.y <= 480) {

					return 2;
				}
                else if (msg.x >= 225 && msg.x <= 244 && msg.y >= 150 && msg.y <= 169) {
                    int o=choosemajor(i*3);
                    if (o==0) MessageBox(hwnd, "超出填报名额!", "", MB_OK);
                }
                else if (msg.x >= 331 && msg.x <= 350 && msg.y >= 150 && msg.y <= 169) {
                    int o=choosemajor(i * 3+1);
                    if (o == 0) MessageBox(hwnd, "超出填报名额!", "", MB_OK);
                }
                else if (msg.x >= 437 && msg.x <= 456 && msg.y >= 150 && msg.y <= 169) {
                    int o=choosemajor(i * 3+2);
                    if (o == 0) MessageBox(hwnd, "超出填报名额!", "", MB_OK);
                }
                else if (msg.x >= 225 && msg.x <= 244 && msg.y >= 270 && msg.y <= 289) {
                    int o=choosemajor((i+1) * 3);
                    if (o == 0) MessageBox(hwnd, "超出填报名额!", "", MB_OK);
                }
                else if (msg.x >= 331 && msg.x <= 350 && msg.y >= 270 && msg.y <= 289) {
                    int o=choosemajor((i+1) * 3 + 1);
                    if (o == 0) MessageBox(hwnd, "超出填报名额!", "", MB_OK);
                }
                else if (msg.x >= 437 && msg.x <= 456 && msg.y >= 270 && msg.y <= 289) {
                    int o=choosemajor((i+1) * 3 + 2);
                    if (o == 0) MessageBox(hwnd, "超出填报名额!", "", MB_OK);
                }
                else if (msg.x >= 225 && msg.x <= 244 && msg.y >= 390 && msg.y <= 409) {
                    int o=choosemajor((i+2) * 3);
                    if (o == 0) MessageBox(hwnd, "超出填报名额!", "", MB_OK);
                }
                else if (msg.x >= 331 && msg.x <= 350 && msg.y >= 390 && msg.y <= 409) {
                    int o=choosemajor((i+2) * 3 + 1);
                    if (o == 0) MessageBox(hwnd, "超出填报名额!", "", MB_OK);
                }
                else if (msg.x >= 437 && msg.x <= 456 && msg.y >= 390 && msg.y <= 409) {
                    int o=choosemajor((i+2) * 3 + 2);
                    if (o == 0) MessageBox(hwnd, "超出填报名额!", "", MB_OK);
                }
                else if (msg.x >= 540 && msg.x <= 638 && msg.y >= 400 && msg.y <= 432) {
                    cout << stu[id].score[10] << endl;
                    int goal = finall_sure(scores_this_year, stu[id].score[10]);
                    cout << "goal: " << goal << endl;
                    if (goal==-1) MessageBox(hwnd, "未被任何学校录取!", "", MB_OK);
                    else {
                        string s;
                        s = "恭喜您!您被";
                        s += Line[goal / 3].school;
                        cout << Line[goal / 3].school << endl;
                        s += "的";
                        if (goal % 3 == 0) s += "A";
                        else if (goal % 3 == 1) s += "B";
                        else if (goal % 3 == 2) s += "C";
                        s += "类专业录取了";
                        MessageBox(hwnd,s.c_str(), "", MB_OK);
                        choose = 0;
                        return 2;
                    }
                }
				break;
			case WM_MOUSEWHEEL:
				if (msg.wheel > 0) {
					if (i != 0) i--;
				}
				else {
					if (i != 31) i++;
				}
			}
            cout << endl;
			for (int j = 0; j <= 2; j++) {
				putimage(10, 70 + 120 * j, &imgschool2[i + j]);
                for (int t = 0; t <= 2; t++) {
                    if (is_chosen[(i + j) * 3 + t]) putimage(225 + t * 106, 150 + 120 * j, &img[37]);
                    else putimage(225 + t * 106, 150 + 120 * j, &img[38]);
                }
			}
		}
		ShowTime(id);
		EndBatchDraw();
		Sleep(20);
	}
	return 1;
}