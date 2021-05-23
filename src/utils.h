#ifndef UTILS_HEADER
#define UTILS_HEADER

#include <sys/time.h>

#define CLOSE_FD(fd) \
  if (fd > 0)        \
  {                  \
    close(fd);       \
  }

#define CLOSE_FP(fp) \
  if (fp != NULL)    \
  {                  \
    fclose(fp);      \
  }

int equalStr(const char *, const char *);
void format_result(char *);
void log_config();
long tv_to_ms(const struct timeval *tv);
long tv_to_us(const struct timeval *tv);
int write_file(const char *, const char *);

#endif
