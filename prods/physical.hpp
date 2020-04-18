
#ifndef physical_hpp
#define physical_hpp

#include <stdio.h>
#include "../product.hpp"

class Physical : public Product {
protected:
	int inStock; //total physical items left in stock
public:
	Physical();
	
	Physical(int inStock);
	
	virtual int getInStock();
};

#endif /* physical_hpp */

