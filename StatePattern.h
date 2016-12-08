#ifndef _STATEPATTERN_H_
#define _STATEPATTERN_H_
#pragma once
#include <iostream>
#include <vector>
using namespace std;
/*************************************************
Author:toni
Date:2016-11-22
contain: Work State --4个类别
Description：
一般汽车发动机工作时有四种状态，吸气、压缩、做功和排气。
在运行时，不同的状态会有不同的行为，当前的状态机在适当的时候会过渡到下一状态。
其实用户在使用时根本不知道当前的状态，也无需知道当前的状态。用户只需要给发动机一个初始状态，最后得到一个停止状态就行了。

**************************************************/

//状态模式模式：

class Work;
//状态
class State
{
public:
	virtual void operation(Work *work) {}
	~State() {}
};

class Work
{
private:
	State *m_state; //目前状态
	int m_step;     //步骤
public:
	Work(State *state) :m_state(state) ,m_step(0){}
	
	~Work() { 
	//	delete m_state; 
	}

	int getStep()
	{
		return m_step;
	}

	void setStep(int step)
	{
		m_step = step;
	}

	void setState(State *state)
	{
		delete m_state;
		m_state = state;
	}

	void operation()
	{
		m_state->operation(this);
	}
};

//排气状态
//排气状态  4
class ExhaustState : public State
{
public:
	void operation(Work *work)  //排气操作  
	{
		if (work->getStep() == 4)
		{
			cout << "Step : " << work->getStep() << "排气操作" << endl;
		}
	}
};

//做功状态  3
class ActState : public State
{
public:
	void operation(Work *work) //做功操作  
	{
		if (work->getStep() == 3)
		{
			cout << "Step : " << work->getStep() << "做功操作" << endl;
		}
		else
		{
			work->setState(new ExhaustState());
			work->operation();
		}
	}
};

//压缩状态  2
class CompressState : public State
{
public:
	void operation(Work *work) //压缩操作  
	{
		if (work->getStep() == 2)
		{
			cout << "Step : " << work->getStep() << "压缩操作" << endl;
		}
		else
		{
			work->setState(new ActState());
			work->operation();
		}
	}
};

//吸气状态  
class InhaleState : public State
{
public:
	void operation(Work *work) //吸气操作  
	{
		if (work->getStep() == 1)
		{
			cout << "Step : " << work->getStep() << "吸气操作" << endl;
		}
		else
		{
			work->setState(new CompressState());
			work->operation();
		}
	}
};







void TestStatePattern()
{
	cout << endl << "______________TestStatePattern________________" << endl;

	State *st = new InhaleState();  //初试状态

	Work *work = new Work(st);

	for (int i = 1; i < 5; ++i)
	{
		work->setStep(i);
		work->operation();  //操作
	}

	delete  work;
//	delete st;  //这个应该交由谁来delete?
}


#endif //_STATEPATTERN_H_