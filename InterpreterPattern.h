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
Description：
抽象表达式角色(AbstractExpression)： 声明一个抽象的解释操作，这个接口为所有具体表达式角色都要实现的。
终结符表达式角色(TerminalExpression)： 实现与文法中的元素相关联的解释操作，通常一个解释器模式中只有一个终结符表达式，但有多个实例对应不同的终结符，
终结符就是语言中用到的基本元素，一般不能再被分解，如: x -> xa， 这里a是终结符，因为没有别的规则可以把a变成别的符号，不过x可以变成别的符号，所以x是非终结符。
非终结符表达式角色(NonterminalExpression)： 文法中的每条规则对应于一个非终结表达式， 非终结表达式根据逻辑的复杂程度而增加，原则上每个文法规则都对应一个非终结符表达式。
环境角色(Context)：包含解释器之外的一些全局信息。

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