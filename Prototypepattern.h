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
contain: 原型模式
Description:
用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象。
**************************************************/

//设计模式之原型模式

/*
解析：
Prototype模式其实就是常说的"虚拟构造函数"一个实现,C++的实现机制中并没有支持这个特性,
但是通过不同派生类实现的Clone接口函数可以完成与"虚拟构造函数"同样的效果.举一个例子来
解释这个模式的作用,假设有一家店铺是配钥匙的,他对外提供配制钥匙的服务(提供Clone接口函
数),你需要配什么钥匙它不知道只是提供这种服务,具体需要配什么钥匙只有到了真正看到钥匙
的原型才能配好.也就是说,需要一个提供这个服务的对象,同时还需要一个原型(Prototype),不
然不知道该配什么样的钥匙.

*/
//声明一个虚拟基类，所有的原型都从这个基类继承，
//父类    
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
	ResumeA(const char *str)  //构造函数    
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
	ResumeA(const ResumeA &r) //拷贝构造函数    
	{
		name = new char[strlen(r.name) + 1];
		strcpy_s(name, strlen(r.name)+1, r.name);
	}
	~ResumeA()                //析构函数    
	{
		delete [] name;
	}
	ResumeA* Clone()          //克隆，关键所在 
	{
		return new ResumeA(*this);
	}
	void Show()               //显示内容    
	{
		cout << "ResumeA name : " << name << endl;
	}
};


class ResumeB : public Resume
{
public:
	ResumeB(const char *str);  //构造函数    
	ResumeB(const ResumeB &r); //拷贝构造函数    
	~ResumeB();                //析构函数    
	ResumeB* Clone();          //克隆，关键所在    
	void Show();               //显示内容    
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
	//删除r1,r2    
	delete r1; delete r2;
	r1 = r2 = NULL;
	//深拷贝所以对r3,r4无影响    
	r3->Show(); r4->Show();
	delete r3; delete r4;
	r3 = r4 = NULL;

}

#endif // !_PROTOTYPEPATTERN_H_
