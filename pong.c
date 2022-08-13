#include <stdlib.h>
#include "include/raylib.h"
#include <stdio.h>

int main(void)
{
    InitWindow(800, 450, "Ping-pong");
    SetWindowState(FLAG_VSYNC_HINT);
    float first_y = GetScreenHeight() / 2.0f;
    float second_y = GetScreenHeight() / 2.0f;
    int first_score = 0;
    int second_score = 0;
    float ballX = GetScreenWidth() / 2.0f;
    float ballY = GetScreenHeight() / 2.0f;
    float start_dirX = GetRandomValue(-1, 1);
    float start_dirY = GetRandomValue(-1, 1);
    float ballRadius = 10;
    int velocity = 80;
    Rectangle player1 = (Rectangle) {50, first_y - 50, 10, 100};
    Rectangle player2 = (Rectangle) {GetScreenWidth() - 50 - 10, second_y - 50, 10, 100};

    while (!WindowShouldClose())
    {
    	if (!start_dirX){
    		start_dirX += 1;
    		}
    	else if (!start_dirY){
    		start_dirY -= 1;
    		}
    	float FrameTime = GetFrameTime();
    	if ((ballY > 0 + ballRadius && ballY < GetScreenHeight() - ballRadius)){
    		ballX += velocity * FrameTime * start_dirX;
    		ballY += velocity * FrameTime * start_dirY;
    		}
    	else{
    		start_dirY *= -1;
    		ballX += start_dirX * FrameTime * velocity;
    		ballY += start_dirY * FrameTime * velocity;
    	}

    	if (!(ballX > 0 + ballRadius)){
    		second_score++;
    		ballX = GetScreenWidth() / 2.0f;
    		ballY = GetScreenHeight() / 2.0f;
    		start_dirX = GetRandomValue(-1, 1);
    		start_dirY = GetRandomValue(-1, 1);

    	}
    	else if (!(ballX < GetScreenWidth() - ballRadius)){
    		first_score++;
    		ballX = GetScreenWidth() / 2.0f;
    		ballY = GetScreenHeight() / 2.0f;
    		start_dirX = GetRandomValue(-1, 1);
    		start_dirY = GetRandomValue(-1, 1);
    	}
    	if (CheckCollisionCircleRec((Vector2){ballX, ballY}, ballRadius, player1) || CheckCollisionCircleRec((Vector2){ballX, ballY}, ballRadius, player2)){
    		start_dirX *= -1;
    		ballX += start_dirX * FrameTime * velocity;
    		ballY += start_dirY * FrameTime * velocity;
    	}
        BeginDrawing();
            ClearBackground(BLACK);

            DrawRectangleRec(player1, RAYWHITE);
            DrawRectangleRec(player2, RAYWHITE);
            DrawCircle(ballX, ballY, ballRadius, RAYWHITE);
            DrawText(TextFormat("%i", first_score), GetScreenWidth() / 4 - 30, 30, 30, RAYWHITE);
            DrawText(TextFormat("%i", second_score), GetScreenWidth() - 200 - 30, 30, 30, RAYWHITE);

            if (IsKeyDown(KEY_W) && player1.y > 0){
            player1.y -= 4;
            }
            if (IsKeyDown(KEY_S) && player1.y < 350){
            player1.y += 4;
            }
            if (IsKeyDown(KEY_UP) && player2.y > 0){
            player2.y -= 4;
            }
            if (IsKeyDown(KEY_DOWN) && player2.y < 350){
            player2.y += 4;
            }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
