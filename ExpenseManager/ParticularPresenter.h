#pragma once
#include "IView.h"
#include "IPresenter.h"
#include "ParticularRepository.h"
#include "ParticularView.h"

class ParticularPresenter : public IPresenter{
private:
	ParticularView *_aview;
	ParticularRepository* _repo;
	Particular _currentParticular;

public:
	ParticularPresenter(IView* view);
	void Initialize();
	void LoadList();
	void Callback();
	void OptionMenuLoop();
	void setRepository(ParticularRepository* particular_repo);
};