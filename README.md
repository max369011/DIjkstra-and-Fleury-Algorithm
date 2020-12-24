# Dijkstra's and Fluery's Algorithm

## Introduction
Dijkstra's algorithm finds the shortest path between two vertices while the
Fleury's algorithm finds the Euler path or circuit from the given input undirected multigraph with positive integer weights.

An explanation video for this program is at the link: https://youtu.be/ZVu1S3V34Ck

### Prerequisites
To run this program, download the zip file "21600580_HW#5"
it should contain
- Makefile
- dijkstra.c
- euler.c
- graph.h
- graph.
- 5 graph.txt files (graph2 is a Euler path and graph 4 is a Euler circuit)

## Input Format
- The data used in this program must be a undirected multigraph.
- The data must include in the first line number of vertices and number of edges.
  Followed with three integers the starting vertice, ending vertice and edge weight.

```
Ex)
5 8
0 1 1
0 3 2
1 1 1
1 2 3
1 4 2
2 3 1
2 3 4
3 4 1
```

## Instructions
- Open terminal and find the directory of the src folder

- To make a executable file type
```
make
```

- Once the executable file is made type to run Dijkstra algorithm with the starting vertice, ending vertice and input graph
```
./dijkstra 0 1 < graph1.txt
```
- To run the Fluery's algorithm type with the input graph
```
./euler < graph1.txt
```
