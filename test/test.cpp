#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "include/block_matrix.hpp"

TEST_CASE("Setting up two block", "[Setting up two block]")
{
	bmx::block_matrix<int> block;
	block.set_block_one(3, 1);
	block.set_block_two(3, 2);
	REQUIRE(block.get_block_one_values(0, 0) == 1);
	REQUIRE(block.get_block_one_values(1, 1) == 1);
	REQUIRE(block.get_block_two_values(0, 1) == 2);
	REQUIRE(block.get_block_two_values(1, 2) == 2);
}

TEST_CASE("Testing sum", "[Testing sum]")
{
	bmx::block_matrix<int> block1;
	bmx::block_matrix<int> block2;
	block1.set_block_one(3, 1);
	block1.set_block_two(3, 2);
	block2.set_block_one(3, 1);
	block2.set_block_two(3, 1);
	block1.sum(block2);
	REQUIRE(block1.get_block_one_values(0, 0) == 2);
	REQUIRE(block1.get_block_one_values(1, 1) == 2);
	REQUIRE(block1.get_block_two_values(0, 1) == 3);
	REQUIRE(block1.get_block_two_values(1, 2) == 3);
}

TEST_CASE("Testing sum for big matrix", "[Testing sum for big matrix]")
{
	bmx::block_matrix<int> block1;
	bmx::block_matrix<int> block2;
	block1.set_block_one(1000, 1);
	block1.set_block_two(1000, 2);
	block2.set_block_one(1000, 1);
	block2.set_block_two(1000, 1);
	block1.sum(block2);
	REQUIRE(block1.get_block_one_values(0, 0) == 2);
	REQUIRE(block1.get_block_one_values(1, 1) == 2);
	REQUIRE(block1.get_block_two_values(0, 1) == 3);
	REQUIRE(block1.get_block_two_values(1, 2) == 3);
}

TEST_CASE("Testing sum for big matrix and value", "[Testing sum for big matrix and value]")
{
	bmx::block_matrix<int> block1;
	bmx::block_matrix<int> block2;
	block1.set_block_one(1000, 1000);
	block1.set_block_two(1000, 2000);
	block2.set_block_one(1000, 1000);
	block2.set_block_two(1000, 1000);
	block1.sum(block2);
	REQUIRE(block1.get_block_one_values(0, 0) == 2000);
	REQUIRE(block1.get_block_one_values(1, 1) == 2000);
	REQUIRE(block1.get_block_two_values(0, 1) == 3000);
	REQUIRE(block1.get_block_two_values(1, 2) == 3000);
}
