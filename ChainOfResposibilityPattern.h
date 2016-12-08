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
Description:使多个对象都有机会处理请求，
从而避免请求的发送者和接收者之间的耦合关系。
将这些对象连成一条链，并沿着这条链传递该请求，
直到有一个对象处理它为止。
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
			cout << "ConcreHandleA 我把处理权给后继节点。。。" << endl;
			this->GetSuccessor()->HandleRequest();
		}
		else
		{
			cout << "ConcreHandleA 没有后继，我必须自己处理" << endl;
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
			cout << "ConcreteHandleB 我把处理权给后继节点....." << endl;
			this->GetSuccessor()->HandleRequest();
		}
		else {
			cout << "ConcreteHandleB 没有后继了，我必须自己处理...." << endl;
		}
	
	}
protected:
private:
};






void TestChainOfResponsibilityPattern()
{
	cout << endl << "________TestChainOfResponsibilityPattern______________" << endl;
	//店里添加烤肉师傅，菜单，服务员等顾客
	
	Handle* h1 = new ConcreteHandleA();
	Handle* h2 = new ConcreteHandleB();
	Handle* h3 = new ConcreteHandleA();
	h1->SetSuccessor(h2);
	h2->SetSuccessor(h3);
	h1->HandleRequest();

	delete h1, h2,h3 ;
}


#endif // !_CHAINOFRESPONSIBILITYPATTERN_H_

