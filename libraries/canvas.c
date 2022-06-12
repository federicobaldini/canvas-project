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
  // Seed random number generator
  srand(time(NULL));

  // Create circles
  for (int i = 0; i < NUM_CIRCLES; i++)
  {
    // Radius
    int radius = get_random_number(10, 50);

    // Coordinates
    int x = get_random_number(0, 400) + radius;
    int y = get_random_number(0, 400) + radius;

    // Fill circle struct - i
    circles[i].x = x;
    circles[i].y = y;
    circles[i].r = radius;
    circles[i].cr = get_random_number(0, 255);
    circles[i].cg = get_random_number(0, 255);
    circles[i].cb = get_random_number(0, 255);

    // Fill animation data struct - i
    animation_data[i].x = x;
    animation_data[i].y = y;
    animation_data[i].r = radius;
    animation_data[i].xv = get_random_number(1, 4);
    animation_data[i].yv = get_random_number(1, 4);
    animation_data[i].xd = 1;
    animation_data[i].yd = 1;
  }
  // Start JavaScript rendering
  EM_ASM({ render($0, $1); }, NUM_CIRCLES * 6, 6);
}

// Return circles to JavaScript
struct Circle *get_circles(int canvas_width, int canvas_height)
{
  // Update circles data
  return circles;
}
