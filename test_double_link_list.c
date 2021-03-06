#include "double_link_list.h"
#include <assert.h>
#include <string.h>

void test_insert_before();
void test_insert_after();
void test_delete_node();

int main() {

	test_insert_before();
	test_insert_after();
	test_delete_node();
	test_retrieve();

	return 0;
}

void test_insert_before() {
	int a = 5;
	int b = 10;
	NODE *t_list = make_node();
	t_list->value = a;

	printf("Test insert_before\n\n");

	printf("Test 1\n");
	insert_before(t_list, b);
	assert((int) t_list->value == 5);
	assert((int) t_list->prev->value == 10);

	printf("Tests Passed\n\n");
}

void test_insert_after() {

	int a = 5;
	int b = 10;
	NODE *t_list = make_node();
	t_list->value = a;

	printf("Test insert_after\n\n");

	printf("Test 1\n");
	insert_before(t_list, b);
	assert((int) t_list->prev->value == 10);

	printf("Tests Passed\n\n");
}

void test_delete_node() {
	int a = 5;
	int b = 10;
	int c = 15;
	NODE *node_a = make_node();
	node_a->value = a;
	NODE *node_b;
	NODE *node_c;

	printf("Test delete_node\n\n");

	printf("Test 1\n");
	insert_before(node_a, b);
	insert_after(node_a, c);
	node_b = node_a->prev;
	node_c = node_a->next;
	delete_node(node_a);
	assert((int)node_b->next->value == 15);
	assert((int)node_c->prev->value == 10);

	printf("Tests Passed\n\n");
}

void test_retrieve() {
	int a = 5;
	int b = 10;
	int c = 15;
	int d = 20;
	NODE *node = make_node();
	node->value = a;
	insert_after(node, b);
	insert_after(node->next, c);

	printf("Test retrieve\n\n");

	printf("Test 1\n");
	assert((int)retrieve(d, node) == 0);

	printf("Test 2\n");
	assert((int)retrieve(b, node) == 10);

	printf("Test 3\n");
	assert((int)retrieve(c, node) == 15);

	printf("Test 4\n");
	assert((int)retrieve(a, node) == 5);	

	printf("Tests Passed\n\n");
}