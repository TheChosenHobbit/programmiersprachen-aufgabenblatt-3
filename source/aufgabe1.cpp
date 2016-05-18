#include <cstdlib> //std::rand()
#include <vector> //std::vector <>
#include <list> //std::list <>
#include <iostream> //std::cout
#include <iterator> //std::ostream_iterator <>
#include <algorithm> //std::reverse, std::generate

int main ()
{
	std::vector<int>v0(10);

	for (std::vector<int>::iterator it = v0.begin(); it != v0.end(); ++ it ) 
	{
		* it = std::rand(); 
	}
// oder
// for ( auto & v : v0 ) {
// v = std :: rand ();
// }

	std::copy(std::begin(v0), std::end(v0),
		std::ostream_iterator<int>(std::cout, " einfach \n" )); //kopiert und gibt alle 10 Arrays von int Werten aus

	std::list<int> l0(v0.size()); //erstellt eine doppelt verkettete Liste der Größe von v0
	std::copy(std::begin(v0), std::end(v0), std::begin(l0)); //kopiert die Elemente der Arrays in die Liste

	std::list<int> l1 (std::begin(l0), std::end(l0)); //erstellt eine zweite doppelt verkettete Liste von der Liste l1
	std::reverse(std::begin(l1), std::end(l1)); //vertauscht die Reihenfolge der Arrays
	std::copy(std::begin(l1), std::end(l1),
		std::ostream_iterator<int>(std::cout, " umgekehrt \n")); //kopiert und gibt alle Elemente der Liste l1 aus

	l1.sort(); //sortiert die Array Listen l1 aufsteigend ( < )
	std::copy(l1.begin() ,l1.end(),
		std::ostream_iterator<int>(std::cout, " soriert \n")); //kopiert und gibt alle sortierten Elemente der Liste l1 aus

	std::generate(std::begin(v0), std::end(v0), std::rand); //gibt jedem Element von v0 einen Zufallswert
	std::copy(v0.rbegin(), v0.rend(),
		std::ostream_iterator<int>(std::cout, " reversed random \n")); //kopiert und gibt alle Elemente von v0 reversed aus (rbeginn)

	return 0;
}