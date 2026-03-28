#include "fault_detector.h"

bool isCorrupted(int id, int value, int checksum){
    return checksum != (id + value) % 2;
}

bool isInvalid(int value){
    return value < 0;
}

bool isAlert(int value, int threshold){
    return value > threshold;
}