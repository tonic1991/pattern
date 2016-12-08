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

Description: ���Զ�̬�ؽ����θ��ӵ������ϣ���Ҫ��չ���ܣ�װ�����ṩ�˱ȼ̳��߸��е��Ե��������
ʵ�֣� ����component , concreteComponent ,Decortor ,concreteDecortorA,concreteDecortorB;
װ����A,b��������װ��concretComponent �����нӿڣ�����ʵ���Լ��ķ���
**************************************************/

//������࣬�����ӿ�
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

//����װ����
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

/*װ����A����չ�����齨����*/
class ConcreteDecoratorFirst :public Decorator
{
public:
	virtual void operatoration()
	{
		Decorator::operatoration();
		cout << "concreteDecoratorFirst operatoration!" << endl;
	}
};

/*װ����B���Լ�����չ����*/
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
	cout << "_________________TestDecoratorPattern___________ ��" << endl;

	Component *conCpt = new ConcreteComponent();

	ConcreteDecoratorFirst *dctFst = new ConcreteDecoratorFirst();

	ConcreteDecoratorSecond *dctScd = new ConcreteDecoratorSecond();

	dctFst->setComponent(conCpt);    //Ҳ����д�����캯��
	//dctScd->setComponent(conCpt);
	dctScd->setComponent(dctFst);   //�õ�һ���͵ڶ���װ�Ρ�



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






