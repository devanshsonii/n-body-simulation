#include "raylib.h"
#include <deque>
#include <math.h>
using namespace std;

class Particle{
    private:
    Vector2 prevPos;
    public:
    double mass;
    double x;
    double y;
    double radius;
    double velX = 0;
    double velY = 0;
    bool isStar;
    deque<Vector2> positions;
    Particle(double x, double y, double radius, double mass, bool isStar = false){
        this->x = x;
        this->y = y;
        this->mass = mass;
        this->radius = radius;
        prevPos = {(float)x, (float)y};
        this->isStar = isStar;
    };
    void move(Vector2 line, double force) {
        if (isStar) return;

        double acc = force / mass;
        Vector2 accVector = {line.x * acc, line.y * acc};
        // Verlet integration
        Vector2 prevPos = Vector2{(x, y)};
        x += velX + accVector.x * 0.5;
        y += velY + accVector.y * 0.5;
        velX += accVector.x;
        velY += accVector.y;

        positions.push_front(Vector2{(float)x, (float)y});
        if (positions.size() > 100000) {
            positions.pop_back();
        }

        checkBounds();
    }
    void checkBounds(){
        // if(x+radius >= GetScreenWidth()){
        //     x = GetScreenWidth() - radius;
        // } else if(x - radius <= 0){
        //     x = radius;
        // }
        // if(y+radius >= GetScreenHeight()){
        //     y = GetScreenHeight()- radius;
        //     velY = -velY;
        // }
        // if(y <= radius){
        //     y = radius;
        //     velY = -velY;
        // }
    }
    double kineticEnergy()const{
        return 0.5 * mass * (velX * velX + velY * velY);
    }
    void drawVelocity(){
        double angle = atan2(velY, velX);
        if(angle < 0) angle += 2 * M_PI;
        Vector2 arrowEnd = {float((float)x + cos(angle) * 50), float((float)y + sin(angle) * 50)};
        DrawLine(x, y, arrowEnd.x, arrowEnd.y, BLUE);
    }
};
