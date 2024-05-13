#include "particle.h"
#include <iostream>
#include <raylib.h>
#include <vector>
using namespace std;

void DrawParticle(Particle *part){
    DrawCircle(part->x, part->y, part->radius, WHITE);
}
// click to spawn function

const double G = 0.01;
double tempVel = 0;
void clickToSpawn(vector<Particle> &particles){
    if(IsKeyPressed(KEY_RIGHT_BRACKET)){
        tempVel += 0.2;
    }
    if(IsKeyPressed(KEY_LEFT_BRACKET)){
        tempVel -= 0.2;
    }
    if(IsKeyPressed(KEY_D)){
        Particle temp(GetMousePosition().x, GetMousePosition().y, 25, 20000, true);
        // temp.velY = -0.2;
        particles.push_back(temp);
    }
    if(IsKeyPressed(KEY_W)){
        Particle temp(GetMousePosition().x, GetMousePosition().y, 10, 50);
        temp.velY = tempVel;
        tempVel = 0;
        particles.push_back(temp);
    }
    
}

// function that takes two circles and moves them towards each other 
void resolveGravitationForce(Particle &p1, Particle &p2){
    // calculate distance between them

    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    double distance = sqrt(dx*dx + dy*dy);
    double softDist = distance + 0.1 + 0.1;
    // distance = max(distance, minDistance);

    // calculate the force of attraction
    double force = (p1.mass * p2.mass) / (distance * distance / G);
    // calculate the direction of the force
    Vector2 line = {(float)((p2.x-p1.x)/distance), (float)((p2.y-p1.y)/ distance)};

    // apply the force to the particles
    p2.move({-line.x, -line.y}, force);
    p1.move(line, force);

}


int main() {
    const int screenWidth = 800;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Test");
    SetTargetFPS(30);
    vector<Particle> particles;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        clickToSpawn(particles);

        for(auto &it: particles){
            DrawParticle(&it);
            it.drawVelocity();
            if (it.positions.size() >= 2) {
                for (int i = 0; i < it.positions.size() - 1; i++) {
                    DrawLine(it.positions[i].x, it.positions[i].y, it.positions[i+1].x, it.positions[i+1].y, RED);
                }
            }
        }
        if(IsKeyPressed(KEY_ENTER)){
            particles.clear();
        }

        for(int i = 0; i < particles.size(); i++){
            for(int j = i+1; j < particles.size(); j++){
                if(i == j || (particles[i].isStar == false && particles[j].isStar == false)){
                    continue;
                }
                resolveGravitationForce(particles[i], particles[j]);
            }
        }

        EndDrawing();

    }
    CloseWindow();
    return 0;
}