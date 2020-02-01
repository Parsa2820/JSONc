#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum kiaJSONtype {single, object, array};

typedef enum kiaJSONtype kiaJSONtype;

struct kiaJSON
{
    struct kiaJSON *pre, *next, *child, *mom;
    char name[100], stringVal[100];
    kiaJSONtype type;
};

typedef struct kiaJSON kiaJSON;

void init_kiaJSON(kiaJSON *source)
{
    source -> pre = NULL;
    source -> next = NULL;
    source -> child = NULL;
    source -> mom = NULL;
    strcpy(source -> name, "");
    strcpy(source -> stringVal, "");
}

kiaJSON *kiaJSON_createObject()
{
    kiaJSON *ptr = (kiaJSON *)malloc(sizeof(kiaJSON));
    init_kiaJSON(ptr);
    ptr -> type = object;
    return ptr;
}

kiaJSON *kiaJSON_createString(char *val)
{
    kiaJSON *ptr = (kiaJSON *)malloc(sizeof(kiaJSON));
    init_kiaJSON(ptr);
    strcpy(ptr -> stringVal, val);
    ptr -> type = single;
    return ptr;
}

kiaJSON *kiaJSON_createArray()
{
    kiaJSON *ptr = (kiaJSON *)malloc(sizeof(kiaJSON));
    init_kiaJSON(ptr);
    ptr -> type = array;
    return ptr;
}

void kiaJSON_addItem2Object(kiaJSON *sourceObject, char *name, kiaJSON *item)
{
    kiaJSON *tmp;
    strcpy(item -> name, name);
    if (sourceObject -> child == NULL)
    {
        sourceObject -> child = item;
        item -> mom = sourceObject;
    }
    else if ((tmp = sourceObject -> child) -> next == NULL)
    {
        tmp -> next = item;
        item -> pre = tmp;
    }
    else
    {
        while (tmp -> next != NULL)
            tmp = tmp -> next;
        tmp -> next = item;
        item -> pre = tmp;        
    }    
}

void kiaJSON_addItem2Array(kiaJSON *sourceArray, kiaJSON *item)
{
    kiaJSON *tmp;
    if (sourceArray -> child == NULL)
    {
        sourceArray -> child = item;
        item -> mom = sourceArray;
    }
    else if ((tmp = sourceArray -> child) -> next == NULL)
    {
        tmp -> next = item;
    }
    else
    {
        while (tmp -> next != NULL)
            tmp = tmp -> next;
        tmp -> next = item;
        item -> pre = tmp;        
    }
}

void kiaJSON_printUnformatted(kiaJSON *source)
{
    if (source -> type == single)
    {
        if (strcmp(source -> name, ""))
            printf("\"%s\":", source -> name);
        printf("\"%s\"", source -> stringVal);
        if (source -> next != NULL)
        {
            printf(",");
            kiaJSON_printUnformatted(source -> next);
        }
    }
    else if (source -> type == array)
    {
        if (strcmp(source -> name, ""))
            printf("\"%s\":", source -> name);
        printf("[");
        if (source -> child != NULL)
            kiaJSON_printUnformatted(source -> child);
        printf("]");
        if (source -> next != NULL)
        {
            printf(",");
            kiaJSON_printUnformatted(source -> next);
        }
    }
    else if (source -> type == object)
    {
        if (strcmp(source -> name, ""))
            printf("\"%s\":", source -> name);
        printf("{");
        if (source -> child != NULL)
            kiaJSON_printUnformatted(source -> child);
        printf("}");    
        if (source -> next != NULL)
        {
            printf(",");
            kiaJSON_printUnformatted(source -> next);
        }   
    }
}
