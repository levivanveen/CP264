/*
 -------------------------------------
 File:    graph.h
 Project: R12
 file description
 -------------------------------------
 Author:  Levi Van Veen
 ID:      200852490
 Email:   vanv2490@mylaurier.ca
 Version  2021-12-07
 -------------------------------------
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include "graph_components.h"

#define BLOCK 5
#define True 1
#define False 0

typedef struct {
	int **matrix;				//adjacency matrix
	Vertex *vertex_list;		//list to store vetices
	int vertex_count;			//num vertices
	int edge_count;				//num edges
	int directed;				//flag 0: undirected, 1: directed
	int weighted;				//flag 0: non-weighted, 1: weighted
} Graph;

Graph* create_graph(int w, int d);
void destroy_graph(Graph **g);
void print_graph(Graph *g);

int is_null_graph(Graph *g);
int is_empty_graph(Graph *g);

int add_vertex_graph(Graph *g, Vertex *v);
int has_vertex_graph(Graph *g, Vertex *v);
int remove_vertex_graph(Graph *g, Vertex *v);

int add_edge_graph(Graph *g, Edge *e);
int has_edge_graph(Graph *g, Edge *e);
int remove_edge_graph(Graph *g, Edge *e);

#endif /* GRAPH_H_ */
