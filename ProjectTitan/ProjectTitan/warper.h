//
//  warper.h
//  ProjectTitan
//
//  Created by 煦 柯 on 15/2/17.
//  Copyright (c) 2015年 Must Studio. All rights reserved.
//

#ifndef __ProjectTitan__warper__
#define __ProjectTitan__warper__
#ifdef __cplusplus
class Ai;
void setAI(Ai* AiOperating);
int getIdByName(std::string name);
std::string getNameById(int id);
extern "C"
{
#endif
    char * newString(char* src);
    double * newDouble(char* src);
    void * makeList(void * items);
    void * makeEmptyList();
    void * addListToItems(void * list,void * items);
    void * addIdentifierToItems(void * identifier,void * items);
    void * addValueToItems(void * value,void * items);
    void * makeItemsWithList(void * list);
    void * makeItemsWithIdentifier(void * identifier);
    void * makeItemsWithValue(void * value);
#ifdef __cplusplus
}
#endif
#endif /* defined(__ProjectTitan__warper__) */
