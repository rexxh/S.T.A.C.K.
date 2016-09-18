#include <Stack.hpp>
#include <catch.hpp>


SCENARIO("Stack init ", "[init]") {
	stack<int> s();
	REQUIRE(s.count() == 0);
	REQUIRE(s.arraysize() == INIT_SIZE);		
}

SCENARIO("Copy constr", "[copy]") {
	stack<int> s1();
	for (unsigned int i = 0; i < 15, i++)
	{
		s1.push(i);
	}
	stack<int> s2(s1);
	REQUIRE(s1 == s2);
}

SCENARIO("Count", "[count]") {
	stack<int> s1();
	REQUIRE(s1.count() == 0);
}

SCENARIO("Array size", "[array_size]") {
	stack<int> s1();
	REQUIRE(s1.array_size() == INIT_SIZE);
}
	

SCENARIO("Push", "[push]") {
	stack<int> s1();
	for (unsigned int i = 0; i < 10; i++)
	{
		s1.push(i);
	}
	REQUIRE(s1.count() == 10);
}

SCENARIO("Pop", "[pop]") {
	stack<string> s1();
	s1.push(105.2);
	s1.push("Hello");
	REQUIRE(s1.pop() == "Hello");
	REQUIRE(s1.pop() == 105.2);
}

SCENARIO("assignment", "[assignment]") {
	stack<int> s1();
	for (unsigned int i = 0; i < 4; i++)
	{
		s1.push(i);
	}
	stack<int> s1();
	s1 = s2;
	REQUIRE(s1 == s2);
}

