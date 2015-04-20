#pragma once
#include "IRepository.h"
#include <vector>
#include "../models/Particular.h"

class ParticularRepository : public IRepository<Particular>{
private:
	vector<Particular> _particulars;
	int getSeed();
public:
	ParticularRepository();
	~ParticularRepository();

	virtual bool add(Particular entity) override;
	virtual bool update(Particular entity) override;
	virtual Particular getById(int Id) override;
	virtual bool remove(Particular entity) override;
	virtual vector<Particular> getAll() override;

	void mockfill();
	void fill(vector<Particular> particulars);
};

