#ifndef GENERAL_LIST
#define GENERAL_LIST

#define MAXELEMENT 100  
typedef int ListEntry;  



typedef struct{
    ListEntry entry[MAXELEMENT];
    int Size;

}List;



void ListInit(List *pl);
int ListEmpty(List *pl);
int ListFull(List *pl);
int ListSize(List *pl);
void DestroyList(List *pl);
void InsertList(List *pl, ListEntry e,int p);
void DeleteList(List *pl, ListEntry *pe,int p);
void ListRetrieve(List *pl, ListEntry *pe,int p);
void ListReplace(List *pl, ListEntry e,int p);



#endif