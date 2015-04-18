#pragma once
#include "IRepository.h"
#include "Particular.h"
#include <vector>

class ParticularRepository : public IRepository<Particular>{
private:
	vector<Particular> _particulars;

public:
	ParticularRepository();
	~ParticularRepository();

	virtual bool add(Particular entity) override;
	virtual bool update(Particular entity) override;
	virtual Particular getById(int Id) override;
	virtual bool remove(Particular entity) override;
	virtual vector<Particular> getAll() override;

	void mockfill();
};

