#include "Container.h"

void Container::fill(int n) { size = 10; }

void Container::consume(int n) { size -= n; }

int Container::getSize() { return size; }