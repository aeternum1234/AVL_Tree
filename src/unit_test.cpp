#include "gtest/gtest.h"

#ifndef node_h
	#define node_h
	#include "node.h"
#endif

#ifndef avl_h
	#define avl_h
	#include "avl.h"
#endif

// node test fixure
class nodeTest : public testing::Test {
	protected:
		// virtual void SetUp()
		// virtual void TearDown()
		node< int > *node_1                    = new node< int >( 10 );
		node< int > *node_int_children_1       = new node< int >( 90 );
		node< int > *node_int_children_2       = new node< int >( 30 );
		node< int > *node_int_unbalance        = new node< int >( 50 );

		node< double > *node_2                 = new node< double >( 20.7 );
		node< double > *node_double_children_1 = new node< double >( 66.6 );
		node< double > *node_double_children_2 = new node< double >( 49.39 );
		node< double > *node_double_unbalance  = new node< double >( 100.4 );
};

TEST_F( nodeTest , constructor ) {
	EXPECT_EQ( node_1->getData() , 10 );
	EXPECT_EQ( node_1->getHeight() , 1 );
	EXPECT_EQ( node_2->getData() , 20.7 );
	EXPECT_LT( node_2->getHeight() , 2 );
}

TEST_F( nodeTest , setter ) {
	EXPECT_EQ( node_1->getLeftChild() , nullptr );
	node_1->setLeftChild( node_int_children_1 );
	EXPECT_EQ( node_1->getLeftChild()->getData() , 90 );

	EXPECT_EQ( node_1->getRightChild() , nullptr );
	node_1->setRightChild( node_int_children_2 );
	EXPECT_GT( node_1->getRightChild()->getData() , 26 );

	EXPECT_TRUE( node_2->getLeftChild() == nullptr );
	node_2->setLeftChild( node_double_children_2 );
	EXPECT_EQ( node_2->getLeftChild()->getHeight() , 1 );

	EXPECT_EQ( node_2->getRightChild() , nullptr );
	node_2->setRightChild( node_double_children_1 );
	EXPECT_LT( node_2->getRightChild()->getData() , 66.7 );
}

TEST_F( nodeTest , isLeaf ) {
	EXPECT_TRUE( node_1->isLeaf() );
	EXPECT_TRUE( node_2->isLeaf() );

	node_1->setLeftChild( node_int_children_1 );
	node_1->setRightChild( node_int_children_2 );
	node_2->setLeftChild( node_double_children_2 );

	EXPECT_FALSE( node_1->isLeaf() );
	EXPECT_TRUE( node_2->getLeftChild()->isLeaf() );
	EXPECT_FALSE( node_2->isLeaf() );
}

TEST_F( nodeTest , getMaxHeight ) {
	EXPECT_EQ( node_1->getMaxHeight() , 1 );
	EXPECT_EQ( node_2->getMaxHeight() , 1 );

	node_1->setLeftChild( node_int_children_1 );
	node_1->setRightChild( node_int_children_2 );
	node_2->setLeftChild( node_double_children_2 );

	EXPECT_EQ( node_1->getMaxHeight() , 2 );
	EXPECT_EQ( node_2->getMaxHeight() , 2 );

	node_2->setLeftChild( nullptr );
	EXPECT_EQ( node_2->getMaxHeight() , 1 );
}

// avl test fixure
class avlTest : public testing::Test {
	protected:
		// virtual void SetUp()
		// virtual void TearDown()
		AVLTree< int > avl_tree_int;
		AVLTree< double > avl_tree_double;
};

/*  to use FRIEND_TEST , make sure that
 *  test case name( first parameter ) and test name( second parameter ) of the TEST_F and FRIEND_TEST are equal
 */
TEST_F( avlTest , privateContent ) {
	// constructor
	EXPECT_EQ( avl_tree_int.root , nullptr );
	EXPECT_EQ( avl_tree_double.root , nullptr );

	// insert
	avl_tree_int.insertHelper( 66 );
	avl_tree_double.insertHelper( 66.6 );

	EXPECT_EQ( avl_tree_int.root->getData() , 66 );
	EXPECT_EQ( avl_tree_double.root->getData() , 66.6 );
}

GTEST_API_ int main( int argc , char **argv ) {
	testing::InitGoogleTest( &argc , argv );
	return RUN_ALL_TESTS();
}
