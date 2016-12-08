#ifndef _COMMANDPATTERN_H_
#define _COMMANDPATTERN_H_
#pragma once
#include <iostream>
#include <vector>
using namespace std;

/*************************************************
Author:toni
Date:2016-10-08
contain: Cooker ����cooker�����Լ�������ְҵlight-tv  Command    CookMeetCmd   CookVegetableCmd
		Waiter.notify ,excute
Description: �������װ�ɶ������������ʹ�ò�ͬ�����󣬶��У�������־��������������������Ҳ֧�ֳ���������
**************************************************/

//cooker ִ����
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

//��������
class CookMeetCmd :public Command
{
public:
	CookMeetCmd(Cooker *cook):Command(cook){}
	virtual void excute() { receiver->cookMeet(); }
};


//��������
class CookVegetableCmd :public Command
{
public:
	CookVegetableCmd(Cooker *cook) :Command(cook) {}
	virtual void excute() { receiver->cookvegetable(); }
};


//invoke ����Ա
class Waiter
{
protected:
	vector<Command*> m_commandList;
public:
	void setCommand(Command *cmd) { m_commandList.push_back(cmd);  }

	//ִ֪ͨ��
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
	//������ӿ���ʦ�����˵�������Ա�ȹ˿�
	Cooker *cook = new Cooker();
	Command *meetCmd = new CookMeetCmd(cook);
	Command *vegeCamd = new CookVegetableCmd(cook);
	Waiter *girl = new Waiter();
	
	//���
	girl->setCommand(meetCmd);
	girl->setCommand(vegeCamd);
	girl->setCommand(meetCmd);
	//����Ա֪ͨ
	girl->notify();

	delete cook;
	delete meetCmd;
	delete vegeCamd;
	delete girl;
}


#endif // !_COMMANDPATTERN_H_

