#include "List.h"


List* List_Create(void* data, void (* OnRemove)(void*))
{
    List* res;

    res = (List*)malloc(sizeof(List));
    memset((void*)(res), 0, sizeof(List));

    res->data = data;
    res->OnRemove = OnRemove;

    return res;
}

void List_Add(List* list, void* data)
{
    List* newList = List_Create(data, list->OnRemove);

    for (List* v = list;; v = v->next)
    {
        if (v->next != NULL) continue;

        v->next = newList;
        break;
    }
}

ListFindResult List_Find(List* list, const void* data)
{
    ListFindResult res;
    res.hit = NULL;
    res.next = NULL;
    res.back = NULL;

    List* back;
    foreach(list)
    {
        if (v->data != data)
        {
            back = v;
            continue;
        }

        res.hit = v;
        res.next = v->next;
        res.back = back;
        break;
    }

    return res;
}

void List_Remove(List* list, const void* data)
{
    ListFindResult hit = List_Find(list, data);
    if (hit.hit == NULL) return;

    List* next = hit.next;
    List* back = hit.back;
    back->next = next != NULL ? next : NULL;

    // Listから除去された要素のdataのコールバック発火
    if (hit.hit->OnRemove != NULL)
    {
        hit.hit->OnRemove(hit.hit->data);
    }

    // list要素のメモリ開放
    free(hit.hit);
}

void List_RemoveAll(List* list)
{
    List* v = list;
    while (v->next != NULL)
    {
        List* current = v;
        v = v->next;
        free(current);
    }
}
