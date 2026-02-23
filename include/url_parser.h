#ifndef CURLLIB_URL_PARSER_H
#define CURLLIB_URL_PARSER_H

typedef struct {
  char *scheme;
  char *host;
  int port;
  char *path;
  int is_https;
} url_parsed_t;

int url_parse(const char *url, url_parsed_t *out);

void url_parsed_free(url_parsed_t *parsed);

#endif // CURLIB_URL_PARSER_H