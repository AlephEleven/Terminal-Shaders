#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>


// INITS

#define COLOR(in, R, G, B) printf("\033[38;2;%s;%s;%sm%s\033[0;00m", R, G, B, in)

#define REFRESH_SCREEN \
        printf("\033[H\033[J"); \
        printf("\033[%d;%dH", 0, 0);

#define VEC2_SIZE 2
#define INIT_VEC2(NAME, X, Y) vec2 NAME = {.x = X, .y = Y, VEC2_SIZE}


#define VEC3_SIZE 3
#define INIT_VEC3(NAME, X, Y, Z) vec3 NAME = {.x = X, .y = Y, .z = Z, VEC3_SIZE}

//approx of to 1/255
#define RGB_NORM 0.00392156862745

#define RGB_CHAR_BUFFER 256

typedef struct vec2 {
    float x;
    float y;
    int size;
} vec2;


typedef struct vec3 {
    float x;
    float y;
    float z;
    int size;
} vec3;

// SCREEN

#define WINDOW_X 32
#define WINDOW_Y 32
#define SEC_TO_MICROSEC 1000000
#define REFRESH_RATE (int)(SEC_TO_MICROSEC * 0.2)

INIT_VEC2(Resolution, WINDOW_Y, WINDOW_X);
float Time = 0.0;


// FUNCTIONS
// utility

void print_vec3(vec3 vector){
    printf("(%f, %f, %f)\n", vector.x, vector.y, vector.z);
}

void print_vec2(vec2 vector){
    printf("(%f, %f)\n", vector.x, vector.y);
}


void COLOR_vec3(char* in, vec3 color){
    char R[RGB_CHAR_BUFFER];
    char G[RGB_CHAR_BUFFER];
    char B[RGB_CHAR_BUFFER];

    int numericR = (int)(color.x*255);
    int numericG = (int)(color.y*255);
    int numericB = (int)(color.z*255);

    sprintf(R, "%d", (numericR > 0) ? numericR : 0);
    sprintf(G, "%d", (numericG > 0) ? numericG : 0);
    sprintf(B, "%d", (numericB > 0) ? numericB : 0);

    COLOR(in, R, G, B);
    COLOR(in, R, G, B);
}

// vec2

void vec2_add(vec2 * vecA, vec2 * vecB, vec2 * vecC){
    vecC->x += vecB->x;
    vecC->y += vecB->y;
}

void vec2_sub(vec2 * vecA, vec2 * vecB, vec2 * vecC){
    vecC->x -= vecB->x;
    vecC->y -= vecB->y;
}

void vec2_mult(vec2 * vecA, vec2 * vecB, vec2 * vecC){
    vecC->x = vecA->x*vecB->x;
    vecC->y = vecA->y*vecB->y;;
}

void vec2_divide(vec2 * vecA, vec2 * vecB, vec2 * vecC){
    vecC->x = vecA->x/vecB->x;
    vecC->y = vecA->y/vecB->y;
}

void vec2_sadd(vec2 * vec, float scalar){
    vec->x += scalar;
    vec->y += scalar;
}

void vec2_ssub(vec2 * vec, float scalar){
    vec->x -= scalar;
    vec->y -= scalar;
}

void vec2_smult(vec2 * vec, float scalar){
    vec->x *= scalar;
    vec->y *= scalar;
}

void vec2_cos(vec2 * vec){
    vec->x = cosf(vec->x);
    vec->y = cosf(vec->y);
}

void vec2_sin(vec2 * vec){
    vec->x = sinf(vec->x);
    vec->y = sinf(vec->y);
}

void vec2_set(vec2 * vecFrom, vec2 * vecTo){
    vecTo->x = vecFrom->x;
    vecTo->y = vecFrom->y;
}

void vec2_abs(vec2 * vec){
    vec->x = fabsf(vec->x);
    vec->y = fabsf(vec->y);
}

void vec2_fract(vec2 * vec){
    float intpart;

    vec->x = fabsf(modff(vec->x, &intpart));
    vec->y = fabsf(modff(vec->y, &intpart));;
}

float vec2_length(vec2 * vec){
    return sqrtf(vec->x*vec->x + vec->y*vec->y);
}

float vec2_max(vec2 * vec){
    return (vec->x >= vec->y) ? vec->x : vec->y;
}

float vec2_min(vec2 * vec){
    return (vec->x < vec->y) ? vec->x : vec->y;
}


// vec3

void vec3_add(vec3 * vecA, vec3 * vecB, vec3 * vecC){
    vecC->x += vecB->x;
    vecC->y += vecB->y;
    vecC->z += vecB->z;
}

void vec3_sub(vec3 * vecA, vec3 * vecB, vec3 * vecC){
    vecC->x -= vecB->x;
    vecC->y -= vecB->y;
    vecC->z -= vecB->z;
}

void vec3_mult(vec3 * vecA, vec3 * vecB, vec3 * vecC){
    vecC->x = vecA->x*vecB->x;
    vecC->y = vecA->y*vecB->y;
    vecC->z = vecA->z*vecB->z;
}

void vec3_divide(vec3 * vecA, vec3 * vecB, vec3 * vecC){
    vecC->x = vecA->x/vecB->x;
    vecC->y = vecA->y/vecB->y;
    vecC->z = vecA->z/vecB->z;
}

void vec3_sadd(vec3 * vec, float scalar){
    vec->x += scalar;
    vec->y += scalar;
    vec->z += scalar;
}

void vec3_smult(vec3 * vec, float scalar){
    vec->x *= scalar;
    vec->y *= scalar;
    vec->z *= scalar;
}

void vec3_cos(vec3 * vec){
    vec->x = cosf(vec->x);
    vec->y = cosf(vec->y);
    vec->z = cosf(vec->z);
}

void vec3_sin(vec3 * vec){
    vec->x = sinf(vec->x);
    vec->y = sinf(vec->y);
    vec->z = sinf(vec->z);
}

void vec3_set(vec3 * vecFrom, vec3 * vecTo){
    vecTo->x = vecFrom->x;
    vecTo->y = vecFrom->y;
    vecTo->z = vecFrom->z;
}

void vec3_sset(float x, float y, float z, vec3 * vecTo){
    vecTo->x = x;
    vecTo->y = y;
    vecTo->z = z;
}

void palette(float t, vec3 * a, vec3 * b, vec3 * c, vec3 * d, vec3 * vecOut){
    vec3_set(c, vecOut);
    
    vec3_smult(vecOut, t);
    vec3_add(vecOut, d, vecOut);
    vec3_smult(vecOut, 6.28318);
    vec3_cos(vecOut);

    vec3_mult(vecOut, b, vecOut);
    vec3_add(vecOut, a, vecOut);

}

float vec3_dotproduct(vec3 * vecA, vec3 * vecB){
    return vecA->x*vecB->x + vecA->y*vecB->y + vecA->z*vecB->z;
}

float float_step(float scalar, float step){
    return (scalar > step) ? 1.0 : 0.0;
}

float clamp(float scalar, float lowerlimit, float upperlimit){
    if (scalar < lowerlimit) return lowerlimit;
    if (scalar > upperlimit) return upperlimit;
    
    return scalar;
}

float float_smoothstep(float scalar, float edge0, float edge1){
    float x = clamp((scalar-edge0) / (edge1 - edge0), 0.0, 1.0);

    return x * x * (3.0 - 2.0 * x);
}

