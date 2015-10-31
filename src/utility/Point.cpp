/*
The MIT License (MIT)

Copyright (c) 2015 Elanna Stephenson

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE

 * File:   Point.cpp
 * Author: Elanna Stephenson
 *
 * Created on October 27, 2015, 2:58 PM
 * 
 * Utility vector wrapper class for linear algebra operations.
 * 
 */

#include <iostream>
#include <cstdlib>
#include <Eigen/Core>
#include <Eigen/Dense>

#include "ForwardVectorDeclarations.hpp"
#include "Point.hpp"
#include "Normal.hpp"
#include "Vector.hpp"

namespace SCPPR {
    
    // constructors declaration
    
    // default constructor
    Point::Point() :
        coordinates(0,0,0,0) {
        
    }
    
    // parameterized constructor
    Point::Point(float xArg, float yArg, float zArg) :
        coordinates(xArg,yArg,zArg,0) {
        
    }
    
    // array constructor
    Point::Point(float* coords) : 
        coordinates(coords) {
        coordinates.data()[3] = 0; // ensure term 4 is set to 0
    }
    
    // explicit constructor
    Point::Point(Eigen::Vector4f copy) : 
        coordinates(copy) {
        
    }
    
    // copy constructor
    Point::Point(const Point& point) :
        coordinates(point.coordinates){
        
    }
    
    // normal constructor
    Point::Point(const Normal& normal) :
        coordinates(normal.GetContents()){
        
    }
    
    // vector constructor
    Point::Point(const Vector& vector) :
        coordinates(vector.GetContents()) {
        
    }
    // accessors declaration
    
    // returns x coordinate
    float Point::GetX() const {
        return coordinates.x();
    }
    
    // returns y coordinate
    float Point::GetY() const {
        return coordinates.y();
    }
    
    // returns z coordinate
    float Point::GetZ() const {
        return coordinates.z();
    }
    
    // sets x coordinate
    void Point::SetX(float xCoord) {
        coordinates.x() = xCoord;
    }
    
    // sets y coordinate
    void Point::SetY(float yCoord) {
        coordinates.y() = yCoord;
    }
    
    // sets z coordinate
    void Point::SetZ(float zCoord) {
        coordinates.z() = zCoord;
    }
    
    // returns wrapped vector
    Eigen::Vector4f Point::GetContents() const {
        return coordinates;
    }
    
    // explicitely sets wrapped vector
    void Point::SetContents(Eigen::Vector4f newContents) {
        coordinates = newContents;
    }
    
    // displays the contents of the Point in the console
    void Point::DisplayContents() const {
        std::cout << coordinates << std::endl;
    }
    
    // destructor
    Point::~Point() {
        
    }
    
    // Vector addition operator
    Point Point::operator+ (const Vector& vector) const {
        return Point(coordinates + vector.GetContents());
    }
    
    // Vector subtraction operator
    Point Point::operator- (const Vector& vector) const {
        return Point(coordinates - vector.GetContents());
    }
    
    // Creation of vector from point subtraction
    Vector Point::operator- (const Point& point) const {
        return Vector(coordinates - point.coordinates);
    }
};