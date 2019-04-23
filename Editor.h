/* Arbel Nathan 308366749 */
#include <iostream>
#include <string>
#include <vector>
#include "Document.h"
#include <regex>
using namespace std;


class Editor{
private:

    Documents* Doc;
    
public:
    Editor(){Doc=new Documents();}
    void loop();

};

