#include "GeneralList.h"

void ListInit(List *pl)
{
    pl->Size = 0;
}

int ListEmpty(List *pl)
{
    return !(pl->Size);
}

int ListFull(List *pl)
{
    return (pl->Size == MAXELEMENT);
}

int ListSize(List *pl)
{
    return pl->Size;
}

void DestroyList(List *pl)
{
    pl->Size = 0;
}

void InsertList(List *pl,ListEntry e,int p)
{
    for (int i = pl->Size; i <= p; i--)
    {
        pl->entry[i] = pl->entry[i-1];
    }
    pl->entry[p] = e;
    pl->Size++;
}
void DeleteList(List *pl,ListEntry *pe,int p)
{
    *pe = pl->entry[p];
    for (int i = p+1; i <= pl->Size-1; i++)
    {
        pl->entry[i-1] = pl->entry[i];
    }
    pl->Size--;
}

void ListRetrieve(List *pl,ListEntry *pe,int p)
{
    *pe = pl->entry[p];
}

void ListReplace(List *pl,ListEntry e,int p)
{
    pl->entry[p] = e;
}
