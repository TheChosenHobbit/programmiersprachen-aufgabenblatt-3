#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <vector>
#include "circle.hpp"
#include <set>
#include <list>


TEST_CASE ("describe_factorial","[aufgabe3]"){
    std::set<Circle> setCircle;

	for(int i=0; i<10; ++i)
	{
		float r = std::rand() % 100 +1;
		Circle c{{1,1},{r},{0,0,0}};
		setCircle.insert(c);
	}

    REQUIRE(std::is_sorted(setCircle.begin(), setCircle.end()));
}


//Aufgabe 8
template <typename T> void swap (T& a, T& b)
{
	T c{a};
	a=b;
	b=c;
}

TEST_CASE ("swap two objects","[swap]"){
	Circle c1{{0.5,0.5},{0.5},{0,0,0}};
	Circle c2{{1,1},{1},{1,1,1}};

	swap(c1,c2);

	REQUIRE(c1.getPoint2D().x == Approx(1.0f));
	REQUIRE(c1.getPoint2D().y == Approx(1.0f));
	REQUIRE(c1.getColor().r == Approx(1.0f));
	REQUIRE(c1.getColor().g == Approx(1.0f));
	REQUIRE(c1.getColor().b == Approx(1.0f));
	REQUIRE(c1.getRadius() == Approx(1.0f));

	REQUIRE(c2.getPoint2D().x == Approx(0.5f));
	REQUIRE(c2.getPoint2D().y == Approx(0.5f));
	REQUIRE(c2.getColor().r == Approx(0.0f));
	REQUIRE(c2.getColor().g == Approx(0.0f));
	REQUIRE(c2.getColor().b == Approx(0.0f));
	REQUIRE(c2.getRadius() == Approx(0.5f));

	int a = 5;
	int b = 42;
	swap(a,b);
	REQUIRE(a == 42);
	REQUIRE(b == 5);

	float c = 5;
	float d = 42;
	swap(c,d);
	REQUIRE(c == Approx(42.0f));
	REQUIRE(d == Approx(5.0f));
}

//Aufgabe 9
TEST_CASE("sort_list_lambda","[sort lambda]"){
	std::list<Circle> listCircle(5);

	
	for(int i=0; i<5; ++i)
	{
		float r = std::rand() % 100 +1;
		Circle c{{1,1},{r},{0,0,0}};
		listCircle.push_back(c);
	}

	listCircle.sort([](Circle const& a, Circle const& b)
	{
		return a.getRadius()<b.getRadius();
	});

	REQUIRE(std::is_sorted(listCircle.begin(), listCircle.end()));
}

//Aufgabe 10
TEST_CASE("Add Container Lambda","[Lambda add]"){
	std::vector<int> v1{1,2,3,4,5,6,7,8,9};
	std::vector<int> v2{9,8,7,6,5,4,3,2,1};
	std::vector<int> v3(9);

	std::transform(v1.begin(), v1.end(),
					v2.begin(), v3.begin(),
					[](int a, int b){
						return a+b;
					});

	REQUIRE(std::all_of(v3.begin(), v3.end(), [](int a){
		return a==10;
	}));
}


int main(int argc, char *argv[])
{
	return Catch::Session().run(argc, argv);
}