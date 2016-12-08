#ifndef _STATEPATTERN_H_
#define _STATEPATTERN_H_
#pragma once
#include <iostream>
#include <vector>
using namespace std;
/*************************************************
Author:toni
Date:2016-11-22
contain: Work State --4�����
Description��
һ����������������ʱ������״̬��������ѹ����������������
������ʱ����ͬ��״̬���в�ͬ����Ϊ����ǰ��״̬�����ʵ���ʱ�����ɵ���һ״̬��
��ʵ�û���ʹ��ʱ������֪����ǰ��״̬��Ҳ����֪����ǰ��״̬���û�ֻ��Ҫ��������һ����ʼ״̬�����õ�һ��ֹͣ״̬�����ˡ�

**************************************************/

//״̬ģʽģʽ��

class Work;
//״̬
class State
{
public:
	virtual void operation(Work *work) {}
	~State() {}
};

class Work
{
private:
	State *m_state; //Ŀǰ״̬
	int m_step;     //����
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

//����״̬
//����״̬  4
class ExhaustState : public State
{
public:
	void operation(Work *work)  //��������  
	{
		if (work->getStep() == 4)
		{
			cout << "Step : " << work->getStep() << "��������" << endl;
		}
	}
};

//����״̬  3
class ActState : public State
{
public:
	void operation(Work *work) //��������  
	{
		if (work->getStep() == 3)
		{
			cout << "Step : " << work->getStep() << "��������" << endl;
		}
		else
		{
			work->setState(new ExhaustState());
			work->operation();
		}
	}
};

//ѹ��״̬  2
class CompressState : public State
{
public:
	void operation(Work *work) //ѹ������  
	{
		if (work->getStep() == 2)
		{
			cout << "Step : " << work->getStep() << "ѹ������" << endl;
		}
		else
		{
			work->setState(new ActState());
			work->operation();
		}
	}
};

//����״̬  
class InhaleState : public State
{
public:
	void operation(Work *work) //��������  
	{
		if (work->getStep() == 1)
		{
			cout << "Step : " << work->getStep() << "��������" << endl;
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

	State *st = new InhaleState();  //����״̬

	Work *work = new Work(st);

	for (int i = 1; i < 5; ++i)
	{
		work->setStep(i);
		work->operation();  //����
	}

	delete  work;
//	delete st;  //���Ӧ�ý���˭��delete?
}


#endif //_STATEPATTERN_H_