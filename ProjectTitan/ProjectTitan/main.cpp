//
//  main.cpp
//  ProjectTitan
//
//  Created by 煦 柯 on 15/2/16.
//  Copyright (c) 2015年 Must Studio. All rights reserved.
//

#include <iostream>
#include "XMLGen.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    XMLNode node("Data");
    XMLNode* pointer;
    pointer=new XMLNode("Map");
    node.addChild(pointer);
    pointer->addChild(new XMLTextNode("Status"));
    pointer->addChild(new XMLNode("Status"));
    
//    std::cout << "Hello, World!\n";
    XMLGener gener(std::cout);
    gener.Generate(node);
    return 0;
}
