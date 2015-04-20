#pragma once
#define LIST	1
#define ADD		2
#define EDIT	3
#define REMOVE	4

template <class View>
class IPresenter
{
protected:
	View* _view;

	IPresenter(View* view){
		_view = view;
	}

	void Initialize();
};