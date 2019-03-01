#include "emoji.hpp"

/*
 * Implement your emojis in this file.
 **/

// A yellow, empty face.
Face::Face(Point c, int r) : face {c, r}
{
    face.set_fill_color(Color::yellow);
}

void Face::attach_to(Graph_lib::Window& win)
{
    win.attach(face);
}

EmptyFace::EmptyFace(Point c, int r) : Face {c, r}, leftEye{{c.x-r/2, c.y}, r/5}, rightEye{{c.x+r/2, c.y}, r/5}, leftPupil{{c.x-r/2, c.y}, r/10}, rightPupil{{c.x+r/2, c.y}, r/10}
{
    leftEye.set_fill_color(Color::white);
    rightEye.set_fill_color(Color::white);
    leftPupil.set_fill_color(Color::black);
    rightPupil.set_fill_color(Color::black);
}

void EmptyFace::attach_to(Graph_lib::Window& win)
{
    Face::attach_to(win);
    win.attach(leftEye);
    win.attach(rightEye);
    win.attach(leftPupil);
    win.attach(rightPupil);
    
}

SmileyFace::SmileyFace(Point c, int r) : EmptyFace {c, r}, smile{{c.x, c.y+r/4}, int(1.25*r), r, 180, 360}
{
    
}

void SmileyFace::attach_to(Graph_lib::Window& win)
{
    EmptyFace::attach_to(win);
    win.attach(smile);
    
}

SadFace::SadFace(Point c, int r) : EmptyFace {c, r}, sadmouth{{c.x, c.y+int(r/1.5)}, int(1.25*r), r, 0, 180}
{
    
}

void SadFace::attach_to(Graph_lib::Window& win)
{
    EmptyFace::attach_to(win);
    win.attach(sadmouth);
    
}

AngryFace::AngryFace(Point c, int r) : SadFace {c, r}, leftEyebrow {{c.x-r/2-r/10, c.y-2*r/5},{c.x-r/2+r/10, c.y-r/5}}, rightEyebrow {{c.x+r/2-r/10, c.y-r/5},{c.x+r/2+r/10, c.y-2*r/5}}
{
    face.set_fill_color(Color::red);
}

void AngryFace::attach_to(Graph_lib::Window& win)
{
    SadFace::attach_to(win);
    win.attach(leftEyebrow);
    win.attach(rightEyebrow);
    
}

BlinkingFace::BlinkingFace(Point c, int r) : SmileyFace{c, r}, blink{{c.x+r/2, c.y}, 2*r/5, 2*r/5, 0, 180}
{
   
}

void BlinkingFace::attach_to(Graph_lib::Window& win)
{
    SmileyFace::attach_to(win);
    win.detach(rightEye);
    win.detach(rightPupil);
    win.attach(blink);
}

SurprisedFace::SurprisedFace(Point c, int r) : EmptyFace{c, r}, mouth{{c.x, c.y+r/2}, r/4}
{
    mouth.set_fill_color(Color::black);
}

void SurprisedFace::attach_to(Graph_lib::Window& win)
{
    EmptyFace::attach_to(win);
    win.attach(mouth);
}
