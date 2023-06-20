#pragma once

#include <string>
using namespace std;

class Shape {
public:
    Shape(int, int, const string&);
    virtual ~Shape();
    int getLength() const;
    int getWidth() const;
    string getBorderColour() const;
    virtual void draw() = 0;
private:
    int length, width;
    string borderColour;
};

class Fillable {
public:
    Fillable(const string&);
    void drawFill();
private:
    string fillColour;
};

class Writable {
public:
    Writable(const string& text);
    void writeText();
private:
    string text;
};

class Square : public Shape {
public:
    Square(int, int, const string&);
    virtual ~Square();
    void drawBorder();
    void draw() override;
};

class FilledSquare : public Square, public Fillable {
public:
    FilledSquare(int, int, const string&, const string&);
    virtual ~FilledSquare();
    void draw() override;
};

class FilledTextSquare : public FilledSquare, public Writable {
public:
    FilledTextSquare(int, int, const string&, const string&, const string&);
    virtual ~FilledTextSquare();
    void draw() override;
};

class Circle : public Shape {
public:
    Circle(int, int, const string&);
    virtual ~Circle();
    void drawOutside();
    void draw() override;
};

class FilledCircle : public Circle, public Fillable{
public:
    FilledCircle(int, int, const string&, const string&);
    virtual ~FilledCircle();
    void draw() override;
};

class Arc : public Shape {
public:
    Arc(int, int, const string&);
    virtual ~Arc();
    void draw() override;
};
