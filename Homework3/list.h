#ifndef LIST_H
#define LIST_H

#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define STRING 0
#define INT 1
#define DOUBLE 2

#define RAND 3
#define INC 4
#define DEC 5

#define LINEMAXLENGTH 1024

typedef struct _Node {
	char *key;
	void *value;
	struct _Node *next;
} _node;

typedef struct _List {
	_node *head;
	int len;
} _list;

typedef struct _Type {
	int dataType;
	int sortType;
} _type;

_list *listConstructor();

void listDestructor(_list *list);

void addNode(_list *list, char *key, void *value);

void *searchList(_list *list, const char *key);

void sort(_type *type, _list *list);

void sortList(_list *list, int (*cmp)(const void *, const void *));

void outputList(_list *list, _type *type);

#endif // LIST_H
