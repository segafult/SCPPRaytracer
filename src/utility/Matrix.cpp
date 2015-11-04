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
 *  
 * File:   Matrix.cpp
 * Author: Elanna Stephenson
 *
 * Created on November 2, 2015, 3:30PM
 * 
 * Wrapper class for matrix for linear algebra operations
 * 
 */

#include <iostream>
#include <cstdlib>

#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <Eigen/LU>

#include "ForwardVectorDeclarations.hpp"
#include "Matrix.hpp"
#include "Point.hpp"
#include "Normal.hpp"
#include "Vector.hpp"

namespace SCPPR {
    
    // Default constructor
    Matrix::Matrix() : 
        matrix(Eigen::Affine3f::Identity()) {
        
    }
    
    // Explicit constructor
    Matrix::Matrix(Eigen::Affine3f copy) :
        matrix(copy) {
        
    }
    
    // Copy constructor
    Matrix::Matrix(const Matrix& copy) :
        matrix(copy.GetContents()) {
        
    }
    
    Eigen::Affine3f Matrix::Rotate(float rads, Vector axis) {
        return (Eigen::Affine3f)Eigen::AngleAxis<float>(rads, axis.GetContents().topRows(3));
    }
    
    Eigen::Affine3f Matrix::InverseRotate(float rads, Vector axis) {
        return (Eigen::Affine3f)Eigen::AngleAxis<float>(-rads, axis.GetContents().topRows(3));
    }
    
    void Matrix::DisplayContents() const {
        std::cout << matrix.matrix() << std::endl;
    }
    
    // Transforming a point
    Point Matrix::operator* (const Point& point) const {
        // Extract translation component
        Eigen::VectorXf translation(matrix.translation());
        translation.resize(4);
        translation.data()[3] = 0; // set w component to zero
        return Point((matrix * point.GetContents()) + translation);
    }
    
    // Transforming a vector
    Vector Matrix::operator* (const Vector& vector) const {
        return Vector((Eigen::Affine3f)matrix.linear() * vector.GetContents());
    }
    
    // Transforming a normal
    Normal Matrix::operator* (const Normal& normal) const {
        Eigen::Affine3f tempMatrix = (Eigen::Affine3f)matrix.linear().transpose();
        return Normal(tempMatrix * normal.GetContents());
    }
    
    Matrix::~Matrix() {
        
    }
}