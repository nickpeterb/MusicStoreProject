
#include "physical.hpp"

Physical::Physical(){
	this->inStock = 0;
}

Physical::Physical(int inStock){
	this->inStock = inStock;
}

int Physical::getInStock(){
	return this->inStock;
}
