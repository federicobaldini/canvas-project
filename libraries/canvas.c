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

// Circle Animation Data Struct
struct CircleAnimationData
{
  int x;  // x coordinate
  int y;  // y coordinate
  int r;  // circle radius
  int xv; // x - axis velocity
  int yv; // y - axis velocity
  int xd; // x - axis direction (1 = forward, 0 = backward)
  int yd; // y - axis direction (1 = forward, 0 = backward)
};

// Circles variable
struct Circle circles[NUM_CIRCLES];
struct CircleAnimationData animation_data[NUM_CIRCLES];

// Random number generator
int get_random_number(int min, int max)
{
  return (rand() % max) + min;
}

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