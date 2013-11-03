#include <stdio.h>

#define CONCAT(S1,C,S2) ({ \
    static const struct __attribute__ ((packed)) { \
      char s1[sizeof (S1) - 1]; \
      char c; \
      char s2[sizeof (S2)]; \
    } _r = { (S1), (C), (S2) }; \
    (const char *) &_r; \
})
struct s
{
    int   x;
    float y;
    char  *z;
};

struct s pi = { .z = "Pi", .x = 3, .y = 3.1415 };
int
main (void)
{
  puts (CONCAT ("abc", 'd', "efg"));
  printf(__FILE__ ": %d: Hello "
           "world\n", __LINE__);
  return 0;
} 

