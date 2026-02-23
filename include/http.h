#ifndef CURLLIB_HTTP_H
#define CURLLIB_HTTP_H

#include <stddef.h>

typedef enum {
  HTTP_OK = 0,
  HTTP_ERR_INVALID_ARG,
  HTTP_ERR_CONNECT,
  HTTP_ERR_TLS,
  HTTP_ERR_SEND,
  HTTP_ERR_RECV,
  HTTP_ERR_TIMEOUT,
  HTTP_ERR_REDIRECT,
  HTTP_ERR_TOO_MANY_REDIRECTS,
  HTTP_ERR_BAD_RESPONSE,
  HTTP_ERR_OUT_OF_MEMORY
} http_err_t;

typedef enum { HTTP_GET, HTTP_POST } http_method_t;

typedef struct http_header {
  char *name;
  char *value;
  struct http_header *next;
} http_header_t;

typedef struct {
  http_method_t method;
  const char *url;
  http_header_t *headers;
  const void *body;
  size_t body_len;
  int timeout_ms;
  int verify_cert;
  int max_redirects;
} http_request_t;

typedef struct {
  int status;
  http_header_t *headers;
  void *body;
  size_t body_len;
} http_response_t;

http_err_t http_request(const http_request_t *req, http_response_t *resp);
void http_response_free(http_response_t *resp);

http_err_t http_add_header(http_request_t *req, const char *name,
                           const char *value);
void http_free_headers(http_request_t *req);

const char *http_err_str(http_err_t err);

#endif // CURLLIB_HTTP_H