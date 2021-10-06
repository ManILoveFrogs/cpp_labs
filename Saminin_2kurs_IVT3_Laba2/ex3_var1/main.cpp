/*�������� ����������� �����, � ������������ � ���������. 
������������������ � ���� ������������ ������, 
���������� ������������� ��� ���������� � � ����������� ��� ������������� ������. 
����� ������ ��������� ����� serialize() ��� ���������� ������ ������ � ���� 
� ����� deserialize() ��� ������ ������ ������ �� ����� �� ��������� � ������� ����������, 
� ����� ������������� ������ serialize(const std::string& filename) 
� deserialize(const std::string& filename) ��� ������ � ������ � ��������� � ��������� ������.*/


/*����� �������.
������: ���, ���, ��� ��������, ��� �����������, ����� �������, ������� ����.
������� ������ �� 3 ��������� � ���������� �� ������ ������ � ������� ��������. 
��� ������ �������� ������� �������� � ���� � ���������� ��� ������ � ������������ � �����������. 
� ������� ������� �������������� ��� ������ � 
��������� ������� ������������ �� 4 ����� ������ � ����������� � ��������� ������ ������� ����. 
������� ���������� ���������, ������������ �� � ������� �������� �������� �����.
*/

#include <iostream>
#include "Student.h"
using namespace std;
#include <fstream> // for using file input/output
#include <algorithm> // for using sort()

int main() {
	setlocale(LC_ALL, "rus");

	Student student1, student2, student3; //stack
	Student* student4 = new Student("����� ����� �����������", "���", 0, 2000, 151424234334, 0); //heap

	
	student1.setFio("������� ������� �������������");
	student1.setGender("���");
	student1.setYearOfBirth(2002);
	student1.setYearOfEntrance(2020);
	student1.setNumOfCreditBook(88005553535);
	student1.setAvarageMark(0);

	student2.setFio("������� ���� ����");
	student2.setGender("����");
	student2.setYearOfBirth(1990);
	student2.setYearOfEntrance(2010);
	student2.setNumOfCreditBook(666666666);
	student2.setAvarageMark(0);

	student3.setFio("�������� ����� ��������");
	student3.setGender("���� �����");
	student3.setYearOfBirth(666);
	student3.setYearOfEntrance(1941);
	student3.setNumOfCreditBook(777000777);
	student3.setAvarageMark(0);
	

	//�������� 3 ������(�� ��� ���)
	student1.sessionSimulation();
	student2.sessionSimulation(); 
	student3.sessionSimulation(); 
	student4->sessionSimulation(); 
	
	//������������ �������� �����
	student1.calculAvarageMark();
	student2.calculAvarageMark();
	student3.calculAvarageMark();
	student4->calculAvarageMark();

	
	//����� �� �������
	//student1.printInfo(student1);
	//student1.printInfo(student2);
	//student1.printInfo(student3);

	//��������� � ������ ���������
	cout << "  ������ ��������� � ����� � ��������\n  ��� �� ������� ��������� ����� �� ������ ������\n" << endl;
	cout << "  �����, ��������� � ����: " << endl;
	cout << "  - ����� .txt, ��������� � ������� ������ serialize()" << endl;
	cout << "  - Student + ����� .txt, ��������� � ������� �������������� ������ serialize(const string& filename)\n" << endl;
	cout << "  ������������ ������ ������ �� �����, �����, ������� ������� � ����:" << endl;
	cout << "  - ����� .txt, �������� � ������� ������ deserialize()" << endl;
	cout << "  - Student + ����� .txt, �������� � ������� �������������� ������ deserialize(const string& filename)\n" << endl;
	cout << "  ���� �� ������ �� ������� �� �������, ������������� ��������� � ��� ����������� �������� ;) \n" << endl;
	
	// ������ �� ����� � ������� �� �������
	student1.deserialize();
	student2.deserialize();
	student3.deserialize();
	student4->deserialize();

	student1.deserialize("Student1.txt");
	student2.deserialize("Student2.txt");
	student3.deserialize("Student3.txt");
	student4->deserialize("Student4.txt");


	// ���������� � ����
	student1.serialize();
	student2.serialize();
	student3.serialize();
	student4->serialize();

	student1.serialize("Student1.txt");
	student2.serialize("Student2.txt");
	student3.serialize("Student3.txt");
	student4->serialize("Student4.txt");
	
	//����������
	cout << "\n  �������� �� ����������: " << endl;
	student1.printInfo();
	student2.printInfo();
	student3.printInfo();
	student4->printInfo();

	//����������
	cout << "\n\n  ���������� �� �������� ����� �� ��������: " << endl;
	const size_t numOfStud = 4;
	string pitaStr[numOfStud];
	pitaStr[0] = student1.getFio();
	pitaStr[1] = student2.getFio();
	pitaStr[2] = student3.getFio();
	pitaStr[3] = student4->getFio();

	double pitaDoub[numOfStud];
	pitaDoub[0] = student1.getAvarageMark();
	pitaDoub[1] = student2.getAvarageMark();
	pitaDoub[2] = student3.getAvarageMark();
	pitaDoub[3] = student4->getAvarageMark();

	
	for (int i = 0; i < numOfStud; i++) {
		double zamenaDoub;
		string zamenaStr;
		for (int j = i + 1; j < numOfStud; j++) {
			if (pitaDoub[i] < pitaDoub[j]) {
				zamenaDoub = pitaDoub[i];
				pitaDoub[i] = pitaDoub[j];
				pitaDoub[j] = zamenaDoub;

				zamenaStr = pitaStr[i];
				pitaStr[i] = pitaStr[j];
				pitaStr[j] = zamenaStr;
			}
		}
	}

	for (size_t i = 0; i < numOfStud; i++) {
		cout << "  "<< i+1 <<" - " << pitaStr[i] << " - " << pitaDoub[i] << endl;
	}

	cout << "\n\n";

	system("pause");
	return 0;
}