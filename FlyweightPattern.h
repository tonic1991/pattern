#ifndef _FLYWIIGHTPATTERN_
#define _FLYWIIGHTPATTERN_
#pragma once
#include <iostream>
#include <map>
using namespace std;
/*************************************************
Author:toni
Date:2016-12-05
contain: 
Description：
抽象享元类（Flyweight）
它是所有具体享元类的超类。为这些类规定出需要实现的公共接口,那些需要外蕴状态(Exte的操作可以通过方法的参数传入。抽象享元的接口使得享元变得可能，但是并不强制子类实行共享，因此并非所有的享元对象都是可以共享的。
具体享元类(ConcreteFlyweight)
具体享元类实现了抽象享元类所规定的接口。如果有内蕴状态的话，必须负责为内蕴状态提供存储空间。享元对象的内蕴状态必须与对象所处的周围环境无关，从而使得享元对象可以在系统内共享。有时候具体享元类又称为单纯具体享元类，因为复合享元类是由单纯具体享元角色通过复合而成的。
不能共享的具体享元类(UnsharableFlyweight)
不能共享的享元类，又叫做复合享元类。一个复合享元对象是由多个单享元对象组成，这些组成的对象是可以共享的，但是复合享元类本身并不能共享。
享元工厂类(FlyweightFactoiy)
享元工厂类负责创建和管理享元对象。当一个客户端对象请求一个享元对象的时候，享元工厂需要检查系统中是否已经有一个符合要求的享元对象，如果已经有了，享元工厂角色就应当提供这个已有的享元对象；如果系统中没有适当的享元对象的话，享元工厂角色就应当创建一个新的合适的享元对象。
客户类(Client)
客户类需要自行存储所有享元对象的外蕴状态。

**************************************************/

//flyWeight Pattern
class Character
{
public:
	virtual ~Character() {};

	virtual void SetSize(int, int) = 0;
	virtual void Display() = 0;
protected:
	Character() {};
	char m_chSymbol;
	int m_nWeight;
	int m_nHeight;
};

class CharacterA : public Character
{
public:
	CharacterA()
	{
		this->m_chSymbol = 'A';
		this->m_nWeight = 100;
		this->m_nHeight = 200;
	}
	virtual ~CharacterA() {};

	void SetSize(int nWeight, int nHeight)
	{
		this->m_nWeight = nWeight;
		this->m_nHeight = nHeight;
	}
	void Display()
	{
		cout << "CharacterA：" << m_chSymbol << "(" << m_nWeight << "," << m_nHeight << ")" << endl;
	}
};



class CharacterB : public Character
{
public:
	CharacterB() 
	{
		this->m_chSymbol = 'B';
		this->m_nWeight = 100;
		this->m_nHeight = 200;
	}
	virtual ~CharacterB() {}

	void SetSize(int nWeight, int nHeight)
	{
		this->m_nWeight = nWeight;
		this->m_nHeight = nHeight;
	}
	void Display()
	{
		cout << "CharacterB：" << m_chSymbol << "(" << m_nWeight << "," << m_nHeight << ")" << endl;
	}
};

class CharacterFactory
{
public:
	CharacterFactory()
	{
		m_mChar.insert(make_pair<char, Character*>('A', new CharacterA));
		m_mChar.insert(make_pair<char, Character*>('B', new CharacterB));
	}
	virtual ~CharacterFactory() {}

	Character* GetCharacter(char chIn)
	{
		map<char, Character*>::iterator it = m_mChar.find(chIn);
		if (it != m_mChar.end())
		{
			return (Character*)it->second;
		}

		return NULL;
	
	}
private:
	std::map<char, Character*> m_mChar;
};


void TestFlyweightPattern()
{
	cout << endl << "______________TestFlyweightPattern________________" << endl;

	CharacterFactory* pFactory = new CharacterFactory;

	//内蕴状态 存储在享元对象内部并且不会随环境改变而改变  
	Character* ch1 = pFactory->GetCharacter('A');
	ch1->Display();

	//外蕴状态 客户端保存  
	Character* ch2 = pFactory->GetCharacter('B');
	ch2->SetSize(500, 800);
	ch2->Display();
}

#endif //_FLYWIIGHTPATTERN_