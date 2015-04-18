#pragma once
#include "IView.h"

class SettingView : public IView
{
public:
	SettingView();
	~SettingView();
	void showTitle() override;
	void OnViewCreated() override;
	void OnViewDestroyed() override;
	void showMenu();
};
