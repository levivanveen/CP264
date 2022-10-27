/*
 -------------------------------------
 File:    graph_components.h
 Project: R12
 file description
 -------------------------------------
 Author:  Levi Van Veen
 ID:      200852490
 Email:   vanv2490@mylaurier.ca
 Version  2021-12-07
 -------------------------------------
 */

#ifndef GRAPH_COMPONENTS_H_
#define GRAPH_COMPONENTS_H_

#define True 1
#define False 0

typedef struct {
	int num;		//a unique number for the vertex
	char name[20];	//optional label
} Vertex;

Vertex* create_vertex(int num, char *name);
void print_vertex(Vertex *v);
void destroy_vertex(Vertex **v);
int is_equal_vertex(Vertex *v1, Vertex *v2);

typedef struct {
	Vertex *v1;		//First vertex
	Vertex *v2;		//Second vertex
	int weight;		//non-weighted graphs set to 0
	int directed;	//undirected graphs set to 0
} Edge;

Edge* create_edge(Vertex *v1, Vertex *v2, int w, int d);
void print_edge(Edge *e);
void destroy_edge(Edge **e);
int is_equal_edge(Edge *e1, Edge *e2);

#endif /* GRAPH_COMPONENTS_H_ */
