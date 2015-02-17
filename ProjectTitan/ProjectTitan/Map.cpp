//
//  Map.cpp
//  ProjectTitan
//
//  Created by 煦 柯 on 15/2/17.
//  Copyright (c) 2015年 Must Studio. All rights reserved.
//


#include <string>
#include "Map.h"
#include "XMLGen.h"
namespace MAP_STATIC{
    static int idstatic=0;
}
Object::Object(int x,int y)
:id(MAP_STATIC::idstatic++)
,m_x(x)
,m_y(y)
{
    
}

Map::Map(int wid,int hei)
: width(wid)
, height(hei)
{
    
}

Map::~Map()
{
    for (Object* o:objects)
        delete o;
}

void Map::evolution()
{
    int weightTotal=0;
    for (Object* o:objects)
        weightTotal+=o->getEvolutionRate();
    if (weightTotal==0)
        return;
    weightTotal=rand()%weightTotal;
    for (Object* o:objects)
        if (weightTotal-=o->getEvolutionRate()<=0)
        {
            o->doAction();
            break;
        }
}

XMLNodeBase* Map::getXML()
{
    XMLNode* node=new XMLNode("Map");
    node->addChild((new XMLNode("Width"))->addChild(new XMLTextNode(std::to_string(width))));
    node->addChild((new XMLNode("Height"))->addChild(new XMLTextNode(std::to_string(height))));
    XMLNode* temp=new XMLNode("Objects");
    for (Object* o:objects)
        temp->addChild(o->getXML());
    node->addChild(temp);
    return node;
}

void Map::addObject(Object *object)
{
    objects.push_back(object);
}
