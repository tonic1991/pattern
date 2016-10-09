#include <iostream>

#include "Strategy pattern.h"
#include "ObserverPattern.hpp"
#include "DecoratorPattern.h"
#include "FactoryPattern.h"
#include "SingletonPattern.h"
#include "CommandPattern.h"

void main()
{
	//���Բ���ģʽ
	//TestStrategyPattern();

	//���Թ۲���ģʽ
	TestObserverPattern();

	//����װ����ģʽdecortor
	TestDecoratorPattern();

	//���Թ���ģʽ
	TestFactoryPattern();

	//���Ե���ģʽ
	TestSingletonPattern();

	//��������ģʽ
	TestCommandPattern();

	system("pause");
}