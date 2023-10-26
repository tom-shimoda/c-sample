#ifndef C_SAMPLE_LIST_H
#define C_SAMPLE_LIST_H

#include <malloc.h>
#include <memory.h>
#include <stdbool.h>

typedef struct _List
{
    void* data;
    struct _List* next;

    void (* OnRemove)(void*);
} List;

typedef struct
{
    List* hit; // 一致した要素
    List* next; // 一致した要素の次の要素
    List* back; // 一致した要素の前の要素
} ListFindResult;

#define foreach(list) for (List* v = list; v != NULL; v = v->next)

List* List_Create(void* data, void (* OnRemove)(void*));

void List_Add(List* list, void* data);

ListFindResult List_Find(List* list, const void* data);

void List_Remove(List* list, const void* data);

void List_RemoveAll(List* list);

#endif //C_SAMPLE_LIST_H
