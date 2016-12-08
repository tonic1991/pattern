#ifndef _ADAPTERPATTERN_H_
#define _ADAPTERPATTERN_H_
#pragma once
#include <iostream>
using namespace std;

/*************************************************
Author:toni
Date:2016-11-21
contain: Duck ,Turkey , TurkeyAdapter.
Description: 将一个类的接口转换成客户期望的另一个接口，适配器让原本不兼容的类可以合作无间。
**************************************************/

//target -requst
class Duck
{
public:
	void request()
	{
		cout << "request a duck~!" << endl;
	}
	virtual ~Duck() {};
};

//adaptee
class Turkey
{
public:
	void specialRequest()
	{
		cout << "request a turkey~!" << endl;
	}
	virtual ~Turkey() {};
};

//adapter
class TurkeyAdapter:public Duck
{
public:
	TurkeyAdapter(Turkey *turkey) :m_turkey(turkey) {};

	void request()
	{
		cout << "adapter transfer" << endl;
		m_turkey->specialRequest();
	}

private:
	Turkey *m_turkey;
};


void TestAdapterPattern()
{
	cout <<endl<< "________________adapter Pattern___________________" << endl;
	Duck *duck = new Duck;
	Turkey *turkey = new Turkey;

	TurkeyAdapter *turkeyAdapter = new TurkeyAdapter(turkey);

	turkeyAdapter->request();
}

#endif // !_ADAPTERPATTERN_H_
