#ifndef _COMPOSITEPATTERN_H_
#define _COMPOSITEPATTERN_H_
#pragma once
#include <iostream>
#include <vector>
using namespace std;
/*************************************************
Author:toni
Date:2016-11-22
contain: 
	�������:
		1)Component:Ϊ����еĶ��������ӿڣ��������๲�нӿڵ�ȱʡ��Ϊ(�������Add,Remove,GetChild����)��
			����һ���ӿں������Է���Component�������.
	�ӿں���:
	1)Component::Operatation:�����˸���������е���Ϊ�ӿڣ��ɸ�������ľ���ʵ��.
	2)Component::Add���һ�������
	3)Component::Remove::ɾ��һ�������.
	4)Component::GetChild:����������ָ��.
Description��


**************************************************/

//���ģʽ��
//���������
class ComponentBase
{
public:
	virtual void operation() = 0;
	virtual void add(ComponentBase* ) { cout << "add" << endl; }
	virtual void remove(ComponentBase*) {}
	virtual ComponentBase* getChild(int index) { return NULL; }
	virtual ~ComponentBase() {};
protected:
	vector<ComponentBase*> m_comVec;  //����vector�����������
};

//Ҷ����
class Leaf :public ComponentBase
{
public:
	virtual void operation() { cout << "Leaf::operation" << endl; }
	Leaf() {}
	~Leaf() {}
};

class Composite :public ComponentBase
{
public:
	Composite() {}
	~Composite() {}
	void operation() { cout << "Composite::operation" << endl; }
	void add(ComponentBase* com)
	{	
		cout << "Composite::add()" << endl;
		this->m_comVec.push_back(com);
	}

	void remove(ComponentBase* com)
	{
		cout << "Composite::remove()" << endl;
		vector<ComponentBase* >::iterator it = find(this->m_comVec.begin(), this->m_comVec.end(), com);
		this->m_comVec.erase(it);
	}

	ComponentBase* getChild(int index)
	{
		if (index < 0 || index>this->m_comVec.size() )
		{	
			return NULL;
		}
		return this->m_comVec[index];
	}
};

void TestCompositePattern()
{
	cout << endl << "______________TestCompositePattern________________" << endl;

	/*
	������Ҷ��Leaf����Composite����pRoot��pCom��ʵ����Operation�ӿڣ����Կ���һ�¶Դ���ֱ�ӵ���Operation()
	�����ˡ�ʹ���û��Ե����������϶����ʹ�þ���һ���ԡ���
	*/
	Composite* pRoot = new Composite();

	//��϶������Ҷ�ӽڵ�
	pRoot->add(new Leaf());  

	Leaf* pLeaf1 = new Leaf();
	Leaf* pLeaf2 = new Leaf();

	//�����Ҷ�������Ҷ����û������ġ�
	//����Ҷ������϶���̳�����ͬ�Ľӿڣ������﷨���ǶԵģ�ʵ����ʲôҲû��(�̳��Ի���Component��Add����)��
	//Ҷ�ӽڵ�ֻʵ����Operation����������Add��Remove��GetChild���̳��Ի��࣬û��ʵ�����塣
	pLeaf1->add(pLeaf2);
	pLeaf1->remove(pLeaf2);
	//ִ��Ҷ��Operation����
	pLeaf1->operation();

	//��϶���ʵ���˻���Component�����нӿڣ����Կ��������ֲ���(Add��Remove��GetChild��Operation)��
	Composite* pCom = new Composite();
	//��϶������Ҷ�ӽڵ�
	pCom->add(pLeaf1);
	//��϶������Ҷ�ӽڵ�
	pCom->add(pLeaf2);
	//ִ����϶���Operation����
	pCom->operation();

	//��϶��������϶���
	pRoot->add(pCom);

	//ִ����϶���Operation����
	pRoot->operation();

	//Component* cp = pCom->GetChild(0);
	//cp->Operation();

	//pCom->Remove(pLeaf1);

}

#endif //_COMPOSITEPATTERN_H_