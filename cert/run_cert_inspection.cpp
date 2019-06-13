//
// Created by Maxim.Banaev on 6/13/2019.
//
#include <cert-dcl50-cpp.h>
#include <cert-dcl58-cpp.h>
#include <cert-err52-cpp.h>
#include <cert-dcl16-c.h>

int main() {
  cert::dcl50_cpp::check();
  cert::dcl58_cpp::check();
  cert::err52_cpp::check();
  cert::dcl16_c::check();

  return 0;
}
