#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <string.h>


#define MAX 256

int edgeCount(graph_t * g){
   int num = 0;
   for(int i = 0; i<g->n_vertices; i++)
      for(int j = i; j<g->n_vertices; j++)
         if(g->m[i][j])
            num++;
   return num; 
}

int isBridge(graph_t * g, int next) {
	int degNum = 0;
	for(int i =0; i<g->n_vertices; i++) {
		if(g->m[next][i] > 0)
			degNum++;
	
		//edge is not a bridge
		if(degNum > 1)
			return 0;	
	}
	//edge is a bridge
	return 1;	
}

/*
input: graph structure, starting vertice
output: path for euler circuit or path. If not either returns nothing.
*/
void take_a_tour(graph_t * g, int start) {
	
	int n_edges, next, curr;
	
	curr = start;

	n_edges = edgeCount(g);

	//printf("n_edges = %d\n", n_edges);
	
	for(next =0; next<g->n_vertices; next++) {
		if(g->m[curr][next] > 0) {
			if(n_edges <= 1 || !isBridge(g, next)) {

				if(n_edges <=1)
					printf("%d --> %d\n", curr, next);
				else 
					printf("%d --> ", curr);

				graph_remove_edge(g,curr,next,g->w[curr][next][0]);
				take_a_tour(g, next);
			}
		}
	}
}

void euler(graph_t * g) {

	int n_edges, next;
	int deg = 0;
	int evencount = 0, oddcount = 0;
	int vertDegCount[64];

	int curr = 0;

	// Not enough vertices
	if(g->n_vertices < 2) {
		//printf("Not enough vertices for euler graph\n");
		return;
	}

	// Count the degrees for each vertice
	for(int i=0; i<g->n_vertices; i++) {
		deg = 0;
		for(int j=0; j<g->n_vertices; j++) {
			if(g->m[i][j] > 0) {
				for(int k=0; k < g->m[i][j]; k++) {
					deg++;
				}
			}
		}
		vertDegCount[i] = deg;
	}

	// check if degrees are even or odd for each vertice
	for(int i =0; i<g->n_vertices; i++) {
		if(vertDegCount[i] % 2 == 0) {
			evencount++;
		} else {
			oddcount++;
		}
	}

	//printf("evencount = %d, oddcount = %d\n", evencount, oddcount);

	// Check if euler circuit or euler path
	if(evencount == g->n_vertices) {
		//Euler Circuit
	
		take_a_tour(g,0);

		printf("This is a Euler Circuit\n");

	} else if(oddcount == 2) {
		//Euler Path

		// Find and start at odd degree vertice
		for(int i=0; i<g->n_vertices; i++) {
			if(vertDegCount[i] % 2 != 0) {
				take_a_tour(g, i);
				break;
			}
		}

		printf("This is a Euler Path\n");

	} 
}



/*TODO: you can add functions as you want */

int
main ()
{
	graph_t * g ; 

	g = graph_read_stdin() ;

	/* TODO: implement here */
	
	euler(g);

	graph_free(g) ;
	return 0 ;
}
