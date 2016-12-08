#ifndef _COMMANDPATTERN_H_
#define _COMMANDPATTERN_H_
#pragma once
#include <iostream>
#include <vector>
using namespace std;

/*************************************************
Author:toni
Date:2016-10-08
contain: Cooker 除了cooker还可以加其他的职业light-tv  Command    CookMeetCmd   CookVegetableCmd
		Waiter.notify ,excute
Description: 将请求封装成对象，这可以让你使用不同的请求，队列，或者日志请求来参数化其他对象。也支持撤销操作。
**************************************************/

//cooker 执行者
class Cooker
{
public :
	void cookMeet() { cout << "cookMeet !" << endl; }
	void cookvegetable() { cout << "vegetable !" << endl; }
};

class Command
{
public:
	Command(Cooker *cook):receiver(cook) { }
	virtual void excute()=0;
	virtual ~Command(){}
protected:
	Cooker *receiver;
};

//做肉命令
class CookMeetCmd :public Command
{
public:
	CookMeetCmd(Cooker *cook):Command(cook){}
	virtual void excute() { receiver->cookMeet(); }
};


//做菜命令
class CookVegetableCmd :public Command
{
public:
	CookVegetableCmd(Cooker *cook) :Command(cook) {}
	virtual void excute() { receiver->cookvegetable(); }
};


//invoke 服务员
class Waiter
{
protected:
	vector<Command*> m_commandList;
public:
	void setCommand(Command *cmd) { m_commandList.push_back(cmd);  }

	//通知执行
	void notify() 
	{
		for (vector<Command*>::iterator ita = m_commandList.begin();ita != m_commandList.end(); ++ita)
		{
			(*ita)->excute();
		}
	}
};



void TestCommandPattern()
{
	cout << endl << "________TestCommandPattern______________" << endl;
	//店里添加烤肉师傅，菜单，服务员等顾客
	Cooker *cook = new Cooker();
	Command *meetCmd = new CookMeetCmd(cook);
	Command *vegeCamd = new CookVegetableCmd(cook);
	Waiter *girl = new Waiter();
	
	//点菜
	girl->setCommand(meetCmd);
	girl->setCommand(vegeCamd);
	girl->setCommand(meetCmd);
	//服务员通知
	girl->notify();

	delete cook;
	delete meetCmd;
	delete vegeCamd;
	delete girl;
}


#endif // !_COMMANDPATTERN_H_

