//
//  XMLGen.h
//  ProjectTitan
//
//  Created by 煦 柯 on 15/2/16.
//  Copyright (c) 2015年 Must Studio. All rights reserved.
//

#ifndef __ProjectTitan__XMLGen__
#define __ProjectTitan__XMLGen__

#include <vector>
#include <string>
#include <iostream>

class XMLNodeBase
{
public:
    virtual operator std::string()=0;
    virtual ~XMLNodeBase();
};

class XMLNode : public XMLNodeBase
{
public:
    XMLNode(std::string NodeName);
    virtual ~XMLNode();
    virtual operator std::string();
    XMLNode* addChild(XMLNodeBase* child);
private:
    std::string name;
    std::vector<XMLNodeBase*> childs;
};

class XMLTextNode : public XMLNodeBase
{
public:
    XMLTextNode(std::string text);
    virtual operator std::string();
private:
    std::string text;
};

class XMLGener
{
public:
    XMLGener(std::ostream& stream);
    void Generate(XMLNodeBase& base);
private:
    std::ostream& ost;
};

#endif /* defined(__ProjectTitan__XMLGen__) */
