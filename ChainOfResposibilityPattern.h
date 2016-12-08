#ifndef _CHAINOFRESPONSIBILITYPATTERN_H_
#define _CHAINOFRESPONSIBILITYPATTERN_H_
#pragma once
#include <iostream>
#include <vector>
using namespace std;

/*************************************************
Author:toni
Date:2016-12-4
contain: Handle ConcreteHandleA ConcreteHandleB
Waiter.notify ,excute
Description:ʹ��������л��ᴦ������
�Ӷ���������ķ����ߺͽ�����֮�����Ϲ�ϵ��
����Щ��������һ���������������������ݸ�����
ֱ����һ����������Ϊֹ��
**************************************************/


//
class Handle {
public:
	virtual ~Handle() 
	{
		delete _succ;
	}

	virtual void HandleRequest() = 0;

	void SetSuccessor(Handle* succ) 
	{
		_succ = succ;
	}

	Handle* GetSuccessor()
	{
		return _succ;
	}
protected:
	Handle() 
	{
		_succ = 0;
	}

	Handle(Handle* succ)
	{
		this->_succ = succ;
	}
private:
	Handle* _succ;
};

class ConcreteHandleA :public Handle {
public:
	ConcreteHandleA()
	{
	
	}

	~ConcreteHandleA()
	{
	
	}

	ConcreteHandleA(Handle* succ):Handle(succ)
	{

	}
	
	void HandleRequest()
	{
		if (this->GetSuccessor() != 0)
		{
			cout << "ConcreHandleA �ҰѴ���Ȩ����̽ڵ㡣����" << endl;
			this->GetSuccessor()->HandleRequest();
		}
		else
		{
			cout << "ConcreHandleA û�к�̣��ұ����Լ�����" << endl;
		}
	}
protected:
private:
};

class ConcreteHandleB :public Handle {
public:
	ConcreteHandleB()
	{ }
	~ConcreteHandleB() { }
	ConcreteHandleB(Handle* succ) :Handle(succ) {}
	void HandleRequest()
	{
		if (this->GetSuccessor() != 0) {
			cout << "ConcreteHandleB �ҰѴ���Ȩ����̽ڵ�....." << endl;
			this->GetSuccessor()->HandleRequest();
		}
		else {
			cout << "ConcreteHandleB û�к���ˣ��ұ����Լ�����...." << endl;
		}
	
	}
protected:
private:
};






void TestChainOfResponsibilityPattern()
{
	cout << endl << "________TestChainOfResponsibilityPattern______________" << endl;
	//������ӿ���ʦ�����˵�������Ա�ȹ˿�
	
	Handle* h1 = new ConcreteHandleA();
	Handle* h2 = new ConcreteHandleB();
	Handle* h3 = new ConcreteHandleA();
	h1->SetSuccessor(h2);
	h2->SetSuccessor(h3);
	h1->HandleRequest();

	delete h1, h2,h3 ;
}


#endif // !_CHAINOFRESPONSIBILITYPATTERN_H_

