#include <stdio.h>
#include <stdlib.h>
#include "./../include/item.h"

// 構造体をポインタで確保するお作法を確認してみよう
Itemset *init_itemset(size_t number, int seed)
{
    Itemset *list = (Itemset*)malloc(sizeof(Itemset));

    Item *item = (Item*)malloc(sizeof(Item)*number);

    srand(seed);
    for (int i = 0 ; i < number ; i++){
        item[i].value = 0.1 * (rand() % 200);
    	item[i].weight = 0.1 * (rand() % 200 + 1);
  	}
  	*list = (Itemset){.number = number, .item = item};
  	return list;
}

// itemset の free関数
void free_itemset(Itemset *list)
{
  	free(list->item);
  	free(list);
}

// 表示関数
void print_itemset(const Itemset *list)
{
  	size_t n = list->number;
  	const char *format = "v[%d] = %4.1f, w[%d] = %4.1f\n";
  	for(int i = 0 ; i < n ; i++){
      	Item item = get_item(list, i);
      	printf(format, i, get_itemvalue(item), i, get_itemweight(item));
  	}
  	printf("----\n");
}

Item get_item(const Itemset *list, size_t index)
{
    return list->item[index];
}

double get_itemweight(Item item)
{
    return item.weight;
}

double get_itemvalue(Item item){
    return item.value;
}

void save_itemset(char *filename, const Itemset *list){
    int n = list->number;
    FILE* fp = fopen(filename, "wb");
    if(fp==NULL){
        printf("%s: cannot open tile.\n",filename);
        exit(1);
    }
    double* point = (double*)malloc(sizeof(double)*n);
    fwrite(&n, sizeof(int),1,fp); 
    //value
    for(int i=0 ; i<n ; i++){
        point[i] = list->item[i].value;
    }
    fwrite(point, sizeof(double),n,fp);
    //weight
    for(int i=0 ; i<n ; i++){
        point[i] = list->item[i].weight;
    }
    fwrite(point, sizeof(double),n,fp);
    free(point);
    fclose(fp);
}

Itemset* load_itemset(char* filename){
    FILE* fp;
    if( (fp = fopen(filename,"rb")) == NULL ){
        printf("%s: file not open.\n",filename);
        exit(0);
    }
    int n = 0;
    fread(&n, sizeof(int), 1, fp);
    Itemset *list = (Itemset*)malloc(sizeof(Itemset));

    Item *item = (Item*)malloc(sizeof(Item)*n);
    double* data = (double*) malloc(sizeof(double)*n);
    //value
    fread(data,sizeof(double),n,fp);
    for(int i=0 ; i<n ; i++){
        item[i].value = data[i];
    }
    //weight
    fread(data,sizeof(double),n,fp);
    for(int i=0 ; i<n ; i++){
        item[i].weight = data[i];
    }
    *list = (Itemset){.number = n, .item = item};
  	return list;
}