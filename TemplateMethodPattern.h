#ifndef _TEMPLATEMETHODPATTERN_H_
#define _TEMPLATEMETHODPATTERN_H_
#pragma once
#include <iostream>
using namespace std;
/*************************************************
Author:toni
Date:2016-11-22
contain: CaffineBeverage, Coffee, Tea
Description：在一个方法中定义一个算法的骨架，而将一些步骤延迟到子类中去。
模版方法使得子类可以在不改变算法结构的情况下，重新定义算法中的某些步骤。
**************************************************/

//模版方法模式：
class CaffineBeverage //咖啡因饮料，抽象类
{
public:
	void prepareRecipe()   //冲泡方法，实现继承
	{
		boilWater();
		brew();    //冲泡
		pourInCup();
		if (customerWantsCondiments())         //钩子方法
		{
			addCondiments();
		}
	}

	//实现继承
	void boilWater()
	{
		cout << "烧开水" << endl;
	}

	virtual void brew() = 0;

	void pourInCup()
	{
		cout << "将其倒入杯子中" << endl;
	}

	virtual bool customerWantsCondiments()
	{
		return true;
	}

	virtual void addCondiments()
	{
		cout << "想加调料...但没说加什么" << endl;
	}

	virtual ~CaffineBeverage() {};
};


class Coffee :public CaffineBeverage
{
public:
	void brew()
	{
		cout << "用开水冲咖啡" << endl;
	}

	//bool customerWantsCondiments()    //钩子方法
	//{
	//	char input;
	//	cout << "would you like milk and sugar with you coffee? (y/n)" << endl;
	//	cin >> input;
	//    
	//	return input == 'y' ? true : false;
	//}

	void addCondiments()
	{
		cout << "加糖和牛奶" << endl;
	}
};

class Tea :public CaffineBeverage
{
public:
	void brew()
	{
		cout << "用开水泡茶叶" << endl;
	}

	//bool customerWantsCondiments()
	//{
	//	char input;
	//	cout << "would you like lemon with your tea? (y/n)" << endl;
	//	cin >> input;
	//	return input == 'y' ? true : false;
	//}

	void addCondiments()
	{
		cout << "加柠檬" << endl;
	}
};




void TestTemplateMethodPattern()
{
	cout << endl << "______________TestTemplateMethodPattern________________" << endl;
	
	CaffineBeverage* coffee = new Coffee();

	coffee->prepareRecipe();

	cout << endl;

	CaffineBeverage* tea = new Tea();

	tea->prepareRecipe();

	delete coffee, tea;
}

#endif //_TEMPLATEMETHODPATTERN_H_