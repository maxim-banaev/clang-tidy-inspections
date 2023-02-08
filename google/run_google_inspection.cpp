#include <google-default-arguments.h>
#include <google-explicit-constructor.h>
#include <google-readability-casting.h>
#include <google-readability-namespace-comments.h>

int main() {
  google::default_arguments::check();
  google::explicit_constructor::check();
  google::readability_casting::check();
  google::readability_namespace_comments::check();
  return 0;
}