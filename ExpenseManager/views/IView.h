#pragma once
#include <iostream>
#include <stdio.h>
#include <string>

#define LIST	1
#define ADD		2
#define EDIT	3
#define REMOVE	4

using namespace std;

class IView
{
protected:

public:
	virtual void showTitle() = 0;
	virtual void OnViewCreated() = 0;
	virtual void OnViewDestroyed() = 0;
};