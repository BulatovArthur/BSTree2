#include <iostream>
#include "bstree.hpp"

using namespace std;
using namespace BSTree;

int main(int argc, char *argv[]) {
  Tree *tr = new Tree;
  for (int i = 1; i < argc; i++) tr->Insert(atoi(argv[i]));
  delete tr;
  return 0;
}
