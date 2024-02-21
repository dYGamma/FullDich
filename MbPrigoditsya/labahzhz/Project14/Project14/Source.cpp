#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale>
#include <math.h>
#include <vector>
#include <fstream>

using namespace std;

//���-�������
int hashFunction(string key, int mod) {
	int hash = 0;	//��� ��� �� ����� key �� ������ mod
	int k = 1;		//������� ���������
	//���������� ��� ������� �����
	for (size_t i = 0; i < key.size(); ++i) {

		if (key[i] >= '0' && key[i] <= '9') {		//���� ������ ��� �����
			hash += (key[i] - '0') * k;
		}
		else if (key[i] >= 'A' && key[i] <= 'Z') {	//���� ������ ��� �����
			hash += (key[i] - 'A' + 10) * k;
		}
		k *= 11;
		hash %= mod; //����� �� ������
	}

	return hash;
}

//��������� ���-�������
struct hashTable {
	vector<string>* table;	//������� ������������ ����� ������[N] �������(��������)
	int size;				//������ ������� (���-�� ���������)

	hashTable(int _size) {
		cout << "�������� �������...\n";
		size = _size;
		table = new vector<string>[size];
	}

	//������� �������� �������� ���� key � �������
	int add(string key) {
		int hash = hashFunction(key, size); //�������� ��� �� ������ (�� �� ������ ������ � ������� table)
		bool has = false;
		for (size_t i = 0; i < table[hash].size(); ++i) { //���� �� ������ ����� ����
			if (table[hash][i] == key) { //���� ����� ����������
				has = true;
				break;
			}
		}

		if (has) { //���� ������� ��� ���� � �������
			cout << "������� ��� �������� � �������.\n";
			return -1;
		}
		else {
			table[hash].push_back(key); //���� ���������� �� �����, ��������� ������� � ������
			return hash;
		}
	}

	//������� �������� �����
	bool erase(string key) {
		cout << "�������� �����...\n";
		int i = find(key);
		if (i < 0) {
			return false;
		}
		for (size_t j = 0; j < table[i].size(); ++j) {
			if (table[i][j] == key) {
				table[i].erase(table[i].begin() + j);
				cout << "���� ������� ������.\n";
				return true;
			}
		}
	}


	//������� ���� ������� � ���-�������, ���������� ��� ���� ������� ������ � -1 � ��������� ������
	int find(string key) {
		int hash = hashFunction(key, size); //�������� ��� �� ������ (�� �� ������ ������ � ������� table)
		for (size_t i = 0; i < table[hash].size(); ++i) { //���� �� ������ ����� ����
			if (table[hash][i] == key) { //���� ����� ����������
				return hash;
				break;
			}
		}
		return -1; //���� ������� �� ������ ���������� -1
	}

	//������� ���� ��������, �������� � �������	 num, ���������� ������ ��������� ���������
	vector<string>& find(int num) {
		return table[(num - 1) % size];
	}

	void save_to_file(string fname) {
		printf("���������� � ���� \"%s\"...\n", fname.c_str());
		FILE* fout = fopen(fname.c_str(), "w");
		if (!fout) {
			cout << "�� ������� ������� ���� ��� ������.\n";
			return;
		}
		fprintf(fout, "%s; %s\n", "segment", "count");
		for (int i = 0; i < size; ++i) {
			fprintf(fout, "%d; %d\n", i, table[i].size());
		}
		fclose(fout);
		printf("������� ������� ��������� � ���� \"%s\".\n", fname.c_str());
	}

	void print() {
		cout << "����� �������:\n";
		for (int i = 0; i < size; ++i) {
			if (table[i].size() > 0) {
				cout << i + 1 << "'� �������: ";
				for (size_t j = 0; j < table[i].size(); ++j) {
					cout << table[i][j] << ' ';
				}cout << '\n';
			}
		}
	}

};

//������� �������� ���� �� ��������� � ������������������ �������
void next_key(string& key) {
	int i = key.size() - 1;
	while (i > 0 && key[i] == '9' || key[i] == 'Z') {
		--i;
	}
	if (i >= 0) {
		++key[i];
	}

	for (i = i + 1; i < key.size(); ++i) {
		if (key[i] >= '0' && key[i] <= '9') {
			key[i] = '0';
		}
		else {
			key[i] = 'A';
		}
	}
}


