#pragma once
#include "IPresenter.h"
#include "../views/ParticularView.h"
#include "../repositories/ParticularRepository.h"
#include "../models/Particular.h"

class ParticularPresenter : public IPresenter<ParticularView>{
private:
	ParticularRepository* _repo;
	Particular _currentParticular;

public:
	ParticularPresenter(ParticularView* view);
	void Initialize();
	void LoadList();
	void Callback();
	void OptionMenuLoop();
	void setRepository(ParticularRepository* particular_repo);
};