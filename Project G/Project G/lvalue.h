#ifndef __LVALUE_H
#define __LVALUE_H

#include "base.h"
#include <string>
class LocationValueVariable : public LocationValue{
	std::string name;
public:
	LocationValueVariable(const std::string &name) : LocationValue(){
		this->name = name;
	}
	virtual ~LocationValueVariable() {

	}
	virtual void Set(int value) override{
	
	} //method for setting the value
	virtual int Evaluate() override {
		return 0;
	}// method for getting the value
}; 
#endif