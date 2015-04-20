#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

template <class Entity>
class IRepository
{
public:
	virtual bool add(Entity entity) = 0;
	virtual bool update(Entity entity) = 0;
	virtual Entity getById(int Id) = 0;
	virtual bool remove(Entity entity) = 0;
	virtual vector<Entity> getAll() = 0;
};