#pragma once

// Include Graph_lib library files that holds declarations needed for Window,
// and Shape derivatives.
#include "Graph.h"
#include "GUI.h"

// This part is only relevant for non-Windows users in 2019.
// Windows users has Graph_lib::Arc, Mac don't.
#ifndef WIN32
#include "graph_lib.hpp"
#endif

using namespace Graph_lib;

// An abstract class. Concrete classes derived from this base class
// has to implement the member function attach_to().
class Emoji
{
public:
    // Disable copying. Disable slicing, etc.
    Emoji(const Emoji&) = delete;
    Emoji& operator=(const Emoji&) = delete;
    
    // Deleting the copy constructor also deletes the default constructor.
    // Emoji needs a default constructor.
    Emoji() {}
    // Emoji() = default; // is an alternative way of achieving the same.
    
    // The pure virtual function that has to be overriden for a deriving class
    // to be instantiable. Every class deriving from Emoji is supposed to
    // attach all its Shapes to a window. This makes the class abstract.
    virtual void attach_to(Graph_lib::Window&) = 0;
    
    // Relevant because Vector_ref can own Emojis and automatically cleans up.
    // Subject will be visited later in the course.
    virtual ~Emoji() {}
};

// A yellow, empty face.
// An abstract class.
class Face : public Emoji
{
protected:
    Circle face;
    
public:
    Face(Point c, int r);
    void attach_to(Graph_lib::Window& win) override = 0;
};

class EmptyFace : public Face
{
protected:
    Circle leftEye;
    Circle rightEye;
    Circle leftPupil;
    Circle rightPupil;
    
public:
    EmptyFace(Point c, int r);
    void attach_to(Graph_lib::Window& win) override;
};

class SmileyFace : public EmptyFace
{
    Arc smile;
public:
    SmileyFace(Point c, int r);
    void attach_to(Graph_lib::Window& win) override;
};

class SadFace : public EmptyFace
{
    Arc sadmouth;
public:
    SadFace(Point c, int r);
    void attach_to(Graph_lib::Window& win) override;
};

class AngryFace : public SadFace
{
    Line leftEyebrow;
    Line rightEyebrow;
    
public:
    AngryFace(Point c, int r);
    void attach_to(Graph_lib::Window& win) override;
};

class BlinkingFace : public SmileyFace
{
    Arc blink;
public:
    BlinkingFace(Point c, int r);
    void attach_to(Graph_lib::Window& win) override;
};

class SurprisedFace : public EmptyFace
{
    Circle mouth;
public:
    SurprisedFace(Point c, int r);
    void attach_to(Graph_lib::Window& win) override;
};


