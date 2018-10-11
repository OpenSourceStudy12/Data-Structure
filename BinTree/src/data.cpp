/*
 * data.cpp
 *
 *  Created on: Oct 11, 2018
 *      Author: lrh
 */

#include "BTree.h"
#include "data.h"

int data_create(const char *filename,int num){
	int value,ret;
	vector<int>vet;
	vector<int>::iterator it;
	FILE *fp;
	//srand(time(0));
	for(;num;){
		value = rand()%65536;
		for(it = vet.begin();it != vet.end();it++){
			if(*it == value)
				break;
		}
		if(it == vet.end()){
			vet.push_back(value);
			num--;
		}
	}
	fp = fopen(filename,"wb");
	if(NULL == fp){
		printf("file open fail %s %d\n",__FILE__,__LINE__);
	}
	for(it = vet.begin();it != vet.end();it++){
		ret = fwrite(&(*it),sizeof(*it),1,fp);
		printf("value = %d\n",*it);
		if(ret < 0){
			printf("fwrite fail %s %d \n",__FILE__,__LINE__);
			fclose(fp);
			return -1;
		}
	}
	fclose(fp);
	return 0;
}
