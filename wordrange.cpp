#include <iostream>
#include <stack>
#include <fstream>
#include <array>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include "avl.h"

int main(int argc, char** argv){
  if (argc<3){throw std::invalid_argument("wrong syntex buddy");}

  ifstream infile;
  ofstream outfile;
  infile.open(argv[1]);
  outfile.open(argv[2]);
  string commandMe;
  char*buffer, *op, *holder1, *holder2=NULL;
  string val1;
  string val2;
  int counter;
  AVL myTree;
  while(getline(infile, commandMe)){
    if (commandMe.size()==0) continue;

    buffer = strdup(commandMe.c_str());
    op = strtok(buffer, " \t");
    holder1 = strtok(NULL, " \t");
    if(holder1!=NULL) val1 = holder1;
  
    holder2 = strtok(NULL, "\t");
    if(holder2!=NULL) val2 = holder2;
    if(!strcmp(op, "i")){
      // cout<<"inserting "+val1<<endl;
      myTree.root = myTree.insert(myTree.root, val1);
    }
    else if(!strcmp(op, "r")){
      // cout<<"searching between "+val1+" "+val2<<endl;
      // cout<<"searching brodie"<<endl;
      counter = 0;
      counter = myTree.search(val1, val2, myTree.root);
      // cout<<counter<<endl;
      outfile<< to_string(counter) <<endl;
    }
    else if(!strcmp(op, "p")){
      cout<<"Preorder print"<<endl;
      myTree.Preorder(myTree.root);
    }
  }
  infile.close();
  outfile.close();
}

