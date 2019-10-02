#pragma once
#include <fstream>
#include <iostream>
#include <ostream>
#include "glut.h"
#include <string>
#ifdef IEDX_POLYTEX_EXPORTS
#define IEDX_POLYTEX __declspec(dllexport)
#else
#define IEDX_POLYTEX __declspec(dllimport)
#endif

extern "C" IEDX_POLYTEX void PolyTexLoader(const char * fname, int arr[10000]);
extern "C" IEDX_POLYTEX void Poly_texture(int  texturex[10][10]);
extern "C" IEDX_POLYTEX int x;
extern "C" IEDX_POLYTEX int arr_Size;
extern "C" IEDX_POLYTEX int example_texture[10][10];
extern "C" IEDX_POLYTEX void mtl_Loader(const char* fname, double r, double g, double b);