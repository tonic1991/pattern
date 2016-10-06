#ifndef _OBSERVERPATTERN_H_
#define  _OBSERVERPATTERN_H_
#pragma once
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

/*************************************************
Author:toni
Date:2016-10-06
contain: class :SubjectObjec Observerbase ; SubjectData ,ConditionObserver
		 Test: TestObserverPattern()

Description: 在对象之间定义一对多的依赖，这样一来当一个对象改变状态。依赖它的对象都会收到通知。
	         实现：register,remove,notify（push）,pull()->observer->getData();
**************************************************/

/*************************************************
Function:       // 函数名称
Description:    // 函数功能、性能等的描述
Calls:          // 被本函数调用的函数清单
Table Accessed: // 被访问的表（此项仅对于牵扯到<a href="http://lib.csdn.net/base/14" class='replace_word' title="MySQL知识库" target='_blank' style='color:#df3434; font-weight:bold;'>数据库</a>操作的程序）
Table Updated: // 被修改的表（此项仅对于牵扯到数据库操作的程序）
Input:          // 输入参数说明，包括每个参数的作
// 用、取值说明及参数间关系。
Output:         // 对输出参数的说明。
Return:         // 函数返回值的说明
Others:         // 其它说明
*************************************************/

class ObserverBase;


/*主题接口类*/
class SubjectBase  
{

public:
	virtual void registerObserver(ObserverBase * ob) = 0;

	virtual void removeObserver(ObserverBase* ob) = 0;

	virtual void setData(int tep,int hum, int pre) = 0;

	virtual void dataChanged()  = 0;

	virtual void notifyObservers() = 0;

	virtual int getTemperature() const = 0;

	virtual int getHumidity() const = 0;

	virtual int getPressure() const = 0;

	virtual void setChangedStatus() = 0;  //set changed status

	virtual void clearChangerStatus() = 0;

	virtual bool getChangedStatus() const = 0; 

	virtual ~SubjectBase() {};
};


/*观察者基类*/
class ObserverBase
{
public:
	virtual void update(int tep, int hum, int pre) = 0;

	virtual void getData() = 0;

	virtual void display() = 0; //显示，可分离接口做其他事情
};

/*主题实现类*/
class SubjectData :public SubjectBase
{
private:
	list<ObserverBase* > listOb;
	int temperature;  //气温
	int humidity;	  //湿度
	int pressure;	  //气压
	bool dataChangedStatus;

public:
	virtual void registerObserver(ObserverBase * ob)
	{
		if (find(listOb.begin(), listOb.end(), ob) == listOb.end())
		listOb.push_back(ob);
	}

	virtual void removeObserver(ObserverBase* ob)
	{
		listOb.remove(ob);
	}

	virtual void setData(int tep, int hum, int pre)  //数据修改
	{
		this->temperature = tep;
		this->humidity = hum;
		this->pressure = pre;

		setChangedStatus();

		dataChanged();
	}


	virtual void dataChanged() 
	{
		if(dataChangedStatus)
		{
			notifyObservers();
		}
		dataChangedStatus = false;
	}

	virtual void notifyObservers()
	{
		for (list<ObserverBase*>::iterator ita = listOb.begin(); ita != listOb.end(); ++ita)
		{
			(*ita)->update(temperature, humidity, pressure);
		}
	}

	virtual int getTemperature() const
	{
		return temperature;
	}

	virtual int getHumidity() const
	{
		return humidity;
	}

	virtual int getPressure() const
	{
		return pressure;
	}

	virtual void setChangedStatus()  //set changed status
	{
		dataChangedStatus = true;
	}

	virtual void clearChangerStatus()
	{
		dataChangedStatus = false;
	}

	virtual bool getChangedStatus() const  //控制频率？
	{
		return dataChangedStatus;
	}

};

//普通数据观察者
class CondititonObserver : public ObserverBase
{
private:
	int temperature;  //气温
	int humidity;	  //湿度
	int pressure;	  //气压
	SubjectBase* sub;

public:
	CondititonObserver(SubjectBase *sub)
	{
		this->sub = sub;
		sub->registerObserver(this);
	}
	
	virtual void update(int tep, int hum, int pre)
	{
		this->temperature = tep;
		this->humidity = hum;
		this->pressure = pre;
		display();
	}

	virtual void getData()
	{
		temperature = sub->getTemperature();
		humidity = sub->getHumidity();
		pressure = sub->getPressure();
		display();
	}

	virtual void display()  //显示，可分离接口做其他事情
	{
		cout << "CondititonObserver :\t temperature: " << temperature << "\t humidity: " << humidity
			<< "\tpressure： " << pressure << endl;
	}
};

void TestObserverPattern()
{
	SubjectData *sub = new SubjectData();
	
	CondititonObserver *condOb1 = new CondititonObserver(sub);

	CondititonObserver *condOb2 = new CondititonObserver(sub); //还可以实现不同的观察者类型，关注不同数据

	sub->setData(26, 50, 60);

	condOb1->getData();

	delete sub;
	delete condOb1;
	delete condOb2;	
}





#endif // _OBSERVERPATTERN_H_


