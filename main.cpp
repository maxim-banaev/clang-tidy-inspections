#include <iostream>

// Clang-Tidy via clangd
// https://youtrack.jetbrains.com/issue/CPP-12784
// https://clang.llvm.org/extra/clangd.html

// Current Status
//
// Many features could be implemented in Clangd. Here is a list of features that
// could be useful with the status of whether or not they are already
// implemented in Clangd and specified in the Language Server Protocol. Note
// that for some of the features, it is not clear whether or not they should be
// part of the Language Server Protocol, so those features might be eventually
// developed outside Clangd or as an extension to the protocol.
//
// C/C++ Editor feature LSP Clangd
// Formatting           Yes Yes
// Completion           Yes Yes
// Diagnostics          Yes Yes
// Fix-its              Yes Yes
// Go to Definition     Yes Yes
// Signature Help       Yes Yes
// Document Highlights  Yes Yes
// Rename               Yes Yes
// Source hover         Yes Yes
// Find References      Yes No
// Code Lens            Yes No
// Document Symbols     Yes No
// Workspace Symbols    Yes No
// Syntax and Semantic
// Coloring             No  No
// Code folding         No  No
// Call hierarchy       No  No
// Type hierarchy       No  No
// Organize Includes    No  No
// Quick Assist         No  No
// Extract Local
// Variable             No  No
// Extract
// Function/Method      No  No
// Hide Method          No  No
// Implement Method     No  No
// Gen. Getters/Setters No  No

// Registry flags:
// 1) Enable clangd - set clion.clang.clangd.on
// 2) Enable errors from clangd - set clion.clang.show.errors
// 3) Enable clangd as clang-tidy provider - set clion.clang.tidy.uses.clangd
// 4) To disable default error annotators - unset
// clion.default.annotators.enabled

// https://clang.llvm.org/extra/clang-tidy/checks/list.html

int main() {
  return 0;
}