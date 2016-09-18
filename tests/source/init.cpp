#include <Stack.hpp>
#include <catch.hpp>


SCENARIO("Stack init ", "[init]") {
	stack<int> s;
	REQUIRE(s.count() == 0);
	REQUIRE(s.array_size() == INIT_SIZE);		
}

SCENARIO("Copy constr", "[copy]") {
	stack<int> s1;
	for (unsigned int i = 0; i < 15; i++)
	{
		s1.push(i);
	}
	stack<int> s2(s1);
	REQUIRE(s1 == s2);
}

SCENARIO("Count", "[count]") {
	stack<int> s1;
	REQUIRE(s1.count() == 0);
}

SCENARIO("Array size", "[array_size]") {
	stack<int> s1;
	REQUIRE(s1.array_size() == INIT_SIZE);
}
	

SCENARIO("Push", "[push]") {
	stack<int> s1;
	for (unsigned int i = 0; i < 10; i++)
	{
		s1.push(i);
	}
	REQUIRE(s1.count() == 10);
}

SCENARIO("assignment", "[assignment]") {
	stack<int> s1;
	for (unsigned int i = 0; i < 4; i++)
	{
		s1.push(i);
	}
	stack<int> s2;
	s2 = s1;
	REQUIRE(s1 == s2);
}

SCENARIO("fPop", "[fpop]") {
	stack<int> s1;
	s1.push(10);
	REQUIRE(s1.pop() == 10);
}
