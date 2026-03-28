# UART Packet Stream Processor & Fault Detector (C++ & Python)

## Overview
This project simulates a UART-like serial data stream and implements a modular C++ system to process, validate, and analyze incoming packets in real time.

It is designed to reflect core embedded systems and testing workflows, including packet parsing, checksum validation, fault detection, and automated test generation.

---

## Features

- Structured packet processing (ID, payload, checksum)
- Checksum validation for data integrity
- Fault detection:
  - Corrupted packets
  - Invalid values
  - Threshold-based alerts
- Circular buffer for fixed-size sliding window storage
- Modular C++ design with separation of concerns
- Python-based test generation and validation

---

## Project Structure
.
├── src/
│ ├── main.cpp
│ ├── circular_buffer.cpp / .h
│ ├── packet_parser.cpp / .h
│ ├── fault_detector.cpp / .h
├── scripts/
│ ├── packet_generator.py
│ ├── validator.py
│ └── test_runner.py
├── data/
│ └── sample_packets.txt
├── logs/
│ └── output.txt
├── build/
├── README.md
└── .gitignore


---

## How It Works

1. Python script generates packet data simulating a UART stream  
2. Each packet contains: `id value checksum`  
3. C++ processor:
   - Parses packets
   - Validates checksum
   - Detects faults
   - Stores recent data in circular buffer  
4. Logs anomalies and prints alerts  
5. Validator script verifies correctness of system behavior  

---

## Build & Run

### Compile
g++ src/main.cpp src/circular_buffer.cpp src/packet_parser.cpp src/fault_detector.cpp -o processor

### Generate Packets


python3 scripts/packet_generator.py data/sample_packets.txt 50


### Run Processor


./processor data/sample_packets.txt 80


### Validate Results


python3 scripts/validator.py data/sample_packets.txt 80


---

## Example Packet


1 45 0
2 90 1
3 -10 1


---

## Key Concepts Demonstrated

- Packet-based data processing (UART-style simulation)
- Data integrity validation (checksum)
- Fault detection in streaming systems
- Circular buffer memory management
- Modular C++ architecture
- Test automation using Python

---

## Author

Sai Charan K