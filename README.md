# Sorting Algorithms

An university work about sorting algorithms; The intention was to
compare four types of sorting algorithms by execution time with linked
lists.

Also three lib prototypes are shipped with the code:

- dllist: A generic double-linked list with some code to management
(still in development).
- sorting: Sorting operations to dllist.
- TpContato: The base structure required to develop the work.

In this work were implemented:

 - Insertion Sort
 - Selection Sort
 - Quick Sort
 - Merge Sort

## About Sorting

Sort 'name' in TpContato struct by strcmp, not by the number that is
appended to 'name';

## Compilling

The executables are on `/builds` directory. The main program is named
`main`.

```sh
make       # compile the full program
make run   # compile and run program
make debug # compile and run program under valgrind environment
```
