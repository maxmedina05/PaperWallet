#pragma once
#include "IPresenter.h"
#include "RepositoryFactory.h"
#include "SettingView.h"

class HomePresenter : public IPresenter{
private:
	HomePresenter* _aview;
	RepositoryFactory *_factory;
public:
	HomePresenter();
	~HomePresenter();
};

