#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include <string>
class Person {
private:
	string name;
	string age;
	string ID;
	float basticSalary;
public:
	Person();
	Person(string, string, string, float);
	void input();
	void display();
	virtual float Sum_basticSalary();
	float getBasticStaly() {
		return basticSalary;
	}
};

Person::Person(string name, string age, string ID, float basticSalary)
{
	this->name = name;
	this->age = age;
	this->ID = ID;
	this->basticSalary = basticSalary;
}

void Person::input()
{
	cout << "name =: "; cin >> name;
	cout << endl << "age =:"; cin >> age;
	cout << endl << "ID =:"; cin >> ID;
}

void Person::display()
{
	cout << "////////////////////////////////////////////////////////////////";
	cout << endl << "name :" << name << "  age : " << age << " ID : " << ID;
}
float Person::Sum_basticSalary()
{
	return 0.0f;
}
class PM : public Person {
private:
	string position;
public:
	void input();
	void display();
	float Sum_basticSalary();
};

void PM::input()
{
	Person::input();
	cout << "position = ";
	cin >> position;
}

void PM::display()
{
	Person::display();
	cout << " position = " << position;
}

float PM::Sum_basticSalary()
{	
	float luong = getBasticStaly() + 1000;
	return luong;
}
class dev :public Person {
private:
	float bonus;
public:
	dev();
	void input();
	void display();
	float Sum_basticSalary();
};

void dev::input()
{
	Person::input();
	cout << "bonus : ";
	cin >> bonus;
}

void dev::display()
{
	Person::display();
	cout << "bonus : " << bonus;
}

float dev::Sum_basticSalary()
{
	float luong = getBasticStaly() + bonus;
	return luong;
}
class arrofperson {
private:
	vector<Person*> arr;
public:
	void nhapdanhsach();
	void xuatdanhsach();
};

void arrofperson::nhapdanhsach()
{
	Person* arry;
	int value;
	do {
		cout << "1 nhap PM " << endl;
		cout << "2 nhap DEV " << endl;
		cout << "moi chon" << endl;
		cin >> value;
		switch (value)
		{
		case 1: {
			arry = new PM();
			arry->input();
			arr.push_back(arry);
		}
		case 2: {
			arry = new dev();
			arry->input();
			arr.push_back(arry);
			break;
		}
		default:
			break;
		}
	} while (value == 0);
}
void arrofperson::xuatdanhsach() {
	for (int i = 0; i < arr.size(); i++) {
		 arr[i]->display();
	}
}
int main() {
	arrofperson m;
	int tam;
	do {
		cout << "1 nhap" << endl;
		cout << "2 xuat " << endl;
		cout << "moi chon" << endl;
		cin >> tam;
		switch (tam)
		{
		case 1: {
			m.nhapdanhsach();
			break;
		}
		case 2: {
			m.xuatdanhsach();
			break;
		}
		default:
			break;
		}
	} while (tam == 0);
	return 0;
}
