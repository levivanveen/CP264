/**
 * -----------------------------------------------------
 * Testing for undirected non-weighted Graph
 * -----------------------------------------------------
 */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "graph.h"

void test_remove_vertex();

int main() {
	setbuf(stdout, NULL);
	test_remove_vertex();
	return 0;
}

void test_remove_vertex() {
	printf("------------------------------\n");
	printf("Start: Testing remove_vertex_graph:\n\n");

	printf("Creating a graph with 8 vertices\n");
	Graph *g = create_graph(1, 0);

	Vertex *v[8];
	char temp[5];

	int i;
	for (i = 0; i < 8; i++) {
		sprintf(temp, "V%d", i);
		v[i] = create_vertex(i, temp);
		add_vertex_graph(g, v[i]);
	}
	print_graph(g);
	printf("\n");

	printf("Adding 12 edges:\n");
	Edge *e[12];
	e[0] = create_edge(v[0], v[1], 0, 0);
	add_edge_graph(g, e[0]);

	e[1] = create_edge(v[4], v[5], 0, 0);
	add_edge_graph(g, e[1]);

	e[2] = create_edge(v[1], v[4], 0, 0);
	add_edge_graph(g, e[2]);

	e[3] = create_edge(v[0], v[4], 0, 0);
	add_edge_graph(g, e[3]);

	e[4] = create_edge(v[1], v[5], 0, 0);
	add_edge_graph(g, e[4]);

	e[5] = create_edge(v[3], v[4], 0, 0);
	add_edge_graph(g, e[5]);

	e[6] = create_edge(v[2], v[6], 0, 0);
	add_edge_graph(g, e[6]);

	e[7] = create_edge(v[6], v[4], 0, 0);
	add_edge_graph(g, e[7]);

	e[8] = create_edge(v[3], v[6], 5, 0);
	add_edge_graph(g, e[8]);

	e[9] = create_edge(v[2], v[7], 5, 0);
	add_edge_graph(g, e[9]);

	e[10] = create_edge(v[0], v[7], 5, 0);
	add_edge_graph(g, e[10]);

	e[11] = create_edge(v[4], v[7], 5, 0);
	add_edge_graph(g, e[11]);

	print_graph(g);
	printf("\n");

	printf("remove V3:\n");
	remove_vertex_graph(g, v[3]);
	print_graph(g);
	printf("\n");

	printf("remove V2:\n");
	remove_vertex_graph(g, v[2]);
	print_graph(g);
	printf("\n");

	printf("remove V0:\n");
	remove_vertex_graph(g, v[0]);
	print_graph(g);
	printf("\n");

	printf("remove V4:\n");
	remove_vertex_graph(g, v[4]);
	print_graph(g);
	printf("\n");

	printf("remove V7:\n");
	v[7]->num = 3;
	remove_vertex_graph(g, v[7]);
	print_graph(g);
	printf("\n");

	printf("remove V1:\n");
	remove_vertex_graph(g, v[1]);
	print_graph(g);
	printf("\n");

	printf("remove V6:\n");
	v[6]->num = 1;
	remove_vertex_graph(g, v[6]);
	print_graph(g);
	printf("\n");

	printf("remove V5:\n");
	v[5]->num = 0;
	remove_vertex_graph(g, v[5]);
	print_graph(g);
	printf("\n");

	printf("Destroy vertices\n");
	for (i = 0; i < 8; i++)
		destroy_vertex(&v[i]);
	printf("Destroy edges\n");
	for (i = 0; i < 12; i++)
		destroy_edge(&e[i]);

	destroy_graph(&g);
	printf("Graph destroyed successfully\n\n");

	printf("End: Testing remove_vertex_graph\n");
	printf("------------------------------\n\n");
	return;
}
