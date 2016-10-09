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
Description: 确保一个类只有一个实例，并提供一个全局的访问点。
**************************************************/

//自己管理的唯一实例
class Singleton
{
private:
	Singleton()
	{
		cout << "Singleton created! " << endl;
	}
	static std::mutex *mtx;

	static Singleton * m_singleton;

	class Garbo  //程序结束时自动回收
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
	
	Singleton *sg1 = Singleton::getInstance();  //第二个实例不会再次调用，而是引用类中的静态实例
}












#endif // !_SINGLETONPATTERN_H_

