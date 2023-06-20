#include <iostream>
#include <string>
#include "ShapesGood.h"

using namespace std;

/* -------------------- SHAPE -------------------- */
Shape::Shape(int len, int wid, const string& borderClr) : length(len), width(wid), borderColour(borderClr) {}
Shape::~Shape() = default;
int Shape::getLength() const { return length; }
int Shape::getWidth() const { return width; }
string Shape::getBorderColour() const { return borderColour; }

/* -------------------- FILLABLE -------------------- */
Fillable::Fillable(const string& fillClr): fillColour(fillClr) {}
void Fillable::drawFill(){
    cout << " With " + fillColour + " fill.";
}

/* -------------------- WRITABLE -------------------- */
Writable::Writable(const string &txt): text(txt) {}
void Writable::writeText() {
    cout << " Containing the text: \"" << text << "\".";
}

/* -------------------- SQUARE -------------------- */
Square::Square(int len, int wid, const string& colour) : Shape(len, wid, colour) {}
void Square::drawBorder() {
    cout << "\nDrawing a " + getBorderColour() + " square.";
}
Square::~Square() = default;
void Square::draw(){ drawBorder(); }

/* -------------------- FILLEDSQUARE -------------------- */
FilledSquare::FilledSquare(int len, int wid, const string& borderColour, const string& fillColour) : Square(len, wid, borderColour), Fillable(fillColour) {}
FilledSquare::~FilledSquare() = default;
void FilledSquare::draw(){
    drawBorder();
    drawFill();
}

/* -------------------- FILLEDTEXTSQUARE -------------------- */
FilledTextSquare::FilledTextSquare(int len, int wid, const string& borderColour, const string& fillColour, const string& text) : FilledSquare(len, wid, borderColour, fillColour), Writable(text) {}
FilledTextSquare::~FilledTextSquare() = default;
void FilledTextSquare::draw(){
    drawBorder();
    drawFill();
    writeText();
}

/* -------------------- CIRCLE -------------------- */
Circle::Circle(int len, int wid, const string& colour) : Shape(len, wid, colour) {}
Circle::~Circle() = default;
void Circle::drawOutside() {
    cout << "\nDrawing a " + getBorderColour() + " circle.";
}
void Circle::draw(){ Circle::drawOutside(); }

/* -------------------- FILLEDCIRCLE -------------------- */
FilledCircle::FilledCircle(int len, int wid, const string& borderColour, const string& fillColour) : Circle(len, wid, borderColour), Fillable(fillColour){}
FilledCircle::~FilledCircle() = default;
void FilledCircle::draw(){
    drawOutside();
    drawFill();
}

/* -------------------- ARC -------------------- */
Arc::Arc(int len, int wid, const string& colour) : Shape(len, wid, colour) {}
Arc::~Arc() = default;
void Arc::draw() {
    cout << "\nDrawing a " + getBorderColour() + " arc.";
}
