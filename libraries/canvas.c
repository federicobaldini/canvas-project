#include <stdio.h>
#include <emscripten.h>

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