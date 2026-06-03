#include<raylib.h>
#include<ctime>
int Win_x = 800;
int Win_y = 600;
int snake_x_y = 20;
int speed = 1;
class Food{
    public: 

    int Food_x; 
    int Food_y; 

    Food(){
        respawn();
    }

    void respawn(){
        Food_x = GetRandomValue(0,Win_x/snake_x_y -1);
        Food_y = GetRandomValue(0,Win_y/snake_x_y -1);
    }

    void DrawFood(){
        DrawRectangle(Food_x*snake_x_y,Food_y*snake_x_y,snake_x_y,snake_x_y,RED);
    }
    

};

class Snake{
    public:

    int a = GetRandomValue(0,3); 
    

    int snake_x = (Win_x/snake_x_y)/2 -1;
    int snake_y = (Win_y/snake_x_y)/2 -1;
    

    void MovePlayer(){
        switch (a)
        {
        case 0:
            snake_x += speed;
            break;
        case 1:
            snake_x -= speed;
            break;

        case 2:
            snake_y += speed;
            break;

        case 3:
            snake_y -= speed;
            break;
        }
        
    }

    void DrawSnake(){
        DrawRectangle(snake_x * snake_x_y, snake_y* snake_x_y,20,20,GREEN);
    }
};


int main(){
    
    InitWindow(Win_x,Win_y,"Snake game");
    SetTargetFPS(15);
    Food food;
    Snake snake;

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);

        food.DrawFood();
        snake.DrawSnake();
        snake.MovePlayer();
        
       
        EndDrawing();
    }
    CloseWindow();
}