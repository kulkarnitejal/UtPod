#include <iostream>
#include "UTPod.h"
using namespace std;

UtPod::UtPod(){
    memSize = MAX_MEMORY;
    songs = nullptr;
}

UtPod::UtPod(int size){
    memSize = size;
    if(size >= MAX_MEMORY || size <= 0){
        memSize = MAX_MEMORY;
    }
    songs = nullptr;
}

int UtPod::addSong(const Song &s) {

        //add check for remaining memory
        SongNode *temp = new SongNode;
        temp->s = s;
        temp->next = songs;
        songs = temp;
        //Maybe have to free temp idk yet
        return SUCCESS;

}


int UtPod::removeSong(Song const &s){

    SongNode *ptr = songs;
    SongNode *ptr2;
    while (ptr != nullptr) {
        if (ptr->s == s) {
            ptr2 = ptr->next;
            if (ptr2 == nullptr) {
                ptr = ptr2;
            } else {
                ptr->next = ptr2->next;
            }
            
            return SUCCESS;

        } else {
            ptr = ptr->next;
        }
    }
    return NOT_FOUND;
}

UtPod::~UtPod() {
    cout << "In the destructor for something" << endl;
}
//int getRemainingMemory(Song &songs){
//
//
//}




