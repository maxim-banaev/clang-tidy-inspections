#include <google-default-arguments.h>
#include <google-explicit-constructor.h>
int main() {
  google::default_arguments::check();
  google::explicit_constructor::check();

  return 0;
}