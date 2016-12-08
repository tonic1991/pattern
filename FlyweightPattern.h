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
Description��
������Ԫ�ࣨFlyweight��
�������о�����Ԫ��ĳ��ࡣΪ��Щ��涨����Ҫʵ�ֵĹ����ӿ�,��Щ��Ҫ����״̬(Exte�Ĳ�������ͨ�������Ĳ������롣������Ԫ�Ľӿ�ʹ����Ԫ��ÿ��ܣ����ǲ���ǿ������ʵ�й�����˲������е���Ԫ�����ǿ��Թ���ġ�
������Ԫ��(ConcreteFlyweight)
������Ԫ��ʵ���˳�����Ԫ�����涨�Ľӿڡ����������״̬�Ļ������븺��Ϊ����״̬�ṩ�洢�ռ䡣��Ԫ���������״̬�����������������Χ�����޹أ��Ӷ�ʹ����Ԫ���������ϵͳ�ڹ�����ʱ�������Ԫ���ֳ�Ϊ����������Ԫ�࣬��Ϊ������Ԫ�����ɵ���������Ԫ��ɫͨ�����϶��ɵġ�
���ܹ���ľ�����Ԫ��(UnsharableFlyweight)
���ܹ������Ԫ�࣬�ֽ���������Ԫ�ࡣһ��������Ԫ�������ɶ������Ԫ������ɣ���Щ��ɵĶ����ǿ��Թ���ģ����Ǹ�����Ԫ�౾�����ܹ���
��Ԫ������(FlyweightFactoiy)
��Ԫ�����ฺ�𴴽��͹�����Ԫ���󡣵�һ���ͻ��˶�������һ����Ԫ�����ʱ����Ԫ������Ҫ���ϵͳ���Ƿ��Ѿ���һ������Ҫ�����Ԫ��������Ѿ����ˣ���Ԫ������ɫ��Ӧ���ṩ������е���Ԫ�������ϵͳ��û���ʵ�����Ԫ����Ļ�����Ԫ������ɫ��Ӧ������һ���µĺ��ʵ���Ԫ����
�ͻ���(Client)
�ͻ�����Ҫ���д洢������Ԫ���������״̬��

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
		cout << "CharacterA��" << m_chSymbol << "(" << m_nWeight << "," << m_nHeight << ")" << endl;
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
		cout << "CharacterB��" << m_chSymbol << "(" << m_nWeight << "," << m_nHeight << ")" << endl;
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

	//����״̬ �洢����Ԫ�����ڲ����Ҳ����滷���ı���ı�  
	Character* ch1 = pFactory->GetCharacter('A');
	ch1->Display();

	//����״̬ �ͻ��˱���  
	Character* ch2 = pFactory->GetCharacter('B');
	ch2->SetSize(500, 800);
	ch2->Display();
}

#endif //_FLYWIIGHTPATTERN_