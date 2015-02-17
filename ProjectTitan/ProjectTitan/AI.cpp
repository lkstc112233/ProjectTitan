//
//  AI.cpp
//  ProjectTitan
//
//  Created by 煦 柯 on 15/2/17.
//  Copyright (c) 2015年 Must Studio. All rights reserved.
//

#include "AI.h"
#include "warper.h"

List::List()
:items(new Items)
{
    
}
List::List(Items* its)
:items(its)
{
    
}
List::~List()
{
    delete items;
}

Item* List::calculate()
{
    delete itemKeeper;
    // TODO
    itemKeeper=new List();
    return itemKeeper;
}

Symbol::Symbol(std::string name)
:id(getIdByName(name))
{
    
}
Symbol::Symbol(int idin)
:id(idin)
{
    
}

Value::Value(double d)
:value(d)
{
    
}

Items::~Items()
{
    for (Item* i:items)
        delete i;
}

List* Ai::makeList(Items *items)
{
    return new List(items);
}
Items* Ai::addListToItems(List * list,Items* items)
{
    return items->addItem(list);
}
Items* Ai::addIdentifierToItems(char * identifier,Items* items)
{
    auto r = items->addItem(new Symbol(identifier));
    delete [] identifier;
    return r;
}
Items* Ai::addValueToItems(double * value,Items* items)
{
    auto r = items->addItem(new Value(*value));
    delete value;
    return r;
}
Items* Ai::makeItemsWithList(List * list)
{
    return (new Items)->addItem(list);
}
Items* Ai::makeItemsWithIdentifier(char * identifier)
{
    auto r = (new Items)->addItem(new Symbol(identifier));
    delete [] identifier;
    return r;
}
Items* Ai::makeItemsWithValue(double * value)
{
    auto r = (new Items)->addItem(new Value(*value));
    delete value;
    return r;
}
