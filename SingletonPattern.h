#ifndef _SINGLETONPATTERN_H_
#define _SINGLETONPATTERN_H_
#pragma once
#include <iostream>
#include <mutex>
using namespace std;
/*************************************************
Author:toni
Date:2016-10-06
contain: Singleton
Description: ȷ��һ����ֻ��һ��ʵ�������ṩһ��ȫ�ֵķ��ʵ㡣
**************************************************/

//�Լ������Ψһʵ��
class Singleton
{
private:
	Singleton()
	{
		cout << "Singleton created! " << endl;
	}
	static std::mutex *mtx;

	static Singleton * m_singleton;

	class Garbo  //�������ʱ�Զ�����
	{
	public:
		~Garbo()
		{
			if (Singleton::m_singleton != NULL)
				delete Singleton::m_singleton;
		}
	};
	static Garbo garbo;
public:
		
	static Singleton * getInstance()
	{
		if (m_singleton == NULL)
		{
			mtx->lock();
			if (m_singleton == NULL)
			{
				m_singleton = new Singleton();
			}
			mtx->unlock();
		}
		return m_singleton;
	}

};

Singleton* Singleton::m_singleton = NULL;

mutex* Singleton::mtx = new mutex();

void TestSingletonPattern()
{
	cout << endl << "TestSingletonPattern" << endl;
	
	Singleton *sg = Singleton::getInstance();
	
	Singleton *sg1 = Singleton::getInstance();  //�ڶ���ʵ�������ٴε��ã������������еľ�̬ʵ��
}












#endif // !_SINGLETONPATTERN_H_

