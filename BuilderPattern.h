#ifndef _BUILDERPATTERN_H_
#define _BUILDERPATTERN_H_
#pragma once
#include <iostream>
using namespace std;

/*************************************************
Author:toni
Date:2016-12-3
contain: OS �� computer
Description:
��һ�����Ӷ���Ĺ��������ı�ʾ���룬ʹ��ͬ���Ĺ������̿��Դ�����ͬ�ı�ʾ��
1�����������Ӷ�����㷨Ӧ�ö����ڸö������ɲ����Լ����ǵ�װ�䷽ʽʱ
2����������̱�����������Ķ����в�ͬ�ı�ʾʱ

ʹ�ô�����ģʽ�Ļ���������
1����Ҫ�����һ�����࣬���еĶ��󴴽�ʱ�����̳���������ഴ����

2����Ҫ����һ�����õĵ��ݣ���������̬����ͬ�ı��֡����������̳����Ǹ�������࣬���Ǵ洢һ����������ָ�룬���ƶ�̬����

3�������������ʵ��������Ľӿ�
**************************************************/

//  �������,������Builder�Ļ���,�ṩ��ͬ���ֵĹ����ӿں��� 
class  Builder
{
public:
	Builder() {};
	virtual   ~Builder() {}

	//  ���麯��,�ṩ������ͬ���ֵĹ����ӿں��� 
	virtual   void  BuilderPartA() = 0;
	virtual   void  BuilderPartB() = 0;
};

//  ʹ��Builder������Ʒ,������Ʒ�Ĺ��̶�һ��,���ǲ�ͬ��builder�в�ͬ��ʵ��
//  �����ͬ��ʵ��ͨ����ͬ��Builder��������ʵ��,����һ��Builder��ָ��,ͨ�������ʵ�ֶ�̬���� 
class  Director
{
public:
	Director(Builder *  pBuilder) : m_pBuilder(pBuilder)
	{
	}
	~Director()
	{
		delete m_pBuilder;
		m_pBuilder = NULL;
	}

	//  Construct������ʾһ�������������������,��ͬ�Ĳ���֮���װ�䷽ʽ����һ�µ�,
	//  ���ȹ���PartA�����PartB,ֻ�Ǹ��ݲ�ͬ�Ĺ����߻��в�ͬ�ı�ʾ 
	void  Construct()
	{
		m_pBuilder->BuilderPartA();
		m_pBuilder->BuilderPartB();
	}

private:
	Builder *  m_pBuilder;
};

//  Builder��������,ʵ��BuilderPartA��BuilderPartB�ӿں��� 
class  ConcreateBuilder1: public  Builder
{
public:
	ConcreateBuilder1() {}
	virtual   ~ConcreateBuilder1() {}

	virtual   void  BuilderPartA()
	{
		std::cout << " BuilderPartA by ConcreateBuilder1\n ";
	}
	virtual   void  BuilderPartB()
	{
		std::cout << " BuilderPartB by ConcreateBuilder1\n ";
	}
};

//  Builder��������,ʵ��BuilderPartA��BuilderPartB�ӿں��� 
class  ConcreateBuilder2: public  Builder
{
public:
	ConcreateBuilder2() {}
	virtual   ~ConcreateBuilder2() {}

	virtual   void  BuilderPartA()
	{
		std::cout << " BuilderPartA by ConcreateBuilder2\n ";
	};
	virtual   void  BuilderPartB()
	{
		std::cout << " BuilderPartB by ConcreateBuilder2\n ";
	}
};









void TestBuilderPattern()
{
	cout << endl << "________________BuilderPattern___________________" << endl;

	Builder *  pBuilder1 = new  ConcreateBuilder1;
	Director  * pDirector1 = new  Director(pBuilder1);
	pDirector1->Construct();

	Builder *  pBuilder2 = new  ConcreateBuilder2;
	Director  * pDirector2 = new  Director(pBuilder2);
	pDirector2->Construct();

	delete pDirector1;
	delete pDirector2;

}


#endif // !_BUILDERPATTERN_H_