//��������� ���-������ ���������� ����������
void hashTable_fill(hashTable& ht, string key_format) {
	cout << "���������� ���-�������...\n";
	int n = 1; //���������� ���� ��������� ������
	string start_key = "";
	for (size_t i = 0; i < key_format.size(); ++i) {
		if (key_format[i] == '�') {
			n *= 10;			//���-�� ��������� ������������� � 10 ���
			start_key += '0';	//��������� ��������� �����
		}
		else if (key_format[i] == '�') {
			n *= 26;			//���-�� ��������� ����- 26
			start_key += 'A';	//��������� ��������� �����
		}
	}

	cout << "���������� ������...\n";

	//��������� ��� ��������� ����� � �������
	for (int i = 0; i < 8000; ++i) {
		ht.add(start_key);
		next_key(start_key);
	}
	cout << "������� ������� ���������.\n";
}

//������� ��������� ���� �� ������������ �������
bool check_format(string str, string format) {
	for (size_t i = 0; i < str.size(); ++i) {
		if (format[i] == '�') {
			if (str[i] < '0' || str[i] > '9') {
				return false;
			}
		}
		else if (format[i] == '�') {
			if (str[i] < 'A' || str[i] > 'Z') {
				return false;
			}
		}
	}
	return true;
}

//������� �������� ��������� ���� � ������� format 
bool scan_key(string& key, string& format) {
	cout << "������� ����: "; cin >> key;
	if (!check_format(key, format)) {
		printf("���� �� ������������� ������� \"%s\"\n", format.c_str());
		return false;
	}
	return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	//��������� ������ ��������
	hashTable ht(1500);
	string format = "������", key;
	hashTable_fill(ht, format);

	int cmd;

	while (true) {
		cout << "\n\t0- ���������� ���������\n";
		cout << "\t1- ����� ����\n";
		cout << "\t2- �������� ����\n";
		cout << "\t3- ������� ����\n";
		cout << "\t4- ����������� �������\n";
		cout << "\t5- ��������� � ����\n";
		cout << "������� �������: "; cin >> cmd;
		if (cmd == 0) {
			break;
		}
		else if (cmd == 1) {
			cout << "\n\t0- �� �����\n";
			cout << "\t1- �� ������ ��������\n";
			cout << "������� �������: "; cin >> cmd;
			if (cmd == 0) {
				if (!scan_key(key, format)) { continue; } //���� �� ���������� ������� ����, ���������� ��������

				int i = ht.find(key);
				if (i >= 0) {
					cout << "������� ��������� � �������. ����� ��������: " << i + 1 << '\n';
				}
				else {
					cout << "������� �� ������.\n";
				}
			}
			else {
				cout << "������� ����� ��������: "; cin >> cmd;
				vector<string>& v = ht.find(cmd);
				if (v.size() == 0) {
					cout << "������������ �� �������.\n";
				}
				else {
					cout << "��������� ��������: ";
					for (size_t i = 0; i < v.size(); ++i) {
						cout << v[i] << (i < v.size() - 1 ? ", " : "\n");
					}
				}
			}
		}
		else if (cmd == 2) {
			if (!scan_key(key, format)) { continue; } //���� �� ���������� ������� ����, ���������� ��������
			int ind = ht.add(key); //��������� ����
			if (ind >= 0) {
				if (ht.table[ind].size() > 1) {
					printf("��� ���������� ����� %s �������� �������� � ����������: ", key.c_str());
					for (size_t i = 0; i < ht.table[ind].size(); ++i) {
						if (key != ht.table[ind][i]) {
							cout << ht.table[ind][i] << ' ';
						}
					}cout << '\n';
				}
				cout << "���� ������� ��������.\n";
			}
		}
		else if (cmd == 3) {
			if (!scan_key(key, format)) { continue; } //���� �� ���������� ������� ����, ���������� ��������
			ht.erase(key);
		}
		else if (cmd == 4) {
			ht.print();
		}
		else if (cmd == 5) {
			ht.save_to_file("hashTable.csv");
		}
	}

}