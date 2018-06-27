#include "mars/listener/util/Color.h"

#define __RED     "\033[1;31m"
#define __GREEN   "\033[1;32m"
#define __YELLOW  "\033[1;33m"
#define __BLUE    "\033[1;34m"
#define __MAGENTA "\033[1;35m"
#define __CYAN    "\033[1;36m"
#define __WHITE   "\033[0m"

#define DEF_COLOR(color)                                     \
std::ostream& operator<<(std::ostream& os, const T_##color&) \
{                                                            \
    return os << __##color;                                  \
}

DEF_COLOR(WHITE)
DEF_COLOR(RED)
DEF_COLOR(GREEN)
DEF_COLOR(YELLOW)
DEF_COLOR(BLUE)
DEF_COLOR(MAGENTA)
DEF_COLOR(CYAN)
