#include <BST.hpp> 
#include <catch.hpp>
#include <fstream>


SCENARIO ("init", "[init]")

{

  BST<int> test;

  REQUIRE(test.getroot() == nullptr);
  REQUIRE(test.getcount() == 0);

}

SCENARIO("insert", "[init]")

{

  BST<int> test;

  test.add(10);

  REQUIRE(test.search(10, test.getroot()) != 0);

}

SCENARIO("find_node", "[init]")

{

  BST<int> test;

  test.add(10);

  REQUIRE(test.search(10, test.getroot()) != 0);

  REQUIRE(test.search(10, test.getroot()) != 0);

}

SCENARIO("get root", "[init]")

{

  BST<int> test;

  test.add(10);
	
  REQUIRE(test.getcount() == 1);

  REQUIRE(test.getroot() != 0);

}


SCENARIO ("test1", "[init]")
{
	BST<int> test;
	test.input("File1.txt");
	REQUIRE(test.getcount() == 3);
	
}



SCENARIO("del", "[init]")

{

  BST<int> test;

  test.add(1);

  test.add(2);

  test.add(3);

  test.del(test.getroot(), 1);

  test.del(test.getroot(), 2);

  REQUIRE(test.search(1, test.getroot()) != 0);
  REQUIRE(test.search(2, test.getroot()) == 0);

  REQUIRE(test.search(3, test.getroot())!= 0);

}
	



