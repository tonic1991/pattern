#include <iostream>

#include "Strategy pattern.h"
#include "ObserverPattern.hpp"
#include "DecoratorPattern.h"
#include "FactoryPattern.h"
#include "SingletonPattern.h"
#include "CommandPattern.h"
#include "AdapterPattern.h"
#include "TemplateMethodPattern.h"
#include "IteratorPattern.h"
#include "CompositePattern.h"
#include "StatePattern.h"
#include "BridgePattern.h"
#include "BuilderPattern.h"
#include "ChainOfResposibilityPattern.h"
#include "FlyweightPattern.h"
#include "InterpreterPattern.h"
#include "MediatorPattern.h"
#include "MenentoPattern.h"
#include "Prototypepattern.h"
#include "Visitorpattern.h"

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

	//测试适配器模式
	TestAdapterPattern();

	//测试模版方法模式
	TestTemplateMethodPattern();

	//测试迭代器模式
	TestIteratorPattern();

	//测试组合模式
	TestCompositePattern();

	//测试状态模式
	TestStatePattern();

	//测试桥接模式
	TestBirdePattern();

	//测试生成器模式
	TestBuilderPattern();

	//测试责任链模式
	TestChainOfResponsibilityPattern();

	//测试蝇量模式
	TestFlyweightPattern();

	//测试解释器模式
	TestInterpreterPattern();

	//测试中介者模式
	TestMediatorPattern();

	//测试备忘录模式
	TestMementPatternPattern();

	//测试原型模式
	TestProtoPatternPattern();
	
	//访问者模式
	TestVisitorPattern();


	system("pause");
}