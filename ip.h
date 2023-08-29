#pragma once

#include <string.h>
#include <stddef.h>
#include <stddef.h>


#define IP_VERSION_IPV4 4

#define IP_HDR_SIZE_MIN 20
#define IP_HDR_SIZE_MAX 60

#define IP_TOTAL_SIZE_MAX UINT16_MAX
#define IP_PAYLOAD_SIZE_MAX (IP_TOTAL_SIZE_MAX - IP_HDR_SIZE_MIN)

#define IP_ADDR_LEN 4
#define IP_ADDR_STR_LEN (IP_ADDR_LEN * 4)

typedef uint32_t ip_addr_t;

extern const ip_addr_t IP_ADDR_ANY;
extern const ip_addr_t IP_ADDR_BROADCAST;

extern int
ip_addr_pton(const char *p, ip_addr_t *n);
extern char *
ip_addr_ntop(const ip_addr_t n, char *p, size_t size);

extern int ip_init(void);

struct ip_iface {
    struct net_iface iface;
    struct ip_iface *next;
    ip_addr_t unicast;
    ip_addr_t netmask;
    ip_addr_t broadcast;
};

extern struct ip_iface *
ip_iface_alloc(const char *unicast, const char *netmask);
extern int
ip_iface_register(struct net_device *dev, struct ip_iface *iface);