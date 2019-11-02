#include <iostream>
#include "UtPod.h"
#include <time.h>
using namespace std;

UtPod::UtPod(){
    memSize = MAX_MEMORY;
    songs = NULL;
    srand(time(NULL));

}

UtPod::UtPod(int size){

    if(size >= MAX_MEMORY || size <= 0){
        memSize = MAX_MEMORY;
    }
    memSize = size;
    songs = NULL;

}

int UtPod::addSong(const Song &s) {

    if (s.getSize() <= getRemainingMemory()) {
        SongNode *temp = new SongNode;
        temp->s = s;
        temp->next = songs;                     //this->songs
        songs = temp;
        return SUCCESS;
    }
    else{
        return NO_MEMORY;
    }
}


int UtPod::removeSong(Song const &s){

    if(songs == NULL){
        return NOT_FOUND;
    }

    SongNode *ptr = songs;
    SongNode *ptr2 = NULL;
    while (ptr != NULL) {
        if (ptr->s == s) {
            if(ptr == songs){
                songs = ptr->next;
                cout << "Removed song " << s.getArtist() << " " << s.getTitle() << " " << s.getSize() << endl;
                return SUCCESS;
            }
            else {
                ptr2->next = ptr->next;
                delete (ptr);
                cout << "Removed song " << s.getArtist() << " " << s.getTitle() << " " << s.getSize() << endl;
                return SUCCESS;
            }

        } else {
            ptr2 = ptr;
            ptr = ptr->next;
        }
    }
    return NOT_FOUND;
}

void UtPod::shuffle(){

    SongNode *ptr = songs;
    int counter = -1;
    while (ptr != NULL) {
        counter += 1;
        ptr = ptr->next;
    }
    ptr = songs;
    SongNode *ptr2 = songs;
    for(int i = 0; i <= counter; i++){
        int r1 = rand() % counter;
        int r2 = rand() % counter;
        while(r1 != 0){
            ptr = ptr->next;
            r1--;
        }
        while(r2 != 0){
            ptr2 = ptr2->next;
            r2--;
        }
        Song temp = ptr->s;
        ptr->s = ptr2->s;
        ptr2->s = temp;

        ptr = songs;
        ptr2 = songs;
    }

}

void UtPod::showSongList() {
    cout << "Listing songs \n";
    SongNode *ptr = songs;
    while(ptr != NULL){
        cout << ptr->s.getArtist() << " " << ptr->s.getTitle() << " " << ptr->s.getSize() << endl;
        ptr = ptr->next;
    }

}

void UtPod::sortSongList(){
    cout << "Sorted songs \n";

    SongNode *smallest;

    for(smallest = songs; smallest != NULL; smallest = smallest->next ) {
        for (SongNode *p1 = smallest->next; p1 != NULL; p1 = p1->next) {
            if (p1->s < smallest->s) {
                Song temp = p1->s;
                p1->s = smallest->s;
                smallest->s = temp;
            }
        }
    }
}

void UtPod::clearMemory() {
    SongNode *ptr = songs;
    while(ptr != NULL) {
        songs = ptr->next;
        delete(ptr);
        ptr = songs;
    }
    cout << "Cleared UtPod \n";
}

int UtPod::getRemainingMemory() {
    int totMem = 0;
    SongNode *ptr = songs;
    while(ptr != NULL){
        totMem = totMem + ptr->s.getSize();
        ptr = ptr->next;
    }
    int mem = memSize - totMem;

    cout << "Remaining memory " << mem << endl;

    return mem;

}

UtPod::~UtPod() {
    clearMemory();
}




