#include<raylib.h>

int main(){
    InitWindow(800,800,"Snake game");
    while(!WindowShouldClose()){
        BeginDrawing();
        DrawCircle(400,400,20,YELLOW);
        EndDrawing();
    }
    CloseWindow();
}