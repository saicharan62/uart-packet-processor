#include <iostream>
#include "circular_buffer.h"

using namespace std;

CircularBuffer::CircularBuffer() {
    index = 0;
    count = 0;
    start = 0;

    for(int i = 0; i < SIZE; i++){
        buffer[i] = 0;
    }
}

void CircularBuffer::add(int value){
    buffer[index] = value;

    if(count == SIZE){
        start = (start + 1) % SIZE;
    } else {
        count++;
    }

    index = (index + 1) % SIZE;
}

void CircularBuffer::display(){
    for(int i = 0; i < count; i++){
        int idx = (start + i) % SIZE;
        cout << buffer[idx] << " ";
    }
    cout << endl;
}