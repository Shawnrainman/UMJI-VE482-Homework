#include"list.h"

void sortFile(_type *type, char *filename) {
	_list *list = listConstructor();
	FILE* fIn = fopen(filename, "r");
	printf("reading %s\n", filename);
	char *input = malloc(sizeof(char) * LINEMAXLENGTH);
	char *tempKey, *tempValue;
	memset(input, '\0', LINEMAXLENGTH);
	while (fgets(input, LINEMAXLENGTH, fIn) != NULL) {
		tempKey = strtok(input, "=");
		tempValue = strtok(NULL, "\n");
		void *data;
		if (type->dataType == STRING) {
			data = (void *)malloc(sizeof(char) * strlen(tempValue));
			memset(data, '\0', LINEMAXLENGTH);
			strcpy((char *)data, tempValue);
		}
		else if (type->dataType == INT) {
			int value = atoi(tempValue);
			data = (void *)malloc(sizeof(int));
			*(int *) data = value;
		}
		else {
			double value = atof(tempValue);
			data = (void *)malloc(sizeof(double));
			*(double *)data = value;
		}
		char *key = (char *)malloc(sizeof(char) * LINEMAXLENGTH);
		memset(key, '\0', LINEMAXLENGTH);
		strcpy(key, tempKey);
		addNode(list, key, data);
		memset(input, '\0', LINEMAXLENGTH);
	}
	free(input);
	fclose(fIn);
	printf("sorting elements\n");
	sort(type, list);
	outputList(list, type);
	listDestructor(list);
}

void getType(_type *type, char *argv[]) {
	if (strstr(argv[1], "string") != NULL) {
		type->dataType = STRING;
	}
	else if (strstr(argv[1], "int") != NULL) {
		type->dataType = INT;
	}
	else {
		type->dataType = DOUBLE;
	}
	if (strstr(argv[2], "rand") != NULL) {
		type->sortType = RAND;
	}
	else if (strstr(argv[2], "inc") != NULL) {
		type->sortType = INC;
	}
	else {
		type->sortType = DEC;
	}
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("Error: arguments missing\n");
		return -1;
	}
	_type type;
	getType(&type, argv);
	sortFile(&type, argv[1]);
	return 0;
}
