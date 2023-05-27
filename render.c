#include "shaders.c"

#define PIXEL_ASCII "█"


void mainImage(vec2 Coord){
    INIT_VEC2(uv, 0, 0);
    vec2_divide(&Coord, &Resolution, &uv);

    //col = <uv.x+0, uv.y+2, uv.x+4>
    INIT_VEC3(col, uv.x+0.0, uv.y+2.0, uv.x+4.0);

    //col = 0.5+0.5*cos(Time+col)
    vec3_sadd(&col, Time);
    vec3_cos(&col);
    vec3_smult(&col, 0.5);
    vec3_sadd(&col, 0.5);

    INIT_VEC3(Color, col.x, col.y, col.z);
    
    COLOR_vec3(PIXEL_ASCII, Color);
}

// update screen, do not change other than for optimization
int main(int argc, char** argv){
    INIT_VEC2(COORDS, 0, 0);

    while(1){
        REFRESH_SCREEN;
        for(int row = WINDOW_X; row > 0; row--){
            for(int col = 0; col <= WINDOW_X; col++){
                COORDS.x = col;
                COORDS.y  = row;
                mainImage(COORDS);
                
            }
            printf("\n");
        }
        
        usleep(REFRESH_RATE);
        Time += (float)REFRESH_RATE/SEC_TO_MICROSEC;
        
    }
}
