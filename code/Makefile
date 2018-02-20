CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD -O2
EXEC = main.out
OBJECTS = main.o node.o subsequence_finder.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} ${CXXFLAGS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
