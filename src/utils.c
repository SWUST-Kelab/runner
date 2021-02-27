#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <limits.h>

#include "constants.h"
#include "utils.h"

void close_fd(int fd)
{
  if (fd > 0)
  {
    close(fd);
  }
}

int equalStr(const char *s, const char *s2)
{
  while (*s && *s2)
  {
    if (*s++ != *s2++)
    {
      return 1;
    }
  }

  return 0;
}

void format_result(char *message, struct Result *_result)
{
  sprintf(message, "{\n"
                   "  \"status\": %d,\n"
                   "  \"cpu_time_used\": %d,\n"
                   "  \"cpu_time_used_us\": %ld,\n"
                   "  \"real_time_used\": %d,\n"
                   "  \"real_time_used_us\": %ld,\n"
                   "  \"memory_used\": %d,\n"
                   "  \"signal\": %d,\n"
                   "  \"exit_code\": %d\n"
                   "}",
          _result->status,
          _result->cpu_time_used,
          _result->cpu_time_used_us,
          _result->real_time_used,
          _result->real_time_used_us,
          _result->memory_used,
          _result->signal,
          _result->exit_code);
}

long tv_to_ms(const struct timeval *tv)
{
  return (tv->tv_sec * 1000) + ((tv->tv_usec + 500) / 1000);
}

long tv_to_us(const struct timeval *tv)
{
  return (tv->tv_sec * 1000 * 1000) + tv->tv_usec;
}
