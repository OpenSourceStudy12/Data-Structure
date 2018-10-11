/*
 * data.h
 *
 *  Created on: Oct 11, 2018
 *      Author: lrh
 */

#ifndef INC_DATA_H_
#define INC_DATA_H_

#include "BTree.h"
#include <vector>
#include <list>

//template<class type>
//int data_read(const char*,type&);

int data_create(const char *,int);

template<class type>
int data_read(const char *filename,type &tree){
	int value,ret;
	FILE *fp = fopen(filename,"rb");
	if (NULL == fp){
		printf("file open fail %s %d\n",__FILE__,__LINE__);
		return -1;
	}

	//while(!feof(fp)){
	for(;;){
		ret = fread(&value,sizeof(value),1,fp);
		if(ret < 1){
			break;
		}
		tree.Insert(value);
	}
	fclose(fp);
	return 0;
}

#endif /* INC_DATA_H_ */
