CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -Wextra -Wpedantic -MMD -g \
-O2 -fsanitize=undefined,address

EXEC = main.out
SOURCES = $(shell find -name "*.cpp")
OBJECTS = $(SOURCES:.cpp=.o)
DEPENDS = ${SOURCES:.cpp=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} ${CXXFLAGS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
