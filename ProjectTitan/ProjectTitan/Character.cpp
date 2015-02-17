//
//  Character.cpp
//  ProjectTitan
//
//  Created by 煦 柯 on 15/2/17.
//  Copyright (c) 2015年 Must Studio. All rights reserved.
//

#include "Character.h"
#include "XMLGen.h"


Character::Character(int x,int y,int belongingin)
:Object(x,y)
,belonging(belongingin)
{
    //TODO add other implements.
    MaxHP=HP=rand()%100+200;
    speed=rand()%10+10;
    strength=rand()%20+40;
    direction=Direction(rand()%4);
}

Character::~Character()
{
    
}
XMLNodeBase* Character::getXML()
{
    XMLNode* node=new XMLNode("Character");
    node->addChild((new XMLNode("Id"))->addChild(new XMLTextNode(std::to_string(id))));
    node->addChild((new XMLNode("Belonging"))->addChild(new XMLTextNode(std::to_string(belonging))));
    node->addChild((new XMLNode("Position"))
                   ->addChild((new XMLNode("x"))->addChild(new XMLTextNode(std::to_string(m_x))))
                   ->addChild((new XMLNode("y"))->addChild(new XMLTextNode(std::to_string(m_y))))
                   ->addChild((new XMLNode("Direction"))->addChild(new XMLTextNode(std::to_string(direction)))));
    
    node->addChild((new XMLNode("Status"))
                   ->addChild((new XMLNode("HP"))->addChild(new XMLTextNode(std::to_string(HP))))
                   ->addChild((new XMLNode("HPMax"))->addChild(new XMLTextNode(std::to_string(MaxHP))))
                   ->addChild((new XMLNode("Speed"))->addChild(new XMLTextNode(std::to_string(speed))))
                   ->addChild((new XMLNode("Strength"))->addChild(new XMLTextNode(std::to_string(strength)))));
//                   ->addChild((new XMLNode("x"))->addChild(new XMLTextNode(std::to_string(m_x))))
//                   ->addChild((new XMLNode("y"))->addChild(new XMLTextNode(std::to_string(m_y))))
//                   ->addChild((new XMLNode("x"))->addChild(new XMLTextNode(std::to_string(m_x))))
//                   ->addChild((new XMLNode("y"))->addChild(new XMLTextNode(std::to_string(m_y))))
//                   ->addChild((new XMLNode("x"))->addChild(new XMLTextNode(std::to_string(m_x))))
//                   ->addChild((new XMLNode("y"))->addChild(new XMLTextNode(std::to_string(m_y)))));
    return node;
}
int Character::getEvolutionRate()
{
    return speed;
}
void Character::doAction()
{
    switch (rand()%5) {
        case 0:
        case 1:
        case 2:
            action(STAND);
            break;
        case 3:
            action(MOVE);
            break;
        case 4:
            action(TURN);
    }
}

void Character::action(Actions act)
{
    switch (act)
    {
        case STAND:
            break;
        case MOVE:
            switch (direction)
            {
                case NORTH:
                    m_y-=1;
                    break;
                case SOUTH:
                    m_y+=1;
                    break;
                case EAST:
                    m_x+=1;
                    break;
                case WEST:
                    m_x-=1;
                    break;
                default:
                    break;
            }
            break;
        case TURN:
            direction=Direction((direction+1)%4);
            break;
        default:
            break;
    }
}
