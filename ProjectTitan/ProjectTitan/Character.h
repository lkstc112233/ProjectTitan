//
//  Character.h
//  ProjectTitan
//
//  Created by 煦 柯 on 15/2/17.
//  Copyright (c) 2015年 Must Studio. All rights reserved.
//

#ifndef __ProjectTitan__Character__
#define __ProjectTitan__Character__

#include "Map.h"

enum Actions
{
    MOVE,TURN,STAND,
};

enum Direction
{
    NORTH,EAST,SOUTH,WEST,
};

class Character : public Object
{
public:
    Character(int x,int y,int belonging);
    virtual ~Character();
    virtual XMLNodeBase* getXML();
    virtual int getEvolutionRate();
    virtual void doAction();
protected:
    int belonging;
    Direction direction;
    
    int HP;
    int MaxHP;
    int speed;
    int strength;
    
    void action(Actions act);
};

#endif /* defined(__ProjectTitan__Character__) */
