//
//  warper.cpp
//  ProjectTitan
//
//  Created by 煦 柯 on 15/2/17.
//  Copyright (c) 2015年 Must Studio. All rights reserved.
//

#include <map>
#include <string>
#include <sstream>
#include "warper.h"
#include "AI.h"
#include <cstring>

template <class Type>
Type stringToNum(const std::string& str)
{
    std::istringstream iss(str);
    Type num;
    iss >> num;
    return num;
}

Ai* AiOperating;
std::map<int, std::string> identifierTable;
std::map<std::string, int> nameTable;

void setAI(Ai* ai)
{
    AiOperating=ai;
}

int addName(std::string name)
{
    int temp=static_cast<int>(identifierTable.size());
    identifierTable.insert(make_pair(temp,name));
    nameTable.insert(make_pair(name,temp));
    return temp;
}

int getIdByName(std::string name)
{
    auto pid=nameTable.find(name);
    if (pid==nameTable.end())
    {
        return addName(name);
    }
    return pid->second;
}
std::string getNameById(int id)
{
    auto pid=identifierTable.find(id);
    if (pid==identifierTable.end())
    {
        throw -1;
    }
    return pid->second;
}

#ifdef __CPLUSPLUS
extern "C"
{
#endif
    char * newString(char* src)
    {
        char* temp = new char[strlen(src)+1];
        strcpy(temp,src);
        return temp;
    }
    double * newDouble(char* src)
    {
        double * temp=new double;
        *temp=stringToNum<double>(src);
        return temp;
    }
    void * makeList(void * items)
    {
        return AiOperating->makeList(static_cast<Items*>(items));
    }
    void * makeEmptyList()
    {
        return new List();
    }
    void * addListToItems(void * list,void * items)
    {
        return AiOperating->addListToItems(static_cast<List*>(list), static_cast<Items*>(items));
    }
    void * addIdentifierToItems(void * identifier,void * items)
    {
        return AiOperating->addIdentifierToItems(static_cast<char*>(identifier), static_cast<Items*>(items));
    }
    void * addValueToItems(void * value,void * items)
    {
        return AiOperating->addValueToItems(static_cast<double*>(value),static_cast<Items*>(items));
    }
    void * makeItemsWithList(void * list)
    {
        return AiOperating->makeItemsWithList(static_cast<List*>(list));
    }
    void * makeItemsWithIdentifier(void * identifier)
    {
        return AiOperating->makeItemsWithIdentifier(static_cast<char*>(identifier));
    }
    void * makeItemsWithValue(void * value)
    {
        return AiOperating->makeItemsWithValue(static_cast<double*>(value));
    }
#ifdef __CPLUSPLUS
}
#endif