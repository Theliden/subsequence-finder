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
