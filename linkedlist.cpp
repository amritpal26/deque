#include "Deque.h"
#include <iomanip>
#include <iostream>
using namespace std;


	Deque::Deque(){
		left_p = NULL;
    	right_p = NULL;
    	current_size = 0;
    	cursor = NULL;
	}

	// Copy Constructor
    Deque( const Deque& dq ){
    	left_p = dq->data;
    	right_p = dq->next;
    	current_size = dq->current_size;
    	cursor = dq->cursor;
    }

    // Destructor
    ~Deque(){
    	if(current_size != 0){
    		cursor = current_left;
    		while(size != 0){
    			node* temp = cursor;
    			cursor = cursor->next;
    			delete temp;
    			current_size--;
    		}
    	}
    }

    /* Insertion operators */
    // Inserts <item> at left end.
    void push_left( int item ){
    	if (current_size != 0){
    		node * newLeft = new node(item, NULL, p_left);
    		current_size++;
    	}

    	else {
    		node * newLeft = new node(item, NULL, NULL);
    		cursor = newLeft;
    		right_p = newLeft;
    		left_p = newLeft;
    		current_size++;
    	}
    }

    // Inserts <item> at right end.
    void push_right( int item ){
    	if (current_size != 0){
    		node * newRight = new node(item, right_p, NULL);
    		current_size++;
    	}
    	else{
    		node * newRight = new node(item, NULL, NULL);
    		cursor = newRight;
    		left_p = newRight;
    		right_p = newRight;
    		current_size++;
    	}
    } 

    /* Removal operators */
    // Pre: Deque is not empty.
    // removes and returns item on left end.
    // Pre: Deque is not empty.
    int pop_left(){
    	if(current_size >= 1){
    		node * temp = left_p;
    		if(cursor == left_p){
    			cursor = left_p->next;
    		}
    		int tempInt->data = left_p->data;
    		left_p = temp->next;
    		current_size--;
    		delete temp;
    		return tempInt;
    	}
    	else if(current_size == 1){
    		node * temp = left_p;
    		int tempInt->data = left_p->data;
    		left_p = NULL;
    		right_p = NULL;
    		cursor = NULL;
    		current_size = 0;
    		delete temp;
    		return tempInt;
    	}
    } 

     // removes and returns item on right end.
    int pop_right(){
    	if(current_size >= 1){
    		node * temp = right_p;
    		if(cursor == right_p){
    			cursor = right_p->prev;
    		}
    		int tempInt->data = right_p->data;
    		right_p = temp->prev;
    		current_size--;
    		delete temp;
    		return tempInt;
		}
    	else if(current_size == 1){
    		node * temp = left_p;
    		int tempInt->data = left_p->data;
    		left_p = NULL;
    		right_p = NULL;
    		cursor = NULL;
    		current_size = 0;
    		delete temp;
    		return tempInt;
    	}
    }

    /* Size functions */
    // Returns true iff the Deque contains no items.
    bool empty() {
    	return (current_size == 0);
    } 
    // Returns the current number of items in the deque.
    int size(){
    	return current_size;
    }  

    /* Cursor movement operators
    *  These move the cursor one node to the left or right and then 
    *  return true if such a move is possible.  If the move is not 
    *  possible (i.e., the cursor is already at the extreme end
    *  or the Deque is emty), no change occurs and false is returned. 
    */
    // Move cursor left.
    bool cursor_left(){
    	if (current_size == 0 || current_size == 1){
    		return false;
    	}
    	else if(cursor == left_p) {
    		return false;
    	}
    	else{
    		cursor = cursor->prev;
    		return true;
    	}
    }

    // Move cursor right.
    bool cursor_right(){
    	if(current_size == 0 || current_size == 1){
    		return false;
    	}
    	else if(cursor == right_p){
    		return false;
    	}
    	else{
    		cursor = cursor->next;
    		return true;
    	}
    }

    /* Accessor functions */
    // Pre: Deque is not empty.
    // Returns the left-most item without removing it.
    int peek_left(){
    	return left_p->data;
    } 
    
    // Returns the right-most item without removing it.
    // Pre: Deque is not empty.
    int peek_right(){
    	return right_p->data;
    } 
     
    // Return value the cursor currently is at, 
    // Pre: Deque is not empty.   
    int get_cursor(){
    	return cursor->data;
    }

    // Pre: Deque is not empty.
    void set_cursor(int i){
    	cursor->data = i;
    }    

    /* Utility functions */
    // prints a depiction of the deque contents to standard output.    
    void display(){
    	node * current = left_p;
    	for (int i = 0; i < current_size; i++){
    		cout << current->data << " ";
    		current = current->next;
    	}
    }

    // like display, but includes node addresses and pointer values.
    void verbose_display(){
    	node * current = left_p;
    	cout << setw(15) << "Node address" << setw(15) << "Pointer Values" << endl;
    	for (int i = 0; i < current_size; i++){
    		cout << setw(15) << current << set w(15) << current->data << endl;
    		current = current->next;
    	}
    }