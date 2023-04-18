#include<iostream>
#include<fstream>
#define max 100
using namespace std;

struct Student {
	//int No;
	int ID;
//	char ID[max]; //mssv
	char name[max]; //Ten
	char ho[max]; //Ho va ten dem
	char sex[max]; //Gioi tinh
	char birth[max]; //Ngay sinh
	int cccd;
//	char cccd[max]; //So cccd hoac cmnd
};

void countFile(char x[], int& n) {
	ifstream read(x, ios::in);
	n = 0;
	while (!read.eof()) {
		char tmp[500];
		read.getline(tmp, 200);
		n++;
		if (strlen(tmp) == 0)
			n--;
	}
	read.close();
}

void readfile(Student*& x, int& n) {
	char tmp[max];
//	cin.ignore();
//	cout << "Link file: ";
	cin.getline(tmp, max);
	cout << tmp;
	int m;
	countFile(tmp, m);
	ifstream read(tmp, ios::in);
	if (read.is_open()) {
		cout << "File dc mo thanh cong\n";
		int dem = 0;
	//	while (!read.eof()) {
	////		read.getline(x[dem].ID, max, ',');
	//		read >> x[dem].ID;
	//		read.ignore();
	//		read.getline(x[dem].name, max, ',');
	//		read.getline(x[dem].ho, max, ',');
	//		read.getline(x[dem].sex, max, ',');
	//		read.getline(x[dem].birth, max, ',');
	//		read >> x[dem].cccd;
	//	//	read.getline(x[dem].cccd, max, ',');
	//		cout << x[dem].ID << " ";
	//		cout<< x[dem].name << " ";
	//		cout << x[dem].ho << " ";
	//		cout << x[dem].sex << " ";
	//		cout << x[dem].birth << " ";
	//		cout << x[dem].cccd << " ";
	//		cout << endl;
	//		dem++;
	//	}
		for (int i = 0; i < m; i++) {
	//		read.getline(x[dem].ID, max, ',');
			read >> x[dem].ID;
			read.ignore();
			read.getline(x[dem].name, max, ',');
			read.getline(x[dem].ho, max, ',');
			read.getline(x[dem].sex, max, ',');
			read.getline(x[dem].birth, max, ',');
			read >> x[dem].cccd;
		//	read.ignore();
		//	read.getline(x[dem].cccd, max, ',');
			cout << x[dem].ID << " ";
			cout<< x[dem].name << " ";
			cout << x[dem].ho << " ";
			cout << x[dem].sex << " ";
			cout << x[dem].birth << " ";
			cout << x[dem].cccd << " ";
			cout << endl;
			dem++;
		}
		n = dem;
	}
	else
		cout << "File mo khong thanh cong\n";
}

void writefile(Student* x, int n) {
	ofstream write("Bangdiem.CSV", ios::out);
	if (write.is_open()) {
		cout << "Mo file thanh cong\n";
		for (int i = 0; i < n; i++) {
			write << x[i].ID << ",";
			write << x[i].name << ",";
			write << x[i].ho << ",";
			write << x[i].sex << ",";
			write << x[i].birth << ",";
			write << x[i].cccd;
			write << endl;
		}
	}
	else
		cout << "Mo file khong thanh cong\n";


}

int main() {
	int n;
	Student* x = new Student[10];
	readfile(x, n);
	writefile(x, n);
	system("pause");
	return 0;
}