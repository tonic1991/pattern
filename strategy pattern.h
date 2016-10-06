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
Description:Duck�������������㷨�飬�ֱ��װ������������֮����Ի����滻��
					 ��ģʽ��**�㷨�ı仯������ʹ���㷨�Ŀͻ�**��
**************************************************/
class Traffic //���Ը��࣬������Ҫ�Ľӿ�
{
public:
	virtual void multi_tour()=0;
};

class ShipTour: public Traffic  //����1
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

class TrafficContext   //������
{
public:
	TrafficContext(Traffic *tf)
	{
		this->tf = tf;
	}

	void setTourMethod(Traffic *tf) //�趨����
	{
		this->tf = tf;
	}

	void performTour()    //ִ����Ϊ
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
