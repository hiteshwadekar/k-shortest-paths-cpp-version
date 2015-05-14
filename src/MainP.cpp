/************************************************************************/
/* $Id: MainP.cpp 65 2010-09-08 06:48:36Z yan.qi.asu $                                                                 */
/************************************************************************/

#include <limits>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "GraphElements.h"
#include "Graph.h"
#include "DijkstraShortestPathAlg.h"
#include "YenTopKShortestPathsAlg.h"

using namespace std;


void testDijkstraGraph(int src, int dst)
{
	Graph* my_graph_pt = new Graph("/home/hitesh-dev/k-shortest-paths-cpp-version/data/test_50");
	DijkstraShortestPathAlg shortest_path_alg(my_graph_pt);
	BasePath* result =
		shortest_path_alg.get_shortest_path(
			my_graph_pt->get_vertex(src), my_graph_pt->get_vertex(dst));
	result->PrintOut(cout);
}

void testYenAlg(int src, int dst, int kpath)
{
	Graph my_graph("/home/hitesh-dev/k-shortest-paths-cpp-version/data/test_50");

	YenTopKShortestPathsAlg yenAlg(my_graph, my_graph.get_vertex(src),
		my_graph.get_vertex(dst));

	int i=0;
	if(kpath>0)
	{
		vector<BasePath*> result_list;
		yenAlg.get_shortest_paths(my_graph.get_vertex(src),my_graph.get_vertex(dst),kpath,result_list);
		for(vector<BasePath*>::const_iterator pos=result_list.begin();
				pos!=result_list.end(); ++pos)
		{
			cout <<"Path no " << i << endl;
			(*pos)->PrintOut(cout);
			i++;
		}
	}
	else
	{
		while(yenAlg.has_next())
		{
			++i;
			yenAlg.next()->PrintOut(cout);
		}
	}
}

int main(int argc, char *argv[] )
{
	if (argc >= 3)
	{
		cout << "Welcome to the real world!" << endl;
		int source = atoi(argv[1]);
		int destination = atoi(argv[2]);
		int kpath =0;
		if(argc>=4)
		{
			kpath=atoi(argv[3]);
		}
		//testDijkstraGraph();
		testYenAlg(source, destination,kpath);
		//testDijkstraGraph(source,destination);
	}
	else
	{
		cout << "\n Please provide source, destination node and number pathr " << endl;
	}

}
