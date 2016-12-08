#ifndef _TEMPLATEMETHODPATTERN_H_
#define _TEMPLATEMETHODPATTERN_H_
#pragma once
#include <iostream>
using namespace std;
/*************************************************
Author:toni
Date:2016-11-22
contain: CaffineBeverage, Coffee, Tea
Description����һ�������ж���һ���㷨�ĹǼܣ�����һЩ�����ӳٵ�������ȥ��
ģ�淽��ʹ����������ڲ��ı��㷨�ṹ������£����¶����㷨�е�ĳЩ���衣
**************************************************/

//ģ�淽��ģʽ��
class CaffineBeverage //���������ϣ�������
{
public:
	void prepareRecipe()   //���ݷ�����ʵ�ּ̳�
	{
		boilWater();
		brew();    //����
		pourInCup();
		if (customerWantsCondiments())         //���ӷ���
		{
			addCondiments();
		}
	}

	//ʵ�ּ̳�
	void boilWater()
	{
		cout << "�տ�ˮ" << endl;
	}

	virtual void brew() = 0;

	void pourInCup()
	{
		cout << "���䵹�뱭����" << endl;
	}

	virtual bool customerWantsCondiments()
	{
		return true;
	}

	virtual void addCondiments()
	{
		cout << "��ӵ���...��û˵��ʲô" << endl;
	}

	virtual ~CaffineBeverage() {};
};


class Coffee :public CaffineBeverage
{
public:
	void brew()
	{
		cout << "�ÿ�ˮ�忧��" << endl;
	}

	//bool customerWantsCondiments()    //���ӷ���
	//{
	//	char input;
	//	cout << "would you like milk and sugar with you coffee? (y/n)" << endl;
	//	cin >> input;
	//    
	//	return input == 'y' ? true : false;
	//}

	void addCondiments()
	{
		cout << "���Ǻ�ţ��" << endl;
	}
};

class Tea :public CaffineBeverage
{
public:
	void brew()
	{
		cout << "�ÿ�ˮ�ݲ�Ҷ" << endl;
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
		cout << "������" << endl;
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