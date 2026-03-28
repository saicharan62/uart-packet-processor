#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

class CircularBuffer {
private:
    static const int SIZE = 5;
    int buffer[SIZE];
    int index = 0;
    int count = 0;
    int start = 0;    
public:
    CircularBuffer();
    void add(int value);
    void display();
};

#endif