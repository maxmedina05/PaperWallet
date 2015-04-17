#pragma once
#include "IView.h"

class IPresenter
{
protected:
	IView* _View;
	/*IPresenter();*/

	IPresenter(IView* view){
		_View = view;
	}

	void Initialize();

public:
	virtual void Callback() = 0;

};