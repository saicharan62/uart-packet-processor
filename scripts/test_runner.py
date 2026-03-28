import os

os.system("python3 scripts/packet_generator.py data/sample_packets.txt 20")
os.system("./processor data/sample_packets.txt 80")