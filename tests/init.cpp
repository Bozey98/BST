#include <matrix.hpp>
#include <catch.hpp>

SCENARIO("matrix init without parametrs", "[init wp]") {
	Matrix matrix;
	REQUIRE(matrix.rows() == 4);
	REQUIRE(matrix.columns() == 4);
	
	for (int i=0;i<matrix.rows(); i++) {
		for (int j = 0; j<matrix.columns();j++) {
			REQUIRE(matrix.Element(i,j) == 0);
		}
	}
}

SCENARIO("matrix init with parametrs", "[init withp]") {
	Matrix matrix(6,6);
	REQUIRE(matrix.rows() == 6);
	REQUIRE(matrix.columns() == 6);
	
	for (int i=0;i<matrix.rows(); i++) {
		for (int j = 0; j<matrix.columns();j++) {
			REQUIRE(matrix.Element(i,j) == 0);
		}
	}
}

SCENARIO("matrix init copy", "[init copy]") {
	Matrix matrix(6,6);
	Matrix matrix1(matrix);
	REQUIRE(matrix1.rows() == matrix.rows());
	REQUIRE(matrix1.columns() == matrix.columns());
	
	for (int i=0;i<matrix.rows(); i++) {
		for (int j = 0; j<matrix.columns();j++) {
			REQUIRE(matrix.Element(i,j) == matrix1.Element(i,j));
		}
	}
}

SCENARIO("matrix fill", "[fill]") {
	Matrix matrix(2,2);
	ofstream test1("test1.txt");
	test1 << "1 2 3 4";
	test1.close();
	matrix.fill("test1.txt");
	REQUIRE(matrix.Element(0,0) == 1);
	REQUIRE(matrix.Element(0,1) == 2);
	REQUIRE(matrix.Element(1,0) == 3);
	REQUIRE(matrix.Element(1,1) == 4);
}

SCENARIO("matrix sum", "[sum]") {
	Matrix matrix(2,2);
	Matrix matrix1(2,2);
	Matrix sum(2,2);
	
	ofstream test1("test1.txt");
	test1 << "1 2 3 4";
	test1.close();
	
	matrix.fill("test1.txt");
	matrix1.fill("test1.txt");
	ofstream sumfile("sumfile.txt");
	sumfile << "2 4 6 8";
	sum.fill("sumfile.txt");
	sumfile.close();
	for (int i=0;i<matrix.rows(); i++) {
		for (int j = 0; j<matrix.columns();j++) {
			REQUIRE(sum.Element(i,j) == matrix.Element(i,j) + matrix1.Element(i,j));
		}
	}
}
	
	
	



