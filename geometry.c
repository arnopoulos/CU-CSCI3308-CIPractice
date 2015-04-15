/*
 * geometry.c
 * Andy Sayler
 * CSCI 3308
 * Summer 2014
 *
 * This file contains a simple geomtery functions.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <errno.h>

#include "geometry.h"
#include "math.h"

#define FUZZY_EQ 0.01

#define DEBUG(file, line, func, msg) fprintf(stderr, "DEBUG - %s_%d_%s: %s", file, line, func, msg);

double minX(const coord_2d_t*a,const coord_2d_t*b,const coord_2d_t*c) {
	double min = a->x;
	if (min > b->x) min = b->x;
	if (min > c->x) min = c->x;
	return min;
}

double maxX(const coord_2d_t*a,const coord_2d_t*b,const coord_2d_t*c) {
	double max = a->x;
	if (max < b->x) max = b->x;
	if (max < c->x) max = c->x;
	return max;
}

double minY(const coord_2d_t*a,const coord_2d_t*b,const coord_2d_t*c) {
	double min = a->y;
	if (min > b->y) min = b->y;
	if (min > c->y) min = c->y;
	return min;
}

double maxY(const coord_2d_t*a,const coord_2d_t*b,const coord_2d_t*c) {
	double max = a->y;
	if (max < b->y) max = b->y;
	if (max < c->y) max = c->y;
	return max;
}

double delta(double d1, double d2){
	 return fabs(d1-d2);
}

double coord_2d_area_triangle(const coord_2d_t*a,const coord_2d_t*b,const coord_2d_t*c){
	double minx = minX(a,b,c);
	double maxx = maxX(a,b,c);
	double deltax = delta(maxx, minx);
	
	double miny = minY(a,b,c);
	double maxy = maxY(a,b,c);
	double deltay = delta(maxy, miny);
	
	double area = (deltax*deltay)/2.0;
	return area;
}



double coord_2d_dist(const coord_2d_t* a, const coord_2d_t* b){

    /* Input Checks */
    if(!a){
        DEBUG(__FILE__, __LINE__, __func__, "'a' must not be NULL");
        return NAN;
    }
    if(!b){
        DEBUG(__FILE__, __LINE__, __func__, "'b' must not be NULL");
        return NAN;
    }

    /* Maths */
    return sqrt(pow((a->x - b->x), 2) + pow((a->y - b->y), 2));

}

bool coord_2d_eq(const coord_2d_t* a, const coord_2d_t* b){

    /* Equal if dist <= FUZZY_EQ */
    if(coord_2d_dist(a, b) <= FUZZY_EQ){
        return true;
    }
    else{
        return false;
    }

}

void coord_2d_midpoint(coord_2d_t* mid, const coord_2d_t* a, const coord_2d_t* b){

    /* Input Checks */
    if(!mid){
        DEBUG(__FILE__, __LINE__, __func__, "'mid' must not be NULL");
        return;
    }
    if(!a){
        DEBUG(__FILE__, __LINE__, __func__, "'a' must not be NULL");
        return;
    }
    if(!b){
        DEBUG(__FILE__, __LINE__, __func__, "'b' must not be NULL");
        return;
    }

    /* Maths */
    mid->x = ((a->x + b->x) / 2.0 );
    mid->y = ((a->y + b->y) / 2.0 );

}
