#include<iostream>
using namespace std;

//defining the linked list as a structure
struct LinkedList{
int value;
LinkedList* next; // address of next node
};
// define the head globally for easy access across all functions
LinkedList* head = NULL;

//searches the list for a value, returns position
int search_node(int new_value){
int position=0;
if (head!=NULL){
LinkedList* current_node = head;
while(current_node !=NULL && current_node->value<new_value){
position++;
current_node = current_node->next;
}

}
return position;
}


//searches the list, returns last position, for appending
int get_last_index(){
int last_position=0;
if (head!=NULL){
LinkedList* current_node = head;
while(current_node!=NULL){
last_position++;
current_node = current_node->next;
}

}
return last_position;
}

// Appends a new node to the end of the linked list
void append_node(int new_value){
int position = get_last_index();
if(position==0){
//add new_node as first node
LinkedList* new_node = new LinkedList();
if (new_node !=NULL){
new_node->value = new_value;
new_node->next = head;
head = new_node;
}
}
else{
// append at the end
LinkedList* new_node = new LinkedList();
new_node->next = NULL; // point next address to NULL
new_node->value = new_value; // add new data to the created node

if(new_node!=NULL){
LinkedList* left_node = head;

// traverse list until insert position is found
int i=0;
while(i<position-1 && left_node!=NULL){
left_node = left_node->next;
i++;
}

// insert the new node and point its next address to the right node
if(left_node!=NULL){
LinkedList* right_node = left_node->next;
left_node->next = new_node;
new_node->next = right_node;
}

}

}
}

void insert_node(int new_position,int new_value){
int position = new_position-1; // convert position supplied by user to index eg 1 to 0
if(position==0){
//add new_node as first node
LinkedList* new_node = new LinkedList();
if (new_node !=NULL){
new_node->value = new_value;
new_node->next = head;
head = new_node;
}

}
else{
// insert at position
LinkedList* new_node = new LinkedList();
new_node->next = NULL;
new_node->value = new_value;
if(new_node!=NULL){
LinkedList* left_node = head;

int i=0;
while(i<position-1 && left_node!=NULL){
left_node = left_node->next;
i++;
}

if(left_node!=NULL){
LinkedList* right_node = left_node->next;
left_node->next = new_node;
new_node->next = right_node;
}
else{
printf("\nposition exceeds dimensions");
}

}

}
}

void delete_node(int value){
// get the position
int position = search_node(value);
// declare new nodes to track the left and right of the current node
LinkedList* delete_node = head;
LinkedList* left_node = head;
LinkedList* right_node = NULL;

int i = 0;
while(i<position && delete_node!=NULL){
left_node = delete_node;
delete_node = delete_node->next;
i++;
}

if(delete_node!=NULL){

if (delete_node == head){
head = delete_node->next;
}
else{
right_node = delete_node->next;
left_node->next = right_node;
}
}

}

// loops through the entire list and destroys the list
void destroy_list(){
LinkedList* temp_node;
while(head!=NULL){
temp_node = head;
head = head->next;
delete(temp_node);
}

}

//helper function to display the linked list when needed.
void show_list(){
if (head==NULL){
cout<<endl<<"list is empty";
}else{
LinkedList* current_node = head;
cout<<endl<<"Here is the updated linked list: ";
while(current_node !=NULL){
cout<<endl<<current_node->value;
current_node = current_node->next;
}
}
}
int main(){

int action;
int value;
int position;

do{
cout<<endl<<"Action:";
cout<<endl<<"1 - append";
cout<<endl<<"2 - insert";
cout<<endl<<"3 - delete";
cout<<endl<<"4 - search";
cout<<endl<<"5 - quit";
cout<<endl<<"Enter action: "; cin>>action;

switch (action){
case(1):
cout<<endl<<"enter value to append to the linked list: ";cin>>value;
append_node(value);
show_list();
break;
case(2):

cout<<endl<<"enter value to insert: ";cin>>value;
cout<<endl<<"enter position [starts from 1]: ";cin>>position;
insert_node(position,value);
show_list();
break;
case(3):
cout<<endl<<"enter value of the node to delete: ";cin>>value;
delete_node(value);
show_list();
break;
case(4):
cout<<endl<<"enter value of node to search: ";cin>>value;
position = search_node(value);
cout<<"Number found at index "<<position;
break;
case(5):
destroy_list();
exit(0);
break;
default:
cout<<endl<<"Unknown input";
break;
}

}while(action!=5);

}
