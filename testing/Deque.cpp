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

    // Copy Constructor (Deep Copy)
    Deque::Deque(const Deque& dq ){
        int dq_size = dq.current_size;
        node * temp_dq = dq.left_p;

        left_p = NULL;
        right_p = NULL;
        cursor = NULL;
        current_size = 0;
  
        if (dq.current_size != 0){
            left_p = new node(dq.left_p->data, NULL, NULL);
            node * temp_cursor = left_p;
            current_size++;
            if (dq.cursor == dq.left_p){
                cursor = left_p;
            }
            temp_dq = dq.left_p->next;


            for (int i = 0; i < dq_size - 1; i++){
                node * temp = new node(temp_dq->data, temp_cursor, NULL);
                temp_cursor->next = temp;
                if (temp_dq == dq.cursor){
                    cursor = temp;
                }
                
                temp_dq = temp_dq->next;
                temp_cursor = temp;
                current_size++;
            }

            right_p = temp_cursor;
            delete temp_cursor;
            delete temp_dq;
        }
    }
    

    // Destructor
    Deque::~Deque(){
        if(current_size != 0){
            cursor = left_p;
            while(current_size != 0){
                node* temp = cursor;
                cursor = cursor->next;
                delete temp;
                current_size--;
            }
            cursor = NULL;
            left_p = NULL;
            right_p = NULL;
            current_size = 0;
        }
    }

    /* Insertion operators */
    // Inserts <item> at left end.
    void Deque::push_left( int item ){
        if (current_size != 0){
            node * newLeft = new node(item, NULL, left_p);
            left_p->prev = newLeft;
            left_p = newLeft;
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
    void Deque::push_right( int item ){
        if (current_size != 0){
            node * newRight = new node(item, right_p, NULL);
            right_p->next = newRight;
            right_p = newRight;
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
    int Deque::pop_left(){
        if(current_size > 1){
            node * temp = left_p;
            int tempInt = left_p->data;
            if(cursor == left_p){
                cursor = left_p->next;
            }
            left_p = temp->next;
            current_size--;
            delete temp;
            return tempInt;
        }
        else if(current_size == 1){
            node * temp = left_p;
            int tempInt = left_p->data;
            left_p = NULL;
            right_p = NULL;
            cursor = NULL;
            current_size = 0;
            delete temp;
            return tempInt;
        }
    } 

     // removes and returns item on right end.
    int Deque::pop_right(){
        if(current_size > 1){
            node * temp = right_p;
            int tempInt= right_p->data;
            if(cursor == right_p){
                cursor = right_p->prev;
            }     
            right_p = temp->prev;
            current_size--;
            delete temp;
            return tempInt;
        }
        else if(current_size == 1){
            node * temp = right_p;
            int tempInt= right_p->data;
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
    bool Deque::empty() {
        return (current_size == 0);
    } 
    // Returns the current number of items in the deque.
    int Deque::size(){
        return current_size;
    }  

    /* Cursor movement operators
    *  These move the cursor one node to the left or right and then 
    *  return true if such a move is possible.  If the move is not 
    *  possible (i.e., the cursor is already at the extreme end
    *  or the Deque is emty), no change occurs and false is returned. 
    */
    // Move cursor left.
    bool Deque::cursor_left(){
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
    bool Deque::cursor_right(){
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
    int Deque::peek_left(){
        return left_p->data;
    } 
    
    // Returns the right-most item without removing it.
    // Pre: Deque is not empty.
    int Deque::peek_right(){
        return right_p->data;
    } 
     
    // Return value the cursor currently is at, 
    // Pre: Deque is not empty.   
    int Deque::get_cursor(){
        return cursor->data;
    }

    // Pre: Deque is not empty.
    void Deque::set_cursor(int i){
        cursor->data = i;
    }    

    /* Utility functions */
    // prints a depiction of the deque contents to standard output.    
    void Deque::display(){

        node * current = left_p;
        if (current != NULL){ 
            int i = 0;
            cout << "[";
            while ((current != NULL) && (i < current_size)){
            cout << current->data << ";";
            current = current->next;
            i++;
            }
            cout << "] size=" << current_size << ", cursor=" << cursor->data << "." << endl;
        }
        if (current_size == 0){
            cout << "[] size=0, cursor=NULL.\n"; 
        }        
    }

    // like display, but includes node addresses and pointer values.
    void Deque::verbose_display(){
        node * current = left_p;
        cout << setw(15) << "Node address" << setw(15) << "Pointer Values" << endl;
        for (int i = 0; i < current_size; i++){
            cout << setw(15) << current << setw(15) << current->data << endl;
            current = current->next;
        }
    }
