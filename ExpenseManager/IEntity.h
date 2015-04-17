#pragma once
#include <iostream>
#include <string>

using namespace std;

class IEntity
{
protected:
	int _Id;

	string _createdAt;
	string _updatedAt;

public:
	virtual void setId(int Id){
		_Id = Id;
	}

	virtual int getId()
	{
		return _Id;
	}
	virtual void setCreatedAt(string date)
	{
		_createdAt = date;
	}
	virtual string getCreatedAT()
	{
		return _createdAt;
	}
	virtual void setUpdatedAt(string date)
	{
		_updatedAt = date;
	}
	virtual string getUpdateAT()
	{
		return _updatedAt;
	}

};