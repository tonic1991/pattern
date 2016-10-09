#ifndef _FACTORYPATTERM_H_
#define _FACTORYPATTERM_H_
#pragma once
#include <iostream>
using namespace std;
/*************************************************
Author:toni
Date:2016-10-06
contain:  
Description: Product ProductA ProductB
1.  简单工厂模式 Simple Factory Pattern：建立一个工厂（一个函数或一个类方法）来制造新的对象。
    SimpleFactory
2.  工厂方法模式：用来处理**对象的创建**，并将这样的行为**封装在子类**中，
    这样客户程序中关于超类的代码就和子类的对象的创建**解耦**了
	FactoryMethod FactoryMethodA FactoryMethodB 
3.  抽象工厂模式：提供一个接口用于创建相关或依赖对象的家族，而不需要指定具体类。
	AbstractFactory AbstractFactoryA AbstractFactoryB
**************************************************/

//简单工厂模式

typedef enum ProductTypeTag
{
	TypeA,
	TypeB,
	TypeC
}PRODUCTTYPE;

//产品接口
class Product
{
public:
	virtual void show() = 0;
	virtual ~Product(){}
};

class ProductA :public Product
{
public:
	void show()
	{
		cout << "Product A constructed! " << endl;
	}
};

class ProductB : public Product
{
public:
	void show() 
	{
		cout << "Product B constructed!" << endl;
	}
};

class ProductC : public Product
{
public:
	void show()
	{
		cout << "Product C constructed!" << endl;
	}
};

//1.简单工厂模式 Simple Factory Pattern：建立一个工厂（一个函数或一个类方法）来制造新的对象
class SimpleFactory
{
public :
	Product * createProduct(PRODUCTTYPE type)
	{
		switch (type)
		{
		case TypeA:
			return new ProductA(); 
			break;
		case TypeB:
			return new ProductB();
			break;
		case TypeC:
			return new ProductC();
			break;
		default:
			return NULL;
		}
	}
};


/*2. 工厂方法模式：用来处理**对象的创建**，并将这样的行为**封装在子类**中，
	 这样客户程序中关于超类的代码就和子类的对象的创建**解耦**了
*/
class FactoryMethod
{
public:
	virtual Product* createProduct() = 0;
	virtual ~FactoryMethod(){}
};

class FactoryMethodA :public FactoryMethod
{
public:
	Product* createProduct()
	{
		return new ProductA();
	}
};

class FactoryMethodB :public FactoryMethod
{
public:
	Product* createProduct()
	{
		return new ProductB();
	}
};

class FactoryMethodC :public FactoryMethod
{
public:
	Product* createProduct()
	{
		return new ProductC();
	}
};


class AbstractFactory
{
public:
	virtual ~AbstractFactory() {};

	virtual ProductA* createProductA()=0;

	virtual ProductB* createProductB()=0;
};


/*3.  抽象工厂模式：提供一个接口用于创建相关或依赖对象的家族，而不需要指定具体类。*/
class abFactoryA :public AbstractFactory
{
public:
	ProductA * createProductA()
	{
		cout << "abFactoryA create A" << endl;
		return new ProductA();
	}

	ProductB* createProductB()
	{
		cout << "abFactoryA create B" << endl;
		return new ProductB();
	}
};


class AbFactoryB :public AbstractFactory
{
public:
	ProductA * createProductA()
	{
		cout << "abFactoryB create A" << endl;
		return new ProductA();
	}

	ProductB* createProductB()
	{
		cout << "abFactoryB create B" << endl;
		return new ProductB();
	}
};


void TestFactoryPattern()
{
	cout<<endl<< "______________TestSimpleFactory________________" << endl;
	SimpleFactory *sf = new SimpleFactory();

	Product *productObjA = sf->createProduct(TypeA);
	if (productObjA != NULL)
		productObjA->show();
	Product *productObjB = sf->createProduct(TypeB);
	if (productObjB != NULL)
		productObjB->show();
	Product *productObjC = sf->createProduct(TypeC);
	if (productObjB != NULL)
		productObjA->show();

	delete sf, productObjA, productObjB, productObjC;

	cout << endl << "_______________TestFactoryMethod_____________________" << endl;
	
	FactoryMethod * factoryA = new FactoryMethodA();
	Product *pctA = factoryA->createProduct();
	pctA->show();

	FactoryMethod * factoryB = new FactoryMethodB();
	Product *pctB = factoryB->createProduct();
	pctB->show();
	
	delete factoryA, factoryB, pctA, pctB;

	cout << endl << "_____________________AbstractFactory_______________________" << endl;
	AbstractFactory *abFct1 = new abFactoryA();  //工厂1

	ProductA *pdcA1 = abFct1->createProductA();
	ProductB *pdcB1 = abFct1->createProductB();

	AbstractFactory *abFct2 = new AbFactoryB();

	Product *pdcA2 = abFct2->createProductA();
	Product *pdcB2 = abFct2->createProductB();


	delete abFct1, abFct2, pdcA1, pdcB1, pdcA2, pdcB2;

}

#endif //_FACTORYPATTERN_H_