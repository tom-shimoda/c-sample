#include <stdio.h>
#include "ListSample.h"
#include "List.h"

typedef struct
{
    char* name;
} User;

static void OnRemove(void* data)
{
    free(data);
}

void ListSample()
{
    User* data1 = (User*)malloc(sizeof(User));
    data1->name = "hoge";
    List* list = List_Create((void*)data1, OnRemove);

    User* data2 = (User*)malloc(sizeof(User));
    data2->name = "foo";
    List_Add(list, (void*)data2);

    User* data3 = (User*)malloc(sizeof(User));
    data3->name = "fuga";
    List_Add(list, (void*)data3);

    foreach(list)
    {
        printf("%s\n", ((User*)(v->data))->name);
    }

    printf("--- remove ---\n");
    List_Remove(list, data2);
    
    foreach(list)
    {
        printf("%s\n", ((User*)(v->data))->name);
    }

    List_RemoveAll(list);
}
