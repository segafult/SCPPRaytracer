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
 
 * File:   Normal.cpp
 * Author: Elanna Stephenson
 *
 * Created on October 26, 2015, 4:19 PM
 * 
 * Utility vector wrapper class for linear algebra operations
 * 
 */

#include <iostream>
#include <cstdlib>

#include <Eigen/Core>
#include <Eigen/Dense>

#include "ForwardVectorDeclarations.hpp"
#include "Normal.hpp"
#include "Point.hpp"
#include "Vector.hpp"

namespace SCPPR {
    
    // default constructor
    Normal::Normal() :
        coordinates(0,0,0,0) {
        
    }
    
    // parameterized constructor
    Normal::Normal(float xArg, float yArg, float zArg) :
        coordinates(xArg,yArg,zArg,0) {
        
    }
    
    // array constructor
    Normal::Normal(float* coords) : 
        coordinates(coords) {
        coordinates.data()[3] = 0; //don't allow 4th position to be 0
    }
    
    // explicit contructor
    Normal::Normal(Eigen::Vector4f copy) :
        coordinates(copy) {
        
    }
    
    // copy constructor
    Normal::Normal(const Normal& copy) :
        coordinates(copy.coordinates) {
        
    }
    
    // point constructor
    Normal::Normal(const Point& copy) : 
        coordinates(copy.GetContents()) {
        
    }
    
    // vector constructor
    Normal::Normal(const Vector& copy) :
        coordinates(copy.GetContents()) {
        
    }
    
    // accessors declaration
    float Normal::GetX() {
        return coordinates.x();
    }
    
    float Normal::GetY() {
        return coordinates.y();
    }
    
    float Normal::GetZ() {
        return coordinates.z();
    }
    
    void Normal::SetX(float xCoord) {
        coordinates.x() = xCoord;
    }
    
    void Normal::SetY(float yCoord) {
        coordinates.y() = yCoord;
    }
    
    void Normal::SetZ(float zCoord) {
        coordinates.z() = zCoord;
    }
    
    // get the wrapped coordinates
    Eigen::Vector4f Normal::GetContents() const {
        return coordinates;
    }
    
    //set new wrapped coordinates
    void Normal::SetContents(Eigen::Vector4f newContents) {
        coordinates = newContents;
    }
    
    // get the magnitude of wrapped vector
    float Normal::GetMagnitude() const {
        return coordinates.norm();
    }
    
    // get the magnitude of the wrapped vector squared
    float Normal::GetSquaredMagnitude() const {
        return coordinates.squaredNorm();
    }
    
    // normalize the normal
    void Normal::Normalize() {
        coordinates.normalize();
    }

    // debug methods
    void Normal::DisplayContents() const {
        std::cout << coordinates << std::endl;
    }
    
    // dot product of vector and normal
    float Normal::operator* (const Vector& secondVector) const {
        return coordinates.dot(secondVector.GetContents());
    }
    
    // adding a vector to a normal
    Vector Normal::operator+ (const Vector& secondVector) const {
        return Normal(coordinates + secondVector.GetContents());
    }
    
    Normal::~Normal() {
        
    }
};