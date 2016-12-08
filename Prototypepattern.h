#ifndef _PROTOTYPEPATTERN_H_
#define _PROTOTYPEPATTERN_H_
#pragma once
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

/*************************************************
Author:toni
Date:2016-12-06
contain: ԭ��ģʽ
Description:
��ԭ��ʵ��ָ��������������࣬����ͨ��������Щԭ�ʹ����µĶ���
**************************************************/

//���ģʽ֮ԭ��ģʽ

/*
������
Prototypeģʽ��ʵ���ǳ�˵��"���⹹�캯��"һ��ʵ��,C++��ʵ�ֻ����в�û��֧���������,
����ͨ����ͬ������ʵ�ֵ�Clone�ӿں������������"���⹹�캯��"ͬ����Ч��.��һ��������
�������ģʽ������,������һ�ҵ�������Կ�׵�,�������ṩ����Կ�׵ķ���(�ṩClone�ӿں�
��),����Ҫ��ʲôԿ������֪��ֻ���ṩ���ַ���,������Ҫ��ʲôԿ��ֻ�е�����������Կ��
��ԭ�Ͳ������.Ҳ����˵,��Ҫһ���ṩ�������Ķ���,ͬʱ����Ҫһ��ԭ��(Prototype),��
Ȼ��֪������ʲô����Կ��.

*/
//����һ��������࣬���е�ԭ�Ͷ����������̳У�
//����    
class Resume
{
protected:
	char *name;
public:
	Resume() {}
	virtual ~Resume() {}
	virtual Resume* Clone() { return NULL; }
	virtual void Set(char *n) {}
	virtual void Show() {}
};
class ResumeA : public Resume
{
public:
	ResumeA(const char *str)  //���캯��    
	{
		if (str == NULL) {
			name = new char[1];
			name[0] = '\0';
		}
		else {
			name = new char[strlen(str) + 1];
			strcpy_s(name, strlen(str)+1, str);
		}
	}
	ResumeA(const ResumeA &r) //�������캯��    
	{
		name = new char[strlen(r.name) + 1];
		strcpy_s(name, strlen(r.name)+1, r.name);
	}
	~ResumeA()                //��������    
	{
		delete [] name;
	}
	ResumeA* Clone()          //��¡���ؼ����� 
	{
		return new ResumeA(*this);
	}
	void Show()               //��ʾ����    
	{
		cout << "ResumeA name : " << name << endl;
	}
};


class ResumeB : public Resume
{
public:
	ResumeB(const char *str);  //���캯��    
	ResumeB(const ResumeB &r); //�������캯��    
	~ResumeB();                //��������    
	ResumeB* Clone();          //��¡���ؼ�����    
	void Show();               //��ʾ����    
};

ResumeB::ResumeB(const char *str)
{
	if (str == NULL) {
		name = new char[1];
		name[0] = '\0';
	}
	else {
		name = new char[strlen(str) + 1];
		strcpy_s(name, strlen(str)+1, str);
	}
}
ResumeB::~ResumeB() { delete[] name; }

ResumeB::ResumeB(const ResumeB &r) {
	name = new char[strlen(r.name) + 1];
	strcpy_s(name, strlen(r.name)+1 , r.name);
}
ResumeB* ResumeB::Clone() {
	return new ResumeB(*this);
}
void ResumeB::Show() {
	cout << "ResumeB name : " << name << endl;
}



void TestProtoPatternPattern()
{
	cout << endl << "________________ProtoPattern___________________" << endl;

	Resume *r1 = new ResumeA("A");
	Resume *r2 = new ResumeB("B");
	Resume *r3 = r1->Clone();
	Resume *r4 = r2->Clone();
	r1->Show(); r2->Show();
	//ɾ��r1,r2    
	delete r1; delete r2;
	r1 = r2 = NULL;
	//������Զ�r3,r4��Ӱ��    
	r3->Show(); r4->Show();
	delete r3; delete r4;
	r3 = r4 = NULL;

}

#endif // !_PROTOTYPEPATTERN_H_
