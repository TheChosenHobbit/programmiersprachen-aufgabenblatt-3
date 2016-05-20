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




int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}