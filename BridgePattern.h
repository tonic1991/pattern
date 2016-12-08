#ifndef _BRIDGEPATTERN_H_
#define _BRIDGEPATTERN_H_
#pragma once
#include <iostream>
using namespace std;

/*************************************************
Author:toni
Date:2016-12-3
contain: OS ， computer
Description: 
优点
1.将实现抽离出来，再实现抽象，使得对象的具体实现依赖于抽象，满足了依赖倒转原则。

2.将可以共享的变化部分，抽离出来，减少了代码的重复信息。

3.对象的具体实现可以更加灵活，可以满足多个因素变化的要求。

缺点
1.客户必须知道选择哪一种类型的实现。
**************************************************/

//操作系统  
class OS
{
public:
	virtual void InstallOS_Imp() {}
	~OS(){}
};

class WindowsOS : public OS
{
public:
	void InstallOS_Imp()
	{
		cout << "安装windows" << endl;
	}
};

class LinuxOS : public OS
{
public:
	void InstallOS_Imp() { cout << "安装Linux操作系统" << endl; }
};

class UnixOS : public OS
{
public:
	void InstallOS_Imp() { cout << "安装Unix操作系统" << endl; }
};


// 计算机
class Computer
{
public:
	virtual void InstallOS(OS *os) {}
	~Computer() {}
};
class DellComputer : public Computer
{
public:
	void InstallOS(OS *os) { os->InstallOS_Imp(); }
};
class AppleComputer : public Computer
{
public:
	void InstallOS(OS *os) { os->InstallOS_Imp(); }
};
class HPComputer : public Computer
{
public:
	void InstallOS(OS *os) { os->InstallOS_Imp(); }
};

void TestBirdePattern()
{
	cout << endl << "________________TestBirdePattern___________________" << endl;
	OS *os1 = new WindowsOS();
	OS *os2 = new LinuxOS();

	Computer * computer = new AppleComputer();
	computer->InstallOS(os1);
	computer->InstallOS(os2);
	
	delete os1, os2, computer;
}


#endif // !_BRIDGEPATTERN_H_

