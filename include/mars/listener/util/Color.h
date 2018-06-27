#ifndef INCLUDE_MARS_LISTENER_UTIL_COLOR_H_
#define INCLUDE_MARS_LISTENER_UTIL_COLOR_H_

#include <ostream>

#define DECL_COLOR(color) \
const struct T_##color { \
    T_##color() {};       \
} color;                  \
std::ostream& operator<<(std::ostream&, const T_##color&);

DECL_COLOR(WHITE)
DECL_COLOR(RED)
DECL_COLOR(GREEN)
DECL_COLOR(YELLOW)
DECL_COLOR(BLUE)
DECL_COLOR(MAGENTA)
DECL_COLOR(CYAN)

#endif
