#include <iostream>
#include < conio.h >
#include <graphics.h>
#include "UI.h"
Student_Score stu[100];
Number Num[100];
Score_Line Line[100];
#define n 6
#define m 34
void Student_Score::Write_Score(Student_Score stu[]) {//���뿼���ɼ��ļ�
	ifstream in("�����ɼ�.txt");
	for (int i = 0; i < n; i++) {
		in >> stu[i].num >> stu[i].name;
		for (int j = 0; j <= 10; j++)
			in >> stu[i].score[j];
	}
	in.close();
	//cin.get();
}
void Student_Score::Lookup_Score(Student_Score stu[], int& id) {//��ѯ�����ɼ�����
	if (id != -1) {
		//�����Ӧѧ���ɼ�
		//���� ���� ���� ��ѧ Ӣ�� ���� ��ѧ ���� ���� ��ʷ ����
		cout << stu[id].num << "\t" << stu[id].name << "\t" << stu[id].Chinese << "\t" << stu[id].Math << "\t" << stu[id].English << "\t" << stu[id].Physical << "\t" << stu[id].Chemical << "\t" << stu[id].Biological << "\t" << stu[id].Political << "\t" << stu[id].History << "\t" << stu[id].Geographic << endl;
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------��¼,�޸�������ĳ�Ա����-----------------------------------------------------------------------------------
void Number::Write_Number(Number num[]) {//���뿼���˺������ļ�
	ifstream in("�����˺�����.txt");
	for (int i = 0; i < n; i++)
		in >> num[i].number >> num[i].password;
	cout << num[0].number << num[0].password << endl;
	in.close();
	cout << 2 << endl;
	//cin.get();
	cout << 1 << endl;
}
bool Number::Match(string pw, string nu, int& id) {//ƥ�亯��
	int i;
	for (i = 0; i < n; i++) {
		cout << Num[i].number << " " << Num[i].password << endl;
		if (nu == Num[i].number && pw == Num[i].password) {//��¼�ɹ�
			id = i;
			return TRUE;
			break;
		}
	}
	return FALSE;
}
//void Login(Number num[]) {//��¼����
//	cin >> num->nu;//�����˺�
//	cin >> num->pw;//��������
//	Match(num->nu, num->pw, num->id);
//}
void Number::Change_password(Number num[], string npw2, int& id) {//�޸����뺯��
	cout << "id: " << id << endl;
	if (id != -1) {
		ofstream out("�����˺�����.txt");
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

//--------------------------------------------------------------------��ѯȥ���������ĳ�Ա����----------------------------------------------------------------------------------
void Score_Line::Write_Line(Score_Line Line[]) {//����ȥ��������ļ�
	ifstream in("ȥ�������.txt");
	for (int i = 0; i < m; i++)
		in >> Line[i].school >> Line[i].A >> Line[i].B >> Line[i].C;
	in.close();
	//cin.get();
}
//void Lookup_Line(Score_Line Line[], int& id) {//��ѯȥ������ߺ���
//	if (id != -1) {
//		int i = 0;
//		while (i < m) {
//			//ȥ��¼ȡ������Ϊ
//						//��ѧ���� A����ͷ� B����ͷ� C����ͷ�
//			cout << Line[i].school << "\t" << "\t" << Line[i].A << "\t" << "\t" << Line[i].B << "\t" << "\t" << Line[i].C << endl;
//			i++;
//		}
//	}
//}
