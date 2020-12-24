#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <string.h>

#define INFINITE 999999
#define MAX 256

/*
input: graph structure, staring vertice and ending vertice
output: distance from the starting vertice to ending vertice depending on edge weight. If no such way returns nothing.
*/

void Dijkstra(graph_t * g, int start, int end) {

	int visited[64], distance[MAX], cost[MAX][MAX];

	memset(visited, 0, sizeof(int) * 64);

	int count, curr, minDist = INFINITE;

	//printf("start = %d, end = %d\n", start, end);


	// Organize the edges for each vertice into cost matrix
	for(int i=0; i < g->n_vertices; i++) {
		for(int j=0; j < g->n_vertices; j++) {
			//printf("%d\n", g->m[i][j]);
			if(g->m[i][j] == 0) {
				cost[i][j] = INFINITE;
			} else {
				minDist = INFINITE;
				for(int k=0; k< g->m[i][j]; k++) {
					// Find smallest edge weight in multigraph
					if(g->w[i][j][k] < minDist)
						minDist = g->w[i][j][k];
				}
				cost[i][j] = minDist;
			}
		}
	}

	
	// initalize all distance from start vertice
 	for (int i = 0; i < g->n_vertices; i++) {
    	distance[i] = cost[start][i];
  	}

	// reinitalize the distance and vertice visited for the starting vertice
	distance[start] = 0;
	visited[start] = 1;
	count = 1;

	while (count < g->n_vertices - 1) {
    	minDist = INFINITE;

		// find min distance to each vertice from start vertice
    	for (int i = 0; i < g->n_vertices; i++) {

			if(visited[i] == 0) {
      			if (distance[i] < minDist) {
        			minDist = distance[i];
        			curr = i;
      			}
			}
		}
		
		// check for shorter path through nextnode
    	visited[curr] = 1;

   		for (int i = 0; i < g->n_vertices; i++) {
   			if (visited[i] == 0) {
        		if (minDist + cost[curr][i] < distance[i]) {
          			distance[i] = minDist + cost[curr][i];
        		}
			}
		}
		count++;
  	}
	
	// If there is no path to the end vertice
	if(distance[end] == INFINITE)
		return;
	
    printf("Distance from %d to %d is %d\n", start, end, distance[end]);
}


/*TODO: you can add functions as you want */

int
main (int argc, char ** args)
{
	graph_t * g ; 

	g = graph_read_stdin() ;

	if (argc != 3) { 
		fprintf(stderr, "Too few arguments\n") ;
		return 1 ;
	}

	int start, end ;

	start = atoi(args[1]) ;
	end = atoi(args[2]) ;

	if (start < 0 || g->n_vertices <= start ||
		end < 0 || g->n_vertices <= end) {
		fprintf(stderr, "Wrong arguments\n") ;
		return 1 ;
	}


	/* TODO: implement here */

	Dijkstra(g, start, end);

	graph_free(g) ;
	return 0 ;
}
