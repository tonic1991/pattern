#ifndef _BRIDGEPATTERN_H_
#define _BRIDGEPATTERN_H_
#pragma once
#include <iostream>
using namespace std;

/*************************************************
Author:toni
Date:2016-12-3
contain: OS �� computer
Description: 
�ŵ�
1.��ʵ�ֳ����������ʵ�ֳ���ʹ�ö���ľ���ʵ�������ڳ���������������תԭ��

2.�����Թ���ı仯���֣���������������˴�����ظ���Ϣ��

3.����ľ���ʵ�ֿ��Ը������������������ر仯��Ҫ��

ȱ��
1.�ͻ�����֪��ѡ����һ�����͵�ʵ�֡�
**************************************************/

//����ϵͳ  
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
		cout << "��װwindows" << endl;
	}
};

class LinuxOS : public OS
{
public:
	void InstallOS_Imp() { cout << "��װLinux����ϵͳ" << endl; }
};

class UnixOS : public OS
{
public:
	void InstallOS_Imp() { cout << "��װUnix����ϵͳ" << endl; }
};


// �����
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

