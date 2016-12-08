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
	抽象基类:
		1)Component:为组合中的对象声明接口，声明了类共有接口的缺省行为(如这里的Add,Remove,GetChild函数)，
			声明一个接口函数可以访问Component的子组件.
	接口函数:
	1)Component::Operatation:定义了各个组件共有的行为接口，由各个组件的具体实现.
	2)Component::Add添加一个子组件
	3)Component::Remove::删除一个子组件.
	4)Component::GetChild:获得子组件的指针.
Description：


**************************************************/

//组合模式：
//抽象组件类
class ComponentBase
{
public:
	virtual void operation() = 0;
	virtual void add(ComponentBase* ) { cout << "add" << endl; }
	virtual void remove(ComponentBase*) {}
	virtual ComponentBase* getChild(int index) { return NULL; }
	virtual ~ComponentBase() {};
protected:
	vector<ComponentBase*> m_comVec;  //采用vector保存子组件；
};

//叶子项
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
	不管是叶子Leaf还是Composite对象pRoot、pCom都实现了Operation接口，所以可以一致对待，直接调用Operation()
	体现了“使得用户对单个对象和组合对象的使用具有一致性。”
	*/
	Composite* pRoot = new Composite();

	//组合对象添加叶子节点
	pRoot->add(new Leaf());  

	Leaf* pLeaf1 = new Leaf();
	Leaf* pLeaf2 = new Leaf();

	//这里的叶子再添加叶子是没有意义的。
	//由于叶子与组合对象继承了相同的接口，所以语法上是对的，实际上什么也没做(继承自基类Component的Add方法)。
	//叶子节点只实现了Operation方法，其他Add、Remove、GetChild都继承自基类，没有实际意义。
	pLeaf1->add(pLeaf2);
	pLeaf1->remove(pLeaf2);
	//执行叶子Operation操作
	pLeaf1->operation();

	//组合对象实现了基类Component的所有接口，所以可以做各种操作(Add、Remove、GetChild、Operation)。
	Composite* pCom = new Composite();
	//组合对象添加叶子节点
	pCom->add(pLeaf1);
	//组合对象添加叶子节点
	pCom->add(pLeaf2);
	//执行组合对象Operation操作
	pCom->operation();

	//组合对象添加组合对象
	pRoot->add(pCom);

	//执行组合对象Operation操作
	pRoot->operation();

	//Component* cp = pCom->GetChild(0);
	//cp->Operation();

	//pCom->Remove(pLeaf1);

}

#endif //_COMPOSITEPATTERN_H_