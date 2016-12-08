#ifndef _INTERPRETERPATTERN_
#define _INTERPRETERPATTERN_
#pragma once
#include <iostream>
#include <map>
using namespace std;
/*************************************************
Author:toni
Date:2016-12-06
contain:
Description��
������ʽ��ɫ(AbstractExpression)�� ����һ������Ľ��Ͳ���������ӿ�Ϊ���о�����ʽ��ɫ��Ҫʵ�ֵġ�
�ս�����ʽ��ɫ(TerminalExpression)�� ʵ�����ķ��е�Ԫ��������Ľ��Ͳ�����ͨ��һ��������ģʽ��ֻ��һ���ս�����ʽ�����ж��ʵ����Ӧ��ͬ���ս����
�ս�������������õ��Ļ���Ԫ�أ�һ�㲻���ٱ��ֽ⣬��: x -> xa�� ����a���ս������Ϊû�б�Ĺ�����԰�a��ɱ�ķ��ţ�����x���Ա�ɱ�ķ��ţ�����x�Ƿ��ս����
���ս�����ʽ��ɫ(NonterminalExpression)�� �ķ��е�ÿ�������Ӧ��һ�����ս���ʽ�� ���ս���ʽ�����߼��ĸ��ӳ̶ȶ����ӣ�ԭ����ÿ���ķ����򶼶�Ӧһ�����ս�����ʽ��
������ɫ(Context)������������֮���һЩȫ����Ϣ��

**************************************************/

//Interpreter Pattern
class Context
{
private:
	map<string, int> valueMap;
public:
	void addValue(string key, int value)
	{
		valueMap.insert(std::pair<string, int>(key, value));
	}

	int getValue(string key)
	{
		return valueMap[key];
	}
};

class AbstractExpression
{
public:
	virtual int interpreter(Context context) = 0;
	virtual ~AbstractExpression() {}
};

class AddNonterminalExpression : public AbstractExpression
{
private:
	AbstractExpression *left;
	AbstractExpression *right;

public:
	AddNonterminalExpression(AbstractExpression *left, AbstractExpression *right)
	{
		this->left = left;
		this->right = right;
	}

	int interpreter(Context context)
	{
		return this->left->interpreter(context) + this->right->interpreter(context);
	}
};

class SubtractNonterminalExpression : public AbstractExpression
{
private:
	AbstractExpression *left;
	AbstractExpression *right;
public:
	SubtractNonterminalExpression(AbstractExpression* left, AbstractExpression *right)
	{
		this->left = left;
		this->right = right;
	}

	int interpreter(Context context)
	{
		return this->left->interpreter(context) - this->right->interpreter(context);
	}

};

class TerminalExpression : public AbstractExpression
{
private:
	int i;

public:
	TerminalExpression(int i)
	{
		this->i = i;
	}

	int interpreter(Context context)
	{
		return this->i;
	}
};

void TestInterpreterPattern()
{
	cout << endl << "______________TestInterpreterPattern________________" << endl;

	Context context;
	context.addValue("a", 7);
	context.addValue("b", 8);
	context.addValue("c", 2);

	SubtractNonterminalExpression *subtractValue = new SubtractNonterminalExpression(new TerminalExpression(
		context.getValue("a")), new TerminalExpression(context.getValue("b")));

	AddNonterminalExpression *addValue = new AddNonterminalExpression(subtractValue, new TerminalExpression(
		context.getValue("c")));

	cout << addValue->interpreter(context);
}

#endif //_INTERPRETERPATTERN_