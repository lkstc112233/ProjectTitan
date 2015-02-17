//
//  main.cpp
//  ProjectTitan
//
//  Created by 煦 柯 on 15/2/16.
//  Copyright (c) 2015年 Must Studio. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "XMLGen.h"
#include "Map.h"
#include "Character.h"

extern "C" int yyparse ();

int main(int argc, const char * argv[]) {
    // insert code here...
    
    yyparse();
    
    
//    Map map(100,100);
//    map.addObject(new Character(rand()%100,rand()%100,1));
//    map.addObject(new Character(rand()%100,rand()%100,1));
//    map.addObject(new Character(rand()%100,rand()%100,2));
//    map.addObject(new Character(rand()%100,rand()%100,1));
//    map.addObject(new Character(rand()%100,rand()%100,2));
//    
//    for (int i=0; i<20; ++i) {
//        std::string fileName=std::to_string(i)+".xml";
//        std::ofstream ofs(fileName);
//        XMLNode node("Data");
//        node.addChild(map.getXML());
//        node.addChild((new XMLNode("Generation"))->addChild(new XMLTextNode(std::to_string(i+1))));
//        XMLGener gener(ofs);
//        gener.Generate(node);
//        map.evolution();
//    }
    return 0;
}
