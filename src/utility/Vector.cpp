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
THE SOFTWARE.
 
 * File:   Vector.cpp
 * Author: Elanna Stephenson
 *
 * Created on October 25, 2015, 12:32 AM
 * 
 * Utility vector wrapper class for linear algebra operations.
 * 
 */

#include <iostream>
#include <cstdlib>
#include <Eigen/Core>

#include "ForwardVectorDeclarations.hpp"
#include "Vector.hpp"
#include "Normal.hpp"
#include "Point.hpp"

namespace SCPPR {
    
    // Default constructor: Initializes coordinates to an empty vector
    Vector::Vector() : 
        coordinates(0,0,0,0) {
        
    }
    
    // Initializes vector to {xArg,yZrg,zArg}
    Vector::Vector(float xArg, float yArg, float zArg) : 
        coordinates(xArg, yArg, zArg, 0) {
        
    }
    
    // Initializes vector to values stored at coords
    Vector::Vector(float *coords) : 
        coordinates(coords) {
        coordinates.data()[3] = 0; // ensure term 4 is set to 0
    }
    
    // Initializes coordinates to provided vector4f
    Vector::Vector(Eigen::Vector4f copy) : 
        coordinates(copy) {
        
    }
    
    // Copy constructor
    Vector::Vector(const Vector& copy) :
        coordinates(copy.coordinates) {
        
    }
    
    // Construct from a normal
    Vector::Vector(const Normal& normalCopy) :
        coordinates(normalCopy.GetContents()) {
        
    }
    
    // Construct from a point
    Vector::Vector(const Point& pointCopy) : 
        coordinates(pointCopy.GetContents()) {
        
    }
    
    // accessors declaration
    
    // returns x coordinate
    float Vector::GetX() const {
        return coordinates.x();
    }
    
    // returns y coordinate
    float Vector::GetY() const {
        return coordinates.y();
    }
    
    // returns z coordinate
    float Vector::GetZ() const {
        return coordinates.z();
    }
    
    // sets x coordinate
    void Vector::SetX(float xCoord) {
        coordinates.x() = xCoord;
    }
    
    // sets y coordinate
    void Vector::SetY(float yCoord) {
        coordinates.y() = yCoord;
    }
    
    // sets z coordinate
    void Vector::SetZ(float zCoord) {
        coordinates.z() = zCoord;
    }
    
    // returns wrapped vector
    Eigen::Vector4f Vector::GetContents() const {
        return coordinates;
    }
    
    // explicitely sets wrapped vector
    void Vector::SetContents(Eigen::Vector4f newContents) {
        coordinates = newContents;
    }
    
    // returns magnitude of the vector
    float Vector::GetMagnitude() const {
        return coordinates.norm();
    }
    
    // returns magnitude of the vector squared
    float Vector::GetSquaredMagnitude() const {
        return coordinates.squaredNorm();
    }
    
    // normalizes the vector
    void Vector::Normalize() {
        coordinates.normalize();
    }

    // debug methods
    // display wrapped vector in the console
    void Vector::DisplayContents() const {
        std::cout << coordinates << std::endl;
    }
    
    // operator overrides with circular dependencies
    
    // dot product of normal and a vector
    float Vector::operator* (const Normal& secondNormal) const {
        return coordinates.dot(secondNormal.GetContents());
    }
    
    // addition of a normal and a vector
    Vector Vector::operator+ (const Normal& secondNormal) const {
        return Vector(coordinates + secondNormal.GetContents());
    }

    Vector::~Vector() {
        
    }
};

