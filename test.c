#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int
main ()
{
	graph_t * g ; 

	g = graph_read_stdin() ;
	graph_print_stdout(g) ;

	graph_remove_edge(g, 2, 3, 2) ;
	graph_remove_edge(g, 2, 3, 1) ;
	graph_remove_edge(g, 1, 1, 1) ;
	graph_remove_edge(g, 3, 1, 2) ;

	printf("\n") ;

	graph_print_stdout(g) ;


	for(int i =0; i < g->n_vertices; i++) {
		for(int j=0; j< g->n_vertices; j++){
			int gg = g->m[i][j];

			printf("g(%d, %d) = g->[i][j] = %d   ", i,j, gg);
			
			for (int k = 0 ; k < g->m[i][j] ; k++) {
				printf("w[i][j][k] = %d ", g->w[i][j][k]) ;
			}
			printf("\n");
		}
	}



	graph_free(g) ;
}
