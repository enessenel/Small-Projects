import socket
import sys


def connect_to_ip(ip, port):
    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.connect((ip, port))
        return sock

    except Exception:
        return None


def scan_port(ip, port, timeout):
    socket.setdefaulttimeout(timeout)
    sock = connect_to_ip(ip, port)

    if sock:
        print("Able to connect to: %s:%d" % (ip, port))
        sock.close()
    else:
        print("Not able to connect to: %s:%d" % (ip, port))


# Get user input
ip_domain = raw_input("Enter the ip or domain: ")
port = raw_input("Enter the port range (Ex 20-80): ")
timeout = raw_input("Timeout (Default=5): ")
if not timeout:
    timeout = 5

port_range = port.split("-")

# Get the IP address if the host name is a domain
try:
    ip = socket.gethostbyname(ip_domain)
except Exception:
    print 'There was an error resolving the domain'
    sys.exit(1)

for port in range(int(port_range[0]), int(port_range[1])):
    scan_port(ip, int(port), int(timeout))