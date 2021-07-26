#include "button.hpp"

Button::Button() : /*TODO: need to adjust position */ posx_(0), posy_(0) {}

void Button::move() {
    (void) posx_;
    (void) posy_;
}

bool Button::OnEdge() {
    return true;
}