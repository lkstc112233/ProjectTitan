//
//  AI.h
//  ProjectTitan
//
//  Created by 煦 柯 on 15/2/17.
//  Copyright (c) 2015年 Must Studio. All rights reserved.
//

#ifndef __ProjectTitan__AI__
#define __ProjectTitan__AI__

#include <string>
#include <list>

class Items;

class Item
{
public:
    virtual ~Item(){}
    virtual Item* calculate()=0;
    virtual bool isList(){return false;}
};
class List : public Item
{
public:
    List();
    List(Items* items);
    virtual ~List();
    List* addItem(Item* item);
    virtual Item* calculate();
    virtual bool isList(){return true;}
private:
    Items* items;
    Item* itemKeeper=NULL;
};
class Symbol : public Item
{
public:
    Symbol(std::string name);
    Symbol(int id);
    virtual Item* calculate(){return this;}
private:
    int id;
};
class Value : public Item
{
public:
    Value(double d=0);
    virtual Item* calculate(){return this;}
private:
    double value;
};

class Items
{
public:
    ~Items();
    Items* addItem(Item* item){items.push_back(item);return this;}
    std::list<Item*> items;
};

class Ai
{
public:
    List* makeList(Items *items);
    Items* addListToItems(List * list,Items* items);
    Items* addIdentifierToItems(char * identifier,Items* items);
    Items* addValueToItems(double * value,Items* items);
    Items* makeItemsWithList(List * list);
    Items* makeItemsWithIdentifier(char * identifier);
    Items* makeItemsWithValue(double * value);
private:
    Items defines;
};

#endif /* defined(__ProjectTitan__AI__) */
