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

	//����������ģʽ
	TestAdapterPattern();

	//����ģ�淽��ģʽ
	TestTemplateMethodPattern();

	//���Ե�����ģʽ
	TestIteratorPattern();

	//�������ģʽ
	TestCompositePattern();

	//����״̬ģʽ
	TestStatePattern();

	//�����Ž�ģʽ
	TestBirdePattern();

	//����������ģʽ
	TestBuilderPattern();

	//����������ģʽ
	TestChainOfResponsibilityPattern();

	//����Ӭ��ģʽ
	TestFlyweightPattern();

	//���Խ�����ģʽ
	TestInterpreterPattern();

	//�����н���ģʽ
	TestMediatorPattern();

	//���Ա���¼ģʽ
	TestMementPatternPattern();

	//����ԭ��ģʽ
	TestProtoPatternPattern();
	
	//������ģʽ
	TestVisitorPattern();


	system("pause");
}