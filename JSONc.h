#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum JSONctype {single, object, array};

typedef enum JSONctype JSONctype;

struct JSONc
{
    struct JSONc *pre, *next, *child, *mom;
    char name[100], stringVal[100];
    JSONctype type;
};

typedef struct JSONc JSONc;

void init_JSONc(JSONc *source);
JSONc *JSONc_createObject();
JSONc *JSONc_createString(char *val);
JSONc *JSONc_createObject();
JSONc *JSONc_createString(char *val);
JSONc *JSONc_createArray();
void JSONc_addItem2Object(JSONc *sourceObject, char *name, JSONc *item);
void JSONc_addItem2Array(JSONc *sourceArray, JSONc *item);
void JSONc_printUnformatted2Console(JSONc *source);
char *JSONc_printUnformatted (JSONc *source);
JSONc *JSONc_parseNotFirst(char *source, int *i);
JSONc *JSONc_parse(char *source);
int JSONc_getArraySize(JSONc *array);
JSONc *JSONc_getObjectItem(JSONc *source, char *name);
JSONc *JSONc_getArrayItem(JSONc *array, int index);
void JSONc_delete(JSONc *ptr);
