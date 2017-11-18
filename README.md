# subsequence-finder
An algorithm for finding the longest permutation subsequence accepted by a certain kind of finite automaton.

## Possible Subsequence Kinds

A class of sequences of distinct elements can be handled by this program if
there exists a regular language such that
an arbitrary sequence is in our class iff 
the unique string of A's and B's determined by

- the string has length one less than the length of the sequence
- the i-th element of the string is A if the i-th element of the sequence is greater than its successor, or B otherwise

is in the language.
In particular, the only thing that matters about a sequence is whether, for any two consecutive elements, one is greater than the other.

For example, the class of increasing sequences satisfies this propery.
Hence, this algorithm solves the longest increasing subsequence problem.

Furthermore, this algorithm can be used to find the longest "Rollercoaster" subsequence,
where the class of Rollercoaster sequences is another class which satisfies the requirements above.

## Algorithm Information

The algorithm finds a longest subsequence of a permutation that belongs to a certain class.
The time complexity of the algorithm is O(k * n * log n), where n is the size of the permutation, and k is the size of the automaton used to represent the class.

Finding the length of the longest subsequence can be done rather quickly.
The current implementation has some extra overhead because it also stores enough information to reconstruct a subsequence with the longest length.

Although it is not yet implemented, the algorithm could be extended to also count the number of subsequences with the longest length.

## Usage

The main interface to the algorithm is the ```findIndices``` method in the ```SubsequenceFinder``` class.
It expects as a parameter a vector of distinct integers between 1 and n, where n is the size of the vector (the behaviour is undefined if this is not the case). As the name suggests, it returns the indices of the subsequence, stored in a vector.

Although constructing a ```SubsequenceFinder``` in general requires specifying the details of the automaton, the ```RollercoasterFinder``` class provides a constructor taking no arguments for ease of use (seee ```main.cpp```). 
