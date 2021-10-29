#include"list.h"

static int rnd(const void *a, const void *b) {
	return (rand() % 2);
}

static int string_inc(const void *a, const void *b) {
	return strcmp((char *)(((_node *)a)->value), (char *)(((_node *)b)->value));
}

static int string_dec(const void *a, const void *b) {
	return strcmp((char *)(((_node *)b)->value), (char *)(((_node *)a)->value));
}

static int int_inc(const void *a, const void *b) {
	return *((int *)(((_node *)a)->value)) > *((int *)(((_node *)b)->value)) ? 1 : 0;
}

static int int_dec(const void *a, const void *b) {
	return *((int *)(((_node *)a)->value)) < *((int *)(((_node *)b)->value)) ? 1 : 0;
}

static int double_inc(const void *a, const void *b) {
	return *((double *)(((_node *)a)->value)) > *((double *)(((_node *)b)->value)) ? 1 : 0;
}

static int double_dec(const void *a, const void *b) {
	return *((double *)(((_node *)a)->value)) < *((double *)(((_node *)b)->value)) ? 1 : 0;
}

_list *listConstructor() {
	_list *list = malloc(sizeof(_list));
	list->head = NULL;
	list->len = 0;
	return list;
}

void listDestructor(_list *list) {
	if (NULL == list->head) {
		free(list);
		return;
	}
	_node *ptr = list->head;
	for (int i = 0; i < list->len; i++) {
		_node *temp = ptr->next;
		free(ptr->key);
		free(ptr->value);
		free(ptr);
		ptr = temp;
	}
	free(list);
}

// If the head node of a list is NULL, make the newly added node the head node,
// otherwise, append the newly added node to the end of the list
void addNode(_list *list, char* key, void* value) {
	_node *newNode = malloc(sizeof(_node));
	newNode->key = key;
	newNode->value = value;
	newNode->next = NULL;
	if (NULL == list->head) {
		list->head = newNode;
	}
	else {
		_node *it = list->head;
		while (NULL != it->next) {
			it = it->next;
		}
		it->next = newNode;
	}
	list->len++;
}

// Search for the value that match key in list, return NULL if the list is empty or
// no key can match
void *searchList(_list *list, const char *key) {
	if (NULL == list->head) {
		return NULL;
	}
	_node *it = list->head;
	while (NULL != it) {
		if (strcmp(key, it->key) == 0) {
			return it->value;
		}
	}
	return NULL;
}

void sort(_type *type, _list *list) {
	switch (type->sortType) {
		case RAND:
			sortList(list, rnd);
			break;
		case INC:
			if (type->dataType == STRING) {
				sortList(list, string_inc);
			}
			else if (type->dataType == INT) {
				sortList(list, int_inc);
			}
			else {
				sortList(list, double_inc);
			}
			break;
		case DEC:
			if (type->dataType == STRING) {
				sortList(list, string_dec);
			}
			else if (type->dataType == INT) {
				sortList(list, int_dec);
			}
			else {
				sortList(list, double_dec);
			}
			break;
	}
}

void sortList(_list *list, int (*cmp)(const void *, const void *)) {
	if (list->len <= 1) {
		return;
	}
	_node *sortedList = malloc(sizeof(_node) * list->len);
	_node *it = list->head;
	for (int i = 0; i < list->len; i++) {
		memcpy((sortedList + i), it, sizeof(_node));
		it = it->next;
	}
	/*
	for (int i = 1; i < list->len; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (cmp(sortedList + j, sortedList + j + 1)) {
				_node *temp = sortedList + j + 1;
				sortedList + j + 1 = sortedList + j;
				sortedList + j = temp;
			}
		}
	}
	*/
	qsort(sortedList, list->len, sizeof(_node), cmp);
	it = list->head;
	for (int i = 0; i < list->len; i++) {
		it->key = (sortedList + i)->key;
		it->value = (sortedList + i)->value;
		it = it->next;
	}
	free(sortedList);
}

void outputList(_list *list, _type *type) {
	char filename[50] = "";
	switch (type->sortType) {
		case RAND:
			strcpy(filename, "rand_");
			break;
		case INC:
			strcpy(filename, "inc_");
			break;
		case DEC:
			strcpy(filename, "dec_");
			break;
	}
	switch (type->dataType) {
		case STRING:
			strcat(filename, "string.txt");
			break;
		case INT:
			strcat(filename, "int.txt");
			break;
		case DOUBLE:
			strcat(filename, "double.txt");
			break;
	}
	FILE *file = fopen(filename, "w");
	printf("writing %s\n", filename);
	if (list->len == 0) {
		fclose(file);
		return;
	}
	_node *it = list->head;
	for (int i = 0; i < list->len; i++) {
		if (type->dataType == STRING) {
			fprintf(file, "%s=%s\n", it->key, (char *)(it->value));
		}
		else if (type->dataType == INT) {
			fprintf(file, "%s=%d\n", it->key, *((int *)(it->value)));
		}
		else {
			fprintf(file, "%s=%lf\n", it->key, *((double *)(it->value)));
		}
		it = it->next;
	}
	fclose(file);
}


