/* Arbel Nathan 308366749 */
#include "Editor.h"

void Editor::loop(){
// p prints the current line (ed maintains a current line)
    regex p("p");
// n prints line number of current line followed by TAB followed by current line
    regex n("n");
// %p prints all lines
    regex prAll("%p");
// 7 makes line #7 the current line
    regex changeLine(R"(\d)");
// a appends new text after the current line
    regex a("a");
// i inserts new text before the current line
    regex i("i");
// c changes the current line for text that follows
    regex c("c");
// d deletes the current line
    regex d("d");
// /text searches forward after current line for the specified text. The search wraps to the
// beginning of the buffer and continues down to the current line, if necessary
    regex src(R"(/\w+)");
// s/old/new/ replaces old string with new in current line (google: C++ split or token)
    regex swc(R"(s/\w+/\w+/?)");
// Q Quits the editor without saving
    regex Q("Q");

    while(true){
        string work;
        getline(cin,work);
        if(regex_match(work, swc)){
            //cout<<"swc"<<endl;
                    string first=work.substr(2);
            int find1 =first.find("/");
            string one= first.substr(0,find1);
            int find2=first.rfind("/");
            string two;
            if(find2==find1) {
                two= first.substr(find1+1);
                //cout<<"in4"<<endl;
            }else{
                //cout<<first<<endl;
                two= first.substr((find1+1),find2-find1-1);
            }
            Doc->s(one,two);
          //  Doc->Q();
        }
        else if(regex_match(work, p)){
           // cout<<"p"<<endl;
          //  Doc->Q();
          Doc->p();
        }
         else if(regex_match(work, n)){
           // cout<<"n"<<endl;
          //  Doc->Q();
          Doc->n();
        }
         else if(regex_match(work, prAll)){
          //  cout<<"prAll"<<endl;
          //  Doc->Q();
          Doc->pAll();
        }
         else if(regex_match(work, changeLine)){
           // cout<<"changeLine"<<endl;
          //  Doc->Q();
          Doc->changeLine(stoi(work));//stoi string to int
        }
         else if(regex_match(work, a)){
          //  cout<<"a"<<endl;
         //   Doc->Q();
         Doc->a();
        }
         else if(regex_match(work, i)){
           // cout<<"i"<<endl;
          //  Doc->Q();
          Doc->i();
        }
         else if(regex_match(work, c)){
           // cout<<"c"<<endl;
          //  Doc->Q();
          Doc->c();
        }
         else if(regex_match(work, d)){
         //  cout<<"d"<<endl;
         //   Doc->Q();
         Doc->d();
        }
         else if(regex_match(work, src)){
          //  cout<<"src"<<endl;
         //   Doc->Q();
         string src=work.substr(1);
         Doc->search(src);
        }
         else if(regex_match(work,Q)){
         //   cout<<"Q"<<endl;
            Doc->Q();
        }
    }
}
