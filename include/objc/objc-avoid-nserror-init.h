#ifndef OBJC_AVOID_NSERROR_INIT_H
#define OBJC_AVOID_NSERROR_INIT_H

#include <iostream>

namespace objc::avoid_nserror_init {
void check() {
  std::cout << "-- check objc-avoid-nserror-init [turn off by default]";
}
} // namespace objc::avoid_nserror_init

#endif // OBJC_AVOID_NSERROR_INIT_H
