#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <emscripten.h>

// Number of circles to create and animate
#define NUM_CIRCLES 10

// Circle Struct
struct Circle
{
  int x;  // x coordinate
  int y;  // y coordinate
  int r;  // circle radius
  int cr; // color - RED
  int cg; // color - GREEN
  int cb; // color - BLUE
};
// Init circle data and start render - JavaScript
int main()
{
  printf("Init circles\n");
  emscripten_run_script("render()");
}

// Return circles to JavaScript
int get_circles()
{
  return 1;
}