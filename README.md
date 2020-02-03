# JSONc : Simple JSON parser for C

## Table of content
* [How to use?](#How-to-use?)
* [JSONc structure](#JSONc-structure)
* [Functios](#Functios)
    * [init_JSONc](#init_JSONc)
    * [JSONc_createObject](#JSONc_createObject)
    * [JSONc_createString](#JSONc_createString)
    * [JSONc_createArray](#JSONc_createArray)
    * [JSONc_addItem2Object](#JSONc_addItem2Object)
    * [JSONc_addItem2Array](#JSONc_addItem2Array)
    * [JSONc_printUnformatted2Console](#JSONc_printUnformatted2Console)
    * [JSONc_printUnformatted](#JSONc_printUnformatted)
    * [JSONc_parseNotFirst](#JSONc_parseNotFirst)
    * [JSONc_parse](#JSONc_parse)
    * [JSONc_getArraySize](#JSONc_getArraySize)
    * [JSONc_getObjectItem](#JSONc_getObjectItem)
    * [JSONc_getArrayItem](#JSONc_getArrayItem)
    * [JSONc_delete](#JSONc_delete)

## How to use?
Just copy `JSONc.c` file beside your C code and use the include header below
```c
#include "JSONc.c"
```
or you can use full path for header if you don't put `JSONc.c` beside your code.

## JSONc structure
```c
struct JSONc
{
    struct JSONc *pre, *next, *child, *mom;
    char name[100], stringVal[100];
    JSONctype type;
};
```
This structure is for every JSON object. The names pretty illustrate the functionality of variables. JSONctype enum can have three value as below
- object
- array
- single

## Functios

### init_JSONc
```c
void init_JSONc(JSONc *source);
```
This function put NULL in every structure variable.

### JSONc_createObject
```c
JSONc *JSONc_createObject();
```
This function allocate space for JSON and declare object as a type of structure. Finally it returns pointer to allocated memory.

### JSONc_createString
```c
JSONc *JSONc_createString(char *val);
```
This function allocate space for JSON and declare single as a type of structure. Finally it returns pointer to allocated memory.

### JSONc_createArray
```c
JSONc *JSONc_createArray();
```
This function allocate space for JSON and declare array as a type of structure. Finally it returns pointer to allocated memory.

### JSONc_addItem2Object
```c
void JSONc_addItem2Object(JSONc *sourceObject, char *name, JSONc *item);
```
This function add an item `(JSONc *item)` with name `(char *name)` to source object `(JSONc *sourceObject)`. Items can be JSON of any type. This funtion has no return value.

### JSONc_addItem2Array
```c
void JSONc_addItem2Array(JSONc *sourceArray, JSONc *item);
```
This function add an item `(JSONc *item)` to source array `(JSONc *sourceArray)`. Items can be JSON of any type. This funtion has no return value.

### JSONc_printUnformatted2Console
```c
void JSONc_printUnformatted2Console(JSONc *source);
```
This function print given JSON `(JSONc *source)` to terminal. This funtion has no return value.

### JSONc_printUnformatted
```c
char *JSONc_printUnformatted (JSONc *source);
```
This function return start pointer of given JSON `(JSONc *source)` as a string.

### JSONc_parseNotFirst
```c
JSONc *JSONc_parseNotFirst(char *source, int *i);
```
This function is a compliment for `JSONc_parse` function.

### JSONc_parse
```c
JSONc *JSONc_parse(char *source);
```
This function get a string contain JSON and convert it to JSON three structure and return pointer to it.

### JSONc_getArraySize
```c
int JSONc_getArraySize(JSONc *array);
```
This funtion take JSON array as input and returns size of array.

### JSONc_getObjectItem
```c
JSONc *JSONc_getObjectItem(JSONc *source, char *name);
```
This function get source JSON `(JSONc *source)` and a name `(char *name)` and returns a pointer to object item with given name.

### JSONc_getArrayItem
```c
JSONc *JSONc_getArrayItem(JSONc *array, int index);
```
This funtion get an array `(JSONc *array)` as input and an index `(int index)` and returns pointer to item of array with given index.

### JSONc_delete
```c
void JSONc_delete(JSONc *ptr);
```
This function free every memory related to given JSON. This funtion has no return value.
