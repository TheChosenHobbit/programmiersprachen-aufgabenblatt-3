#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <vector>

bool is_odd(int i)
{
	return (i % 2) != 0;
}

bool is_even(int i)
{
	return (i % 2) == 0;
}


TEST_CASE ("describe_factorial","[aufgabe3]"){
    std::vector<unsigned int> v(100);

	for(std::vector<unsigned int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		*it = std::rand() % 100 + 1;
	}

	v.erase(std::remove_if(v.begin(), v.end(), is_odd), v.end() );
	//remove_if "sortiert" Liste nach Kriterium und gibt dann zb 1324 zurück
	//erase löscht dann die ungeraden der Liste


    REQUIRE(std::all_of(v.begin(), v.end(), is_even));
}

/*Aufgabe 6
Sequentieller Container: Vector, List,  jedem Element wird ein bestimmter Wert / Position zugefügt (einfache Sortierungen Möglich),
gleicher Typ
Deque: Ein Deque-Container ist ein dynamisches Array, das so implementiert ist, dass es in beide Richtungen wachsen kann 
Insofern geht das Einfügen und Löschen von Elementen nicht nur am Ende, sondern auch am Anfang optimal schnell.
Aber auch hier brauchen Änderungen in der Mitte entsprechend Zeit zum Verschieben. 

Assoziativer Container: Map, jedes Element bekommt einen einzigartigen Schlüssel mit beliebigem Datentyp, abfrage hier nicht
nach Reihenfolge sondern nach Abgleich der Schlüssel. (erschwerte bzw längere suche, da schlüssel nicht "wirklich" sortiert)

1. Speichern der Punkte eines Polygons
sequentiell: selber datentyp und einfach durchnummeriert, zugriff auf punkte über stelle im vector (xter punkt) vector

2.  Zuordnung von Farbnamen und ensprechenden RGB-Werten
assoziativ: Farbname oder RGB-Werte als Schlüssel zum "wiederfinden", map --> key, value

3. Warteschlange
sequentiell: deque, entfernen und löschen vorne und hinten möglich
*/

//Aufgabe 11
template <typename T, typename Z> T filter(T const& a, Z const& b)
{
	T ausgabe{0};
	std::transform(a.begin(), a.end(),
					ausgabe.begin(),
					b);
	return ausgabe;
}

TEST_CASE("filter template","[template test]"){
	std::vector<int> v{1,2,3,4,5,6};
	std::vector<int> alleven = filter(v, is_even);

	REQUIRE(std::all_of(alleven.begin(), alleven.end(), is_even));
}

/* Aufgabe 3.12
Bei einer Map darf ein Key nicht doppelt vorkommen.
Suche wäre find map[name]; und dann würde die Matrikelnummer ausgegeben werden
emplace oder try_emplace

Mit einer Multimap oder mit einem gepairten String sollte es gehen 

find ist const
*/


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}