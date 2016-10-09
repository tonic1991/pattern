#include <iostream>

#include "Strategy pattern.h"
#include "ObserverPattern.hpp"
#include "DecoratorPattern.h"
#include "FactoryPattern.h"
#include "SingletonPattern.h"
#include "CommandPattern.h"

void main()
{
	//测试策略模式
	//TestStrategyPattern();

	//测试观察者模式
	TestObserverPattern();

	//测试装饰者模式decortor
	TestDecoratorPattern();

	//测试工厂模式
	TestFactoryPattern();

	//测试单例模式
	TestSingletonPattern();

	//测试命令模式
	TestCommandPattern();

	system("pause");
}