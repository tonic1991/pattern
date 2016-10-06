#ifndef _STRATEGPATTERN_H_
#define _STRATEGPATTERN_H_
#pragma once
#include <iostream>

using namespace std;

/*************************************************
Author:toni
Date:2016-10-06
contain: class :Traffic . ShipTour .  BusTour ; 
		 Test: TestStrategyPattern()
Description:Duck场景，定义了算法组，分别封装起来，让他们之间可以互相替换。
					 该模式让**算法的变化独立与使用算法的客户**。
**************************************************/
class Traffic //策略父类，定义主要的接口
{
public:
	virtual void multi_tour()=0;
};

class ShipTour: public Traffic  //子类1
{
public:
	void multi_tour() 
	{
		cout << "triffic by ship on the water!" << endl;
	}
};


class BusTour :public Traffic
{
public:
	void multi_tour()
	{
		cout << "triffic by bus is excited !" << endl;
	}
};

class TrafficContext   //调度类
{
public:
	TrafficContext(Traffic *tf)
	{
		this->tf = tf;
	}

	void setTourMethod(Traffic *tf) //设定方法
	{
		this->tf = tf;
	}

	void performTour()    //执行行为
	{
		tf->multi_tour();
	}	
private:
	Traffic *tf;	
};

void TestStrategyPattern()
{
	cout << "Test Stratagy Patern " << endl;
	TrafficContext *tc = new TrafficContext(new ShipTour());
	tc->performTour();
	tc->setTourMethod(new BusTour());
	tc->performTour();
}


#endif // _STRATEGPATTERN_H
