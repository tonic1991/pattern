#ifndef _MEMENTOPATTERN_H_
#define _MEMENTOPATTERN_H_
#pragma once
#include <iostream>
#include <vector>
using namespace std;

/*************************************************
Author:toni
Date:2016-12-06
contain: 备忘录模式
Description: 
Memento类定义了内部的状态，而Caretake类是一个保存进度的管理者，GameRole类是游戏角色类。
可以看到GameRole的对象依赖于Memento对象，而与Caretake对象无关。下面给出一个简单的是实现。
**************************************************/

// Memento类定义了内部的状态 需保存的信息
class Memento
{
public:
	int m_vitality; //生命值  
	int m_attack;   //进攻值  
	int m_defense;  //防守值  
public:
	Memento(int vitality, int attack, int defense) :
		m_vitality(vitality), m_attack(attack), m_defense(defense) {}
	Memento& operator=(const Memento &memento)
	{
		m_vitality = memento.m_vitality;
		m_attack = memento.m_attack;
		m_defense = memento.m_defense;
		return *this;
	}
};

//游戏角色  
class GameRole
{
private:
	int m_vitality;
	int m_attack;
	int m_defense;
public:
	GameRole() : m_vitality(100), m_attack(100), m_defense(100) {}
	Memento Save()  //保存进度，只与Memento对象交互，并不牵涉到Caretake  
	{
		Memento memento(m_vitality, m_attack, m_defense);
		return memento;
	}
	void Load(Memento memento)  //载入进度，只与Memento对象交互，并不牵涉到Caretake  
	{
		m_vitality = memento.m_vitality;
		m_attack = memento.m_attack;
		m_defense = memento.m_defense;
	}

	void Show() { cout << "vitality : " << m_vitality << ", attack : " << m_attack << ", defense : " << m_defense << endl; }
	
	void Attack() { m_vitality -= 10; m_attack -= 10;  m_defense -= 10; }
};

//保存的进度库  
class Caretake
{
public:
	Caretake() {}
	void Save(Memento menento) { m_vecMemento.push_back(menento); }
	Memento Load(int state) { return m_vecMemento[state]; }
private:
	vector<Memento> m_vecMemento;
};


void TestMementPatternPattern()
{
	cout << endl << "________________MementPattern___________________" << endl;
	
	Caretake caretake;
	GameRole role;
	role.Show();   //初始值  
	caretake.Save(role.Save()); //保存状态  
	role.Attack();
	role.Show();  //进攻后  
	role.Load(caretake.Load(0)); //载入状态   
	role.Show();  //恢复到状态0  

}

#endif // !_MEMENTOPATTERN_H_
