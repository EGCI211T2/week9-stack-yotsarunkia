
#ifndef stack_h
#define stack_h
#include "node.h"
#include<iostream>
class Stack {
	NodePtr top;
	int size;
public:
    void push(int);
    int pop();
    Stack();
    ~Stack();
};


void Stack::push(int x){
  NodePtr new_node=new NODE(x);
  if(new_node){
    new_node -> set_next(top);
    top=new_node;
    size++;
   }  
}

int Stack::pop(){
    if (top==nullptr) 
    {
        return -1;
    }
        NodePtr t=top;
        int value;
        value=t->get_value();
        top=top->get_next();
    // Left missing part for exercises
        size--;    
        delete t;
        return value;
        
	//be careful of the empty stack!!!
    }

Stack::Stack(){
    //initialize stack
    top=NULL;
    size=0;
}
Stack::~Stack(){
    //delete all remaning stack (i.e. pop all) 
    while(top!=NULL)
    {
        NodePtr temp=top;
        top = top->get_next();
        delete temp;
    }
    size=0;
}


#endif
