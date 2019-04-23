/* Arbel Nathan 308366749 */
#include "Document.h"

// p prints the current line (ed maintains a current line)
    void Documents::p(){
        cout<<full.at(currentLine)<<endl;
    }
// n prints line number of current line followed by TAB followed by current line
    void Documents::n(){
        cout<<(currentLine+1)<<"\t"<<full.at(currentLine)<<endl;
    }
// %p prints all lines
    void Documents::pAll(){

        for(string st: full){
            cout<<st<<endl;
        }

    }

// 7 makes line #7 the current line
    void Documents::changeLine(int line){
        if(line>full.size()||line<=0){
            cout<<"?"<<endl;
            Q();
        }
        currentLine=(line-1);
        cout<<full.at(currentLine)<<endl;
    }
// a appends new text after the current line
    void Documents::a(){
       if(currentLine==-1){
           string temp;
           //need lines and with empty lines;
           getline(cin,temp);
           if(temp.compare(".")){
               full.push_back(temp);
               currentLine=0;
           }
       }
        std::vector<string>::iterator it;
        
        while(true){
            it=full.begin()+(currentLine+1);
            string temp;
           //need lines and with empty lines;
            getline(cin,temp);
            if(!temp.compare(".")) break;
            full.insert(it,temp);
            currentLine++;
          //  pAll();
        }
        
    }
// i inserts new text before the current line
    void Documents::i(){
        if(currentLine==-1){
           string temp;
           //need lines and with empty lines;
           getline(cin,temp);
           if(temp.compare(".")){
               full.push_back(temp);
               currentLine=0;
           }
       }
        std::vector<string>::iterator it;
        
        while(true){
            it=full.begin()+(currentLine);
            string temp;
           //need lines and with empty lines;
            getline(cin,temp);
            if(!temp.compare(".")) break;
            full.insert(it++,temp);
            currentLine++;
        }
    }
// c changes the current line for text that follows
    void Documents::c(){
        d();
        std::vector<string>::iterator it;
        
        while(true){
            it=full.begin()+(currentLine+1);
            string temp;
           //need lines and with empty lines;
            getline(cin,temp);
            if(!temp.compare(".")) break;
            full.insert(it,temp);
            currentLine++;
        }

    }
// d deletes the current line
    void Documents::d(){
        //cout<<full.at(currentLine)<<" del"<<endl;
        full.erase((full.begin()+(currentLine)));
        currentLine--;  
    }
// /text searches forward after current line for the specified text. The search wraps to the
// beginning of the buffer and continues down to the current line, if necessary
    void Documents::search(string find){
        for(int i =0; i<=currentLine ; i++)
        {
            if(full.at(i).find(find)!=string::npos){
                currentLine=i;
            }
        }
        cout<<full.at(currentLine)<<endl;
        
    }
// s/old/new/ replaces old string with new in current line (google: C++ split or token)
    void Documents::s(string s_old, string s_new){
        int check= full.at(currentLine).find(s_old);
        if(check!=-1){
            full.at(currentLine).replace(check,s_old.size(),s_new);
        }
        else{
            cout<<"?"<<endl;
            Q();
        }
    }
// Q
// Quits the editor without saving
    void Documents::Q(){
        exit(0);
    }

    