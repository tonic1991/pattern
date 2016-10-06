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

Description: �ڶ���֮�䶨��һ�Զ������������һ����һ������ı�״̬���������Ķ��󶼻��յ�֪ͨ��
	         ʵ�֣�register,remove,notify��push��,pull()->observer->getData();
**************************************************/

/*************************************************
Function:       // ��������
Description:    // �������ܡ����ܵȵ�����
Calls:          // �����������õĺ����嵥
Table Accessed: // �����ʵı����������ǣ����<a href="http://lib.csdn.net/base/14" class='replace_word' title="MySQL֪ʶ��" target='_blank' style='color:#df3434; font-weight:bold;'>���ݿ�</a>�����ĳ���
Table Updated: // ���޸ĵı����������ǣ�������ݿ�����ĳ���
Input:          // �������˵��������ÿ����������
// �á�ȡֵ˵�����������ϵ��
Output:         // �����������˵����
Return:         // ��������ֵ��˵��
Others:         // ����˵��
*************************************************/

class ObserverBase;


/*����ӿ���*/
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


/*�۲��߻���*/
class ObserverBase
{
public:
	virtual void update(int tep, int hum, int pre) = 0;

	virtual void getData() = 0;

	virtual void display() = 0; //��ʾ���ɷ���ӿ�����������
};

/*����ʵ����*/
class SubjectData :public SubjectBase
{
private:
	list<ObserverBase* > listOb;
	int temperature;  //����
	int humidity;	  //ʪ��
	int pressure;	  //��ѹ
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

	virtual void setData(int tep, int hum, int pre)  //�����޸�
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

	virtual bool getChangedStatus() const  //����Ƶ�ʣ�
	{
		return dataChangedStatus;
	}

};

//��ͨ���ݹ۲���
class CondititonObserver : public ObserverBase
{
private:
	int temperature;  //����
	int humidity;	  //ʪ��
	int pressure;	  //��ѹ
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

	virtual void display()  //��ʾ���ɷ���ӿ�����������
	{
		cout << "CondititonObserver :\t temperature: " << temperature << "\t humidity: " << humidity
			<< "\tpressure�� " << pressure << endl;
	}
};

void TestObserverPattern()
{
	SubjectData *sub = new SubjectData();
	
	CondititonObserver *condOb1 = new CondititonObserver(sub);

	CondititonObserver *condOb2 = new CondititonObserver(sub); //������ʵ�ֲ�ͬ�Ĺ۲������ͣ���ע��ͬ����

	sub->setData(26, 50, 60);

	condOb1->getData();

	delete sub;
	delete condOb1;
	delete condOb2;	
}





#endif // _OBSERVERPATTERN_H_


