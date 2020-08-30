#include <objc-avoid-nserror-init.h>

int main() {
  objc::avoid_nserror_init::check();

  return 0;
}