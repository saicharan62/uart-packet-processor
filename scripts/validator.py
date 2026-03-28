import sys


def load_packets(file_path):
    packets = []
    with open(file_path, "r") as f:
        for line in f:
            parts = line.strip().split()
            if len(parts) != 3:
                continue
            packet_id = int(parts[0])
            value = int(parts[1])
            checksum = int(parts[2])
            packets.append((packet_id, value, checksum))
    return packets


def compute_expected(packets, threshold):
    corrupted = []
    invalid = []
    alerts = []

    for pid, value, checksum in packets:
        if checksum != (pid + value) % 2:
            corrupted.append(pid)

        if value < 0:
            invalid.append(value)

        if value > threshold:
            alerts.append(value)

    return corrupted, invalid, alerts


def main():
    if len(sys.argv) < 3:
        print("Usage: python3 validator.py <file> <threshold>")
        sys.exit(1)

    file_path = sys.argv[1]
    threshold = int(sys.argv[2])

    packets = load_packets(file_path)
    corrupted, invalid, alerts = compute_expected(packets, threshold)

    print("Expected Corrupted Packet IDs:", corrupted)
    print("Expected Invalid Values:", invalid)
    print("Expected Alerts:", alerts)


if __name__ == "__main__":
    main()