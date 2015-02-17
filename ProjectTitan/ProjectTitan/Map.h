//
//  Map.h
//  ProjectTitan
//
//  Created by 煦 柯 on 15/2/17.
//  Copyright (c) 2015年 Must Studio. All rights reserved.
//

#ifndef __ProjectTitan__Map__
#define __ProjectTitan__Map__

#include <vector>
class XMLNodeBase;

class Object
{
public:
    Object(int x,int y);
    virtual ~Object(){}
    virtual int getId(){return id;}
    virtual int getX(){return m_x;}
    virtual int getY(){return m_y;}
    virtual XMLNodeBase* getXML()=0;
    virtual int getEvolutionRate(){return 0;}
    virtual void doAction(){}
protected:
    int id;
    int m_x;
    int m_y;
};

class Map
{
public:
    Map(int width,int height);
    ~Map();
    void addObject(Object* object);
    void evolution();
    XMLNodeBase* getXML();
private:
    int width;
    int height;
    std::vector<Object*> objects;
};


#endif /* defined(__ProjectTitan__Map__) */
