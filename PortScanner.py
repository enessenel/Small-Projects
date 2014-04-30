import socket


def connect_to_ip(ip, port):
	
    try:
    
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	sock.connect((ip, port))
       
	return sock

    except:

    	return None

def scan_ports(ip, port):

    sock = connect_to_ip(ip, port)
    socket.setdefaulttimeout(5)

    if sock:
        
	print("Able to connect to: %s:%d"%(ip, port))
	sock.close() 

    else:

        print("Not able to connect to: %s:%d"%(ip, port))
        
        
ip_domain = raw_input("Enter the ip or domain: ")
port = raw_input("Enter the port range: ")
port_range = port.split("-")

ip=socket.gethostbyname(ip_domain) #get ip if the host name is a domain

for i in range(int(port_range[0]), int(port_range[1])):
    scan_ports(ip, int(i))

