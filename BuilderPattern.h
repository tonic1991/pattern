#ifndef _BUILDERPATTERN_H_
#define _BUILDERPATTERN_H_
#pragma once
#include <iostream>
using namespace std;

/*************************************************
Author:toni
Date:2016-12-3
contain: OS ， computer
Description:
将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示。
1、当创建复杂对象的算法应该独立于该对象的组成部分以及它们的装配方式时
2、当构造过程必须允许被构造的对象有不同的表示时

使用创建者模式的基本方法：
1、需要抽象出一个基类，所有的对象创建时，都继承自这个基类创建。

2、需要创建一个调用的导演，由它来多态到不同的表现。（它并不继承自那个抽象基类，而是存储一个抽象基类的指针，类似多态）。

3、各个具体对象实例化基类的接口
**************************************************/

//  虚拟基类,是所有Builder的基类,提供不同部分的构建接口函数 
class  Builder
{
public:
	Builder() {};
	virtual   ~Builder() {}

	//  纯虚函数,提供构建不同部分的构建接口函数 
	virtual   void  BuilderPartA() = 0;
	virtual   void  BuilderPartB() = 0;
};

//  使用Builder构建产品,构建产品的过程都一致,但是不同的builder有不同的实现
//  这个不同的实现通过不同的Builder派生类来实现,存有一个Builder的指针,通过这个来实现多态调用 
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

	//  Construct函数表示一个对象的整个构建过程,不同的部分之间的装配方式都是一致的,
	//  首先构建PartA其次是PartB,只是根据不同的构建者会有不同的表示 
	void  Construct()
	{
		m_pBuilder->BuilderPartA();
		m_pBuilder->BuilderPartB();
	}

private:
	Builder *  m_pBuilder;
};

//  Builder的派生类,实现BuilderPartA和BuilderPartB接口函数 
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

//  Builder的派生类,实现BuilderPartA和BuilderPartB接口函数 
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

