#include<iostream>
#include<fstream>
#define max 100
using namespace std;

struct Student {
	//int No;
	char ID[max]; //mssv
	char name[max]; //Ten
	char ho[max]; //Ho va ten dem
	char sex[max]; //Gioi tinh
	char birth[max]; //Ngay sinh
	char cccd[max]; //So cccd hoac cmnd
};

void readfile(Student*& x) {
	char tmp[max];
//	cin.ignore();
	cout << "Link file: ";
	cin.getline(tmp, max);
	ifstream read(tmp, ios::in);
	if (read.is_open()) {
		cout << "File dc mo thanh cong\n";
		int dem = 0;
		while (!read.eof()) {
			read.getline(x[dem].ID, max, ',');
			read.getline(x[dem].name, max, ',');
			read.getline(x[dem].ho, max, ',');
			read.getline(x[dem].sex, max, ',');
			read.getline(x[dem].birth, max, ',');
			read.getline(x[dem].cccd, max, ',');
			cout << x[dem].ID << " ";
			cout<< x[dem].name << " ";
			cout << x[dem].ho << " ";
			cout << x[dem].sex << " ";
			cout << x[dem].birth << " ";
			cout << x[dem].cccd << " ";
			dem++;
		}
	}
	else
		cout << "File mo khong thanh cong\n";
}

int main() {
	Student* x = new Student[10];
	readfile(x);
	system("pause");
	return 0;
}