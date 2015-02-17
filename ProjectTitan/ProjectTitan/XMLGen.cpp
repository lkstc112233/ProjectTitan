//
//  XMLGen.cpp
//  ProjectTitan
//
//  Created by 煦 柯 on 15/2/16.
//  Copyright (c) 2015年 Must Studio. All rights reserved.
//

#include "XMLGen.h"

XMLNodeBase::~XMLNodeBase()
{
}

XMLNode::XMLNode(std::string NodeName)
:name(NodeName)
{
    
}

XMLNode::~XMLNode()
{
    for (XMLNodeBase* s:childs) {
        delete s;
    }
}

XMLNode:: operator std::string()
{
    if (childs.size()==0)
    {
        std::string toReturn="<";
        toReturn+=name;
        toReturn+=" />";
        return toReturn;
    }
    std::string toReturn="<";
    toReturn+=name;
    toReturn+=">";
    for (XMLNodeBase* s: childs)
        toReturn+=(*s);
    toReturn+="</";
    toReturn+=name;
    toReturn+=">";
    return toReturn;
}

XMLNode* XMLNode::addChild(XMLNodeBase* child)
{
    childs.push_back(child);
    return this;
}

XMLTextNode::XMLTextNode(std::string texts)
:text(texts)
{
    
}

XMLTextNode:: operator std::string()
{
    return text;
}


XMLGener::XMLGener(std::ostream& stream)
:ost(stream)
{
    
}

void XMLGener::Generate(XMLNodeBase& base)
{
    ost<<base.operator std::string();
}
