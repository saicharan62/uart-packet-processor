#ifndef FAULT_DETECTOR_H
#define FAULT_DETECTOR_H

bool isCorrupted(int id, int value, int checksum);
bool isInvalid(int value);
bool isAlert(int value, int threshold);

#endif