#pragma once

#include <string>
#include <vector>
#include <iostream>

class Button {
    public:
    /* default constuctor */
    Button();

    /* controls the movement of the pipe */
    void move();

    /* Judges the position of the pipe.
     * @return true if the pipe has a out-of-bound y-position, false otherwise.
     */
    bool OnEdge();

    private:
    double posx_;
    double posy_;
};