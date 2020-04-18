/*
 COS221a
 Nicholas Bruhnev
 Music Store
 Course Project
*/
 
#include <iostream>
#include <vector>
#include <deque>
#include <fstream>
#include <sstream>

//include product header files
#include "product.hpp"
#include "prods/physical.hpp"
#include "prods/digital.hpp"
#include "prods/cd.hpp"
#include "prods/vinyl.hpp"
#include "prods/song.hpp"
#include "prods/album.hpp"

//include utility header files
#include "utils/bmsearch.hpp"
#include "utils/mergesort.hpp"

using namespace std;

//import data from a file
//add it to a vector of a certain type
//also add it to the products vector
template <class T>
void importData(string path, vector<T*> &ts, vector<Product*> &products){
	ifstream file;
	file.open(path);
	
	//create a 2D array from the data
	vector<vector<string>> data;
	vector<string> row;
	string line;
	if(file.is_open()){
		while(getline(file,line))
		{
			stringstream linestream(line);
			string value;

			while(getline(linestream,value,','))
			{
				row.push_back(value);
			}
			data.push_back(row);
			row.clear();
		}
		file.close();
	} else {
		cout << "err: file not opened" << endl;
	}
	
	//create vector of objects
	for(int i = 0; i < data.size(); i++){
		T *newT = new T (
			data[i][0], //id
			data[i][1], //title
			data[i][2], //artist
			atoi(data[i][3].c_str()), //year(int)
			atof(data[i][4].c_str()), //price(double)
			atoi(data[i][5].c_str()) //stock or sales(int)
		);
		//add object to its vector
		ts.push_back(newT);
		//also add each object to products
		products.push_back(newT);
	}
}

//format strings for easier searching
void formatStr(string &txt){
	//convert letters to lowercase
	transform(txt.begin(), txt.end(), txt.begin(), ::tolower);
	//remove spaces
	txt.erase(remove(txt.begin(), txt.end(), ' '), txt.end());
}

//search interface
void searchProducts(vector<Product*> products){
	string pattern;
	cout << "Search Products: ";
	cin >> pattern;
	cout << endl;
	formatStr(pattern);
	
	//store resuls in deque, for easy sorting
	deque<Product*> results;
	
	//instance Boyer Moore Search class
	BmSearch *bms = new BmSearch();
	
	if (!pattern.empty()) {
		int most_matches = 0;
		//search the name of each item, sorting by most matches
		for (int j = 0; j < products.size(); j++) {
			string txt = products[j]->getTitle()+products[j]->getArtist();
			formatStr(txt);
			int matches = bms->search_matches(txt, pattern);
			if (matches > 0) {
				if (matches > most_matches) {
					results.push_front(products[j]);
				}
				else {
					results.push_back(products[j]);
				}
			}
		}
	}
	
	if (!results.empty()) {
		//output results
		for (int i = 0; i < results.size(); i++) {
			cout << results[i]->getArtist() << " - " << results[i]->getTitle() << endl;
		}
	}
	else {
		cout << "Search returned no results" << endl;
	}
}

//check if user wants to exit program or start again
bool exitProgram(){
	string again;
	cout << endl;
	cout << "Start again? (y/n): ";
	cin >> again;
	if(again == "n") return true;
	return false;
}

//utility function to display a vector of products
void displayProds(vector<Product*> products){
	cout << endl;
	for (int i = 0; i < products.size(); i++){
		products[i]->toString();
	}
	cout << endl;
}

int main() {
	//vector to hold all the products
	vector<Product*> products;
	
	//create vectors of each product type
	vector<CD*> cds;
	vector<Vinyl*> vinyls;
	vector<Album*> albums;
	vector<Song*> songs;
	
	//import data from files into their respective vectors and into products vector
	importData<CD>("./data/cds.txt", cds, products);
	importData<Vinyl>("./data/vinyls.txt", vinyls, products);
	importData<Album>("./data/albums.txt", albums, products);
	importData<Song>("./data/songs.txt", songs, products);
	
	//greeting
	cout << "Welcome to the Music Store" << endl;
	
	string input;
	bool exit = false;
	
	//instance Merge Sort class
	MergeSort *ms = new MergeSort();
	
	while(!exit){
		//main menu
		cout << endl;
		cout << "0) Show all products" << endl;
		cout << "1) Search through products" << endl;
		cout << "Enter: ";
		
		cin >> input;
		if(input == "0") {
			cout << endl;
			cout << "p) Sort by price" << endl;
			cout << "y) Sort by year" << endl;
			cout << "Enter: ";
			
			string sort;
			cin >> sort;
			if(sort == "p"){
				//sort products by price
				ms->sort(products, 0, products.size() - 1.0, ms->Price);
				
				displayProds(products);
				
				exit = exitProgram();
			} else if(sort == "y"){
				//sort products by year
				ms->sort(products, 0, products.size() - 1.0, ms->Year);
				
				displayProds(products);
				
				exit = exitProgram();
			} else {
				cout << "invalid input" << endl;
				exit = exitProgram();
			}
			
		} else if(input == "1"){
			//search products
			searchProducts(products);
			
			exit = exitProgram();
		} else {
			cout << "invalid input" << endl;
			exit = exitProgram();
		}
	}
	
	return 0;
}
