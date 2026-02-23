#ifndef CURLLIB_PLATFORM_H
#define CURLLIB_PLATFORM_H

#include <stddef.h>

typedef struct pal_socket pal_socket_t;

pal_socket_t *pal_connect(const char *host, int port, int timeout_ms);
int pal_send(pal_socket_t *sock, const void *buf, size_t len);
int pal_recv(pal_socket_t *sock, void *buf, size_t len);
int pal_close(pal_socket_t *sock);

int pal_time_ms(void);

void *pal_malloc(size_t n);
void *pal_realloc(void *ptr, size_t n);
void pal_free(void *ptr);

#endif // CURLLIB_PLATFORM_H