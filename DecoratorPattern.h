#ifndef _DECORATORPATTERN_H_
#define _DECORATORPATTERN_H_
#pragma once
#include <iostream>
using namespace std;
/*************************************************
Author:toni
Date:2016-10-06
contain: class :Component ConcreteComponent ; Decorator ,ConcreteDecoratorFirst ConcreteDecoratorSecond
Test: TestDecoratorPattern()

Description: 可以动态地将责任附加到对象上，若要拓展功能，装饰者提供了比继承者更有弹性的替代方案
实现： 父类component , concreteComponent ,Decortor ,concreteDecortorA,concreteDecortorB;
装饰类A,b不仅可以装饰concretComponent 的已有接口，还能实现自己的方法
**************************************************/

//抽象基类，公共接口
class Component
{
public:
	virtual ~Component(){}

	virtual void operatoration() = 0;
};

class ConcreteComponent :public Component
{
public:
	virtual ~ConcreteComponent() {}

	virtual  void operatoration() 
	{
		cout << "ConcreteComponent operatoration!" << endl;
	}
};

//抽象装饰类
class Decorator :public Component
{
protected:
	Component *cpt;

public:
	Decorator()
	{
		cpt = NULL;
	}
	virtual ~Decorator() {}

	virtual void setComponent(Component *cpt) 
	{
		this->cpt = cpt;
	}
	
	virtual void operatoration()
	{
		if (cpt != NULL)
			cpt->operatoration();
	}
};

/*装饰类A有扩展具体组建函数*/
class ConcreteDecoratorFirst :public Decorator
{
public:
	virtual void operatoration()
	{
		Decorator::operatoration();
		cout << "concreteDecoratorFirst operatoration!" << endl;
	}
};

/*装饰类B有自己的扩展函数*/
class ConcreteDecoratorSecond :public Decorator
{
public:
	virtual void operatoration()
	{
		Decorator::operatoration();
		cout << "concreteDecoratorSecond operatoration!" << endl;
	}

	virtual void addFoo()
	{
		cout << "concreteDecoratorSecond special Foo!" << endl;
	}
};


void TestDecoratorPattern()
{
	cout << "_________________TestDecoratorPattern___________ ！" << endl;

	Component *conCpt = new ConcreteComponent();

	ConcreteDecoratorFirst *dctFst = new ConcreteDecoratorFirst();

	ConcreteDecoratorSecond *dctScd = new ConcreteDecoratorSecond();

	dctFst->setComponent(conCpt);    //也可以写进构造函数
	//dctScd->setComponent(conCpt);
	dctScd->setComponent(dctFst);   //用第一个和第二个装饰。



	conCpt->operatoration();
	dctFst->operatoration();
	cout << "asdasd\n";
	dctScd->operatoration();

	dctScd->addFoo();

	delete conCpt;
	delete dctFst;
	delete dctScd;
}



#endif // !_DECORATORPATTERN_H_






