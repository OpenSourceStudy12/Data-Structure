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

int data_create(const char *filename,int num){
	int value,ret;
	vector<int>vet;
	vector<int>::iterator it;
	FILE *fp;
//	srand(time(0));
//	for(;num;){
//		value = rand()%(2^32);
//		for(it = vet.begin();it != vet.end();it++){
//			if(*it == value)
//				break;
//		}
//		if(it == vet.end()){
//			vet.push_back(value);
//			num--;
//		}
//	}
	for(;num;num--){
		vet.push_back(num);
	}
	fp = fopen(filename,"wb");
	if(NULL == fp){
		printf("file open fail %s %d\n",__FILE__,__LINE__);
	}
	for(it = vet.begin();it != vet.end();it++){
		ret = fwrite(&(*it),sizeof(*it),1,fp);
		if(ret < 0){
			printf("fwrite fail %s %d \n",__FILE__,__LINE__);
			fclose(fp);
			return -1;
		}
	}
	fclose(fp);
	return 0;
}

#endif /* INC_DATA_H_ */
