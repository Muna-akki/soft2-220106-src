#include <stdio.h>
#include <stdlib.h>
float calc_magicnumber(int i){
    FILE* fp;
    if ( (fp = fopen("helloworld.txt","rb")) == NULL){ 
        printf("file not open.\n");
	    exit(1);
    }
    int maxnum = 10000;
    float* buf = (float*)calloc(maxnum,sizeof(float));
    size_t rsize = fread(buf, sizeof(float), maxnum, fp);
    if(rsize<maxnum){
        buf[rsize] = '\0';
    }
    float ans = buf[i];
    free(buf);
    return ans;
}