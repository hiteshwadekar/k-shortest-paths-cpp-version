CXXFLAGS =	-O0 -g -Wall -fmessage-length=0 -fprofile-arcs -ftest-coverage
LFLAGS= -lgcov -coverage

AM_CXXFLAGS = --coverage 
AM_LDFLAGS = --coverage 
AM_CFLAGS = -shared

OBJS =	MainP.o YenTopKShortestPathsAlg.o Graph.o DijkstraShortestPathAlg.o

TARGET = kpath

$(TARGET):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)
DijkstraShortestPathAlg.o:
	$(CXX) $(CXXFLAGS) -c src/DijkstraShortestPathAlg.cpp -o DijkstraShortestPathAlg.o
Graph.o:
	$(CXX) $(CXXFLAGS) -c src/Graph.cpp -o Graph.o
YenTopKShortestPathsAlg.o:
	$(CXX) $(CXXFLAGS) -c src/YenTopKShortestPathsAlg.cpp -o YenTopKShortestPathsAlg.o
MainP.o:
	$(CXX) $(CXXFLAGS) -c src/MainP.cpp -o MainP.o

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
	rm -f *.gcda *.gcno
