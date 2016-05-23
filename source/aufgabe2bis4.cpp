#include <cstdlib> //std::rand()
#include <vector> //std::vector <>
#include <list> //std::list <>
#include <iostream> //std::cout
#include <iterator> //std::ostream_iterator <>
#include <algorithm> //std::reverse, std::generate
#include <set>
#include <map>

int main()
{
	std::list<unsigned int> liste1(100);

	for(std::list<unsigned int>::iterator it = liste1.begin(); it != liste1.end(); ++it)
	{
		*it = std::rand() % 100 + 1;
	}

	/*Ausgabe Liste
	std::copy(std::begin(liste1), std::end(liste1),
		std::ostream_iterator<int>(std::cout, "\n" ));
	*/

	std::vector<int> vector1(liste1.size());
	std::copy(std::begin(liste1), std::end(liste1), std::begin(vector1));

	/*Ausgabe Vector
	std::copy(std::begin(vector1), std::end(vector1),
		std::ostream_iterator<int>(std::cout, "\n" ));
	*/


	std::set<unsigned int> listeSet(std::begin(liste1), std::end(liste1));
	std::cout<< "Diese Liste mit Zufallszahlen enthaelt " << listeSet.size() <<" verschiedene Elemente"<<std::endl;


	std::cout<< "Folgende Zahlen zwischen 0 und 100 sind nicht in der Liste enthalten: "<<std::endl;
	
	for (int i = 0; i <= 100; ++i) 
	{
    	if (listeSet.count(i) == 0) {
      		std::cout << i << "\n";
    	}
    }


    std::map<unsigned int, unsigned int> map1;
    for (int i = 0; i<=100; ++i){
    	map1[i]=std::count(liste1.begin(), liste1.end(), i);
	}

    //for (auto i : liste1) {
    //	++map1[i];
    //}
    
	std::cout << "Zahl: Haeufigkeit" << std::endl;
	for (int i = 0; i<=100; ++i){
		if (map1[i]>0){
    	 	std::cout << i << ": " << map1[i] << std::endl;
    	} 	
    }


	return 0;
}