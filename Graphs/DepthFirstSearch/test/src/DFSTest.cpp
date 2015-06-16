/*
*
* A C++ test implmentation of Depth first search on a directed graph.
*
* Created by: Asad zia.
*/

#include "DFSTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DFSTest);

void DFSTest::setUp()
{
	this->myGraph = new Graph(4);
}

void DFSTest::teardown()
{
	delete myGraph;
}

void DFSTest::testGraph ()
{
	CPPUNIT_ASSERT(myGraph->Vertices == 4);
}

void DFSTest::testAddEdge ()
{
	myGraph->addEdge(0, 1);
	myGraph->addEdge(0, 2);
	myGraph->addEdge(1, 2);
	myGraph->addEdge(2, 0);
	myGraph->addEdge(2, 3);
	myGraph->addEdge(3, 3);

	CPPUNIT_ASSERT(true);
	list<int>::iterator it;
	it = myGraph->adj[0].begin();
	CPPUNIT_ASSERT(*it == 1);
	it = myGraph->adj[1].begin();
	CPPUNIT_ASSERT(*it == 2);
}
