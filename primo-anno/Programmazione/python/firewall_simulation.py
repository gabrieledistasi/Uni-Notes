import random

def generate_random_IP(): 
    return f"192.168.1.{random.randint(0,20)}"

def check_firewall_rules(ip, rules): 
    for rule_ip, action in rules.items(): 
        if ip == rule_ip: 
            return action
    return "allow"


def main(): 
    firewall_rules = {
        "192.168.1.1" : "block", 
        "192.168.1.4" : "block",
        "192.168.1.9" : "block",
        "192.168.1.13" : "block",
        "192.168.1.16" : "block",
        "192.168.1.19" : "block"
    }

    for _ in range(12): 
        ip_address = generate_random_IP()
        action = check_firewall_rules(ip_address, firewall_rules)
        random_num = random.randint(0, 9999)
        print(f"IP: {ip_address}, Action: {action}, Random: {random_num}")

if __name__ == "__name__": 
    main()

print(main())
