/*
*
* A C++ test implmentation of Depth first search on a directed graph.
*
* Created by: Asad zia.
*/

#include "DFS.h"
#include <cppunit/extensions/HelperMacros.h>

class DFSTest : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE (DFSTest);
  /* testing the addedge function */
	CPPUNIT_TEST(testAddEdge);
	/* testing the Graph constructor */
	CPPUNIT_TEST(testGraph);
	CPPUNIT_TEST_SUITE_END ();

	private:
	  /* An instance of Graph to be tested */
		Graph *myGraph;
		void testAddEdge ();
		void testGraph ();

	public:
		void setUp();
		void teardown();
};
