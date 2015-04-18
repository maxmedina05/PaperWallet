#pragma once
#include "IView.h"
#include <vector>
#include "Particular.h"

class ParticularView : public IView
{
public:
	ParticularView();
	~ParticularView();

	void OnViewCreated() override;
	void OnViewDestroyed() override;
	void showTitle() override;
	void showMenu();
	static void listView(vector<Particular> particulars, ParticularType type);
	Particular editView(Particular particular);

	void showSuccessfulMessage();
};