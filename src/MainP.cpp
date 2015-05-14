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
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
#include <ctime>

using namespace std;


void testDijkstraGraph(int src, int dst)
{
	Graph* my_graph_pt = new Graph("/home/gr-dev/k-shortest-paths-cpp-version/data/test_50");
	DijkstraShortestPathAlg shortest_path_alg(my_graph_pt);
	BasePath* result =
		shortest_path_alg.get_shortest_path(
			my_graph_pt->get_vertex(src), my_graph_pt->get_vertex(dst));
	result->PrintOut(cout);
}

void testYenAlg(int src, int dst, int kpath)
{
	Graph my_graph("/home/gr-dev/k-shortest-paths-cpp-version/data/test_500");
	YenTopKShortestPathsAlg yenAlg(my_graph, my_graph.get_vertex(src),
		my_graph.get_vertex(dst));

	int i=1;
	if(kpath>0)
	{
		vector<BasePath*> result_list;
		clock_t begin = clock();
		cout << "\nCalculating K shortest path Start time ->  "<< (double)begin/CLOCKS_PER_SEC;
		yenAlg.get_shortest_paths(my_graph.get_vertex(src),my_graph.get_vertex(dst),kpath,result_list);
		clock_t end = clock();
		cout << "\nCalculating K shortest path End time ->  "<< (double)end/CLOCKS_PER_SEC;
		cout <<"\n";
		for(vector<BasePath*>::const_iterator pos=result_list.begin();
				pos!=result_list.end(); ++pos)
		{
			cout <<"Path no " << i << endl;
			(*pos)->PrintOut(cout);
			i++;
		}
		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout << "\nIt took Yan's k path " << elapsed_secs << "(seconds)" <<endl;

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
