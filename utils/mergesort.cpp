#include "mergesort.hpp"
using namespace std;

//Implementation of mergeSort
void MergeSort::merge(vector<Product*>& products, int l, int middle, int r, sortBy sortby) {
	int i, j, k;

	int nL = middle - l + 1;  //number of elements in the left vector
	int nR = r - middle; //number of elements in the right vector

	vector<Product*> left;  //declaration of the left subvector of products
	vector<Product*> right; //declaration of the right subvector of products

	//loops to copy values in the 2 temporary vectors, left and right
	for (int i = 0; i < nL; i++)
		left.push_back(products[l + i]);
	for (int j = 0; j < nR; j++)
		right.push_back(products[middle + 1 + j]);

	//merging the two vectors in the initial vector
	i = 0; //initial index of the first subvector
	j = 0; //initial index of the second subvector
	k = l; //initial index of the merged subvector
	
	while (i < left.size() && j < right.size()) {
		
		if ((sortby == Price) ? left[i]->getPrice() <= right[j]->getPrice() : left[i]->getYear() <= right[j]->getYear()) {
			products[k] = left[i];
			i++;
		}
		else {
			products[k] = right[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of vector<Product*> left , if there are any
	while (i < left.size())
	{
		products[k] = left[i];
		i++;
		k++;
	}

	// Copy the remaining elements of vector<Product*> right , if there are any
	while (j < right.size())
	{
		products[k] = right[j];
		j++;
		k++;
	}
}
void MergeSort::sort(vector<Product*> &products, int left, int right, sortBy sortby)
{
	if (left < right) {
		int center = (left + right) / 2;
		//Sort the first and second halves
		sort(products, left, center, sortby);     //mergeSort function calling itself
		sort(products, center + 1, right, sortby);

		//merge the two halves together
		merge(products, left, center, right, sortby);
	}
}
