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
 * File:   Matrix.hpp
 * Author: Elanna Stephenson
 *
 * Created on November 2, 2015, 10:29 AM
 * 
 * Wrapper class for matrix for linear algebra operations
 * Class and method definitions
 */

#ifndef MATRIX_HPP
#define	MATRIX_HPP

#include <Eigen/Core>
#include <Eigen/Dense>

#include "ForwardVectorDeclarations.hpp"

namespace SCPPR {
    
    class Matrix {
        
    public:
        
        // begin constructor definitions----------------------------------------
        //! Default constructor
        /*!
         Creates a new identity matrix
         */
        Matrix();
        
        //! Explicit constructor
        /*!
         Constructs a transformation matrix wrapping the provided Affine3f
         */
        Matrix(Eigen::Affine3f copy);
        
        //! Copy constructor
        /*!
         Clones the matrix
         */
        Matrix(const Matrix& copy);
        
        // end constructor definitions------------------------------------------
        
        // begin accessor definitions-------------------------------------------
        
        Eigen::Affine3f GetContents() const;
        
        void SetContents(Eigen::Affine3f newContents);
        
        // end accessor definitions---------------------------------------------
        
        // Begin static methods-------------------------------------------------
        
        //! Returns an affine transformation for a given uniform scale
        static Eigen::Affine3f Scale(float scaleFactor);
        
        //! Returns an affine scale for provided x y and z values
        static Eigen::Affine3f Scale(float x, float y, float z);
        
        //! Returns an inverse affine tranformation for given uniform scale
        static Eigen::Affine3f InverseScale(float scaleFactor);
        
        //! Returns an inverse affine scale for provided x y and z values
        static Eigen::Affine3f InverseScale(float x, float y, float z);
        
        //! Returns an affine rotation around a given vector
        static Eigen::Affine3f Rotate(float rads, Vector axis);
        
        //! Returns an inverse affine rotation around a given vector
        static Eigen::Affine3f InverseRotate(float rads, Vector axis);
        
        //! Returns an affine translation with given x y and z values.
        static Eigen::Affine3f Translate(float x, float y, float z);
        
        //! Returns an inverse affine translation with given x y and z values.
        static Eigen::Affine3f InverseTranslate(float x, float y, float z);
        
        // End static methods---------------------------------------------------
         
        // Begin operator overloads---------------------------------------------
        
        //! Normal transformation
        Normal operator* (const Normal& normal) const;
        
        //! Point transformation
        Point operator* (const Point& point) const;
        
        //! Vector transformation
        Vector operator* (const Vector& vector) const;
        
        //! Matrix multiplication
        Matrix operator* (const Matrix& secondMatrix) const;
        
        //! Matrix unary multiplication
        Matrix& operator*= (const Matrix& secondMatrix);
        
        //! Matrix assignment operator
        Matrix& operator= (const Matrix& secondMatrix);
        
        // End operator overloads-----------------------------------------------
        
        // Begin method definitions---------------------------------------------
        
        void DisplayContents() const;
        
        // End method definitions-----------------------------------------------
        
        //! Destructor
        ~Matrix();
        
    protected:
        
        Eigen::Affine3f matrix; //!< Wrapped matrix
    };
    
    inline Eigen::Affine3f Matrix::GetContents() const {
        return matrix;
    }
    
    inline void Matrix::SetContents(Eigen::Affine3f newContents) {
        matrix = newContents;
    }
    
    // Generate scale matrix
    inline Eigen::Affine3f Matrix::Scale(float scaleFactor) {
        return (Eigen::Affine3f)Eigen::Scaling(scaleFactor);
    }
    
    // Generate parameterized scale matrix
    inline Eigen::Affine3f Matrix::Scale(float x, float y, float z) {
        return (Eigen::Affine3f)Eigen::Scaling(x, y, z);
    }
    
    // Generate inverse scale matrix
    inline Eigen::Affine3f Matrix::InverseScale(float scaleFactor) {
        float invScaleFactor = 1 / scaleFactor;
        return (Eigen::Affine3f)Eigen::Scaling(invScaleFactor);
    }
    
    // Generate inverse parameterized scale matrix
    inline Eigen::Affine3f Matrix::InverseScale(float x, float y, float z) {
        return (Eigen::Affine3f)Eigen::Scaling(1/x, 1/y, 1/z);
    }
    
    // Generate translation matrix
    inline Eigen::Affine3f Matrix::Translate(float x, float y, float z) {
        return (Eigen::Affine3f)Eigen::Translation3f(x, y, z);
    }
    
    // Generate inverse translation matrix
    inline Eigen::Affine3f Matrix::InverseTranslate(float x, float y, float z) {
        return (Eigen::Affine3f)Eigen::Translation3f(-x, -y, -z);
    }
    
    // Matrix multiplication
    inline Matrix Matrix::operator* (const Matrix& secondMatrix) const {
        return matrix * secondMatrix.GetContents();
    }
    
    // Matrix unary multiplication
    inline Matrix& Matrix::operator*= (const Matrix& secondMatrix) {
        matrix = matrix * secondMatrix.GetContents();
        return (*this);
    }
    
    // Matrix assignment operator
    inline Matrix& Matrix::operator= (const Matrix& secondMatrix) {
        matrix = secondMatrix.GetContents();
        return (*this);
    }
}

#endif	/* MATRIX_HPP */

