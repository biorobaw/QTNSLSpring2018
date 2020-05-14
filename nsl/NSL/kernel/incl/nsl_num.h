#ifndef _NSL_NUM_H
#define _NSL_NUM_H
#include "nsl_num_2.h"
#include "nsl_num_1.h"
#include "nsl_num_0.h"

typedef float num_type;
//typedef nsl_num_2 nsl_num_2;
//typedef nsl_num_0 nsl_num_0;
//typedef nsl_num_1 nsl_num_1;

bool operator>(float a, const nsl_num_0& b);
bool operator>(const nsl_num_0& b, float a);
bool operator>(float a, const nsl_num_0& b);
bool operator>(const nsl_num_0& b, float a);
bool operator>(const nsl_num_0 &a, const nsl_num_0 &b);
bool operator<(float a, const nsl_num_0 &b);
bool operator<(const nsl_num_0 &a, const nsl_num_0 &b);
bool operator==(const nsl_num_0 &a, float b);
nsl_num_0 operator*(float b, const nsl_num_0 &a);
nsl_num_0 operator*(const nsl_num_0 &a, float b);
nsl_num_0 operator*(const nsl_num_0 &a, const nsl_num_0 &b);
nsl_num_0 operator/(const nsl_num_0 &a, float b);
nsl_num_0 operator-(const nsl_num_0 &, float);
nsl_num_0 operator-(const nsl_num_0 &a, const nsl_num_0 &b);
nsl_num_0 operator-(float, const nsl_num_0 &);
nsl_num_0 operator-(const nsl_num_0 &, const nsl_num_0 &);
#endif
