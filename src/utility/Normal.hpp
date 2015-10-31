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
 
 * File:   Normal.hpp
 * Author: Elanna Stephenson
 *
 * Created on October 26, 2015, 2:18 PM
 * 
 * Utility vector wrapper class for linear algebra operations
 * Class and method definitions
 * 
 */

#ifndef NORMAL_HPP
#define	NORMAL_HPP

#include <Eigen/Core>
#include <Eigen/Dense>

#include "ForwardVectorDeclarations.hpp"
#include "Vector.hpp"
#include "Point.hpp"


namespace SCPPR {
    
    //! 3D Normal Class
    /*!
     A wrapper class for Vector4f to provide normal behaviour while transforming
     */
    class Normal {
        
    public:
        
        // begin constructor declarations---------------------------------------
        
        //! Default constructor
        /*!
         Constructs a normal of {0,0,0}
         */
        Normal();
        
        //! Parameterized constructor
        /*!
         Constructs a normal of {xArg,yArg,zArg}
         */
        Normal(float xArg, float yArg, float zArg);
        
        //! Array constructor
        /*!
         Constructs a normal using the floats stored in the array at coords
         */
        Normal(float *coords);
        
        //! Explicit constructor
        /*!
         Constructs a normal using the provided Eigen::Vector4f
         */
        Normal(Eigen::Vector4f copy);
        
        //! Copy constructor
        /*!
         Clones the provided normal
         */
        Normal(const Normal& copy);
        
        //! Copy constructor
        /*!
         Creates a normal using the provided vector
         */
        Normal(const Vector& copy);
        
        //! Copy constructor
        /*!
         Creates a normal using the provided point
         */
        Normal(const Point& copy);
        
        // end constructor declarations-----------------------------------------
        
        // begin accessor declarations------------------------------------------

        //! Returns X component of wrapped vector
        float GetX();

        //! Returns Y component of wrapped vector
        float GetY();

        //! Returns Z component of wrapped vector
        float GetZ();

        //! Sets X component of wrapped vector
        /*!
         \param xCoord X component to set
         */
        void SetX(float xCoord);

        //! Sets Y component of wrapped vector
        /*!
         \param yCoord Y component to set
         */
        void SetY(float yCoord);

        //! Sets Z component of wrapped vector
        /*!
         \param zCoord Z component to set
         */
        void SetZ(float zCoord);

        //! Returns a copy of the wrapped vector
        Eigen::Vector4f GetContents() const;

        //! Explicitly sets the wrapped vector to a provided Eigen::Vector4f
        /*!
         \param newContents The new contents of the Normal wrapper
         */
        void SetContents(Eigen::Vector4f newContents);
        
        // end accessor declarations--------------------------------------------
        
        // begin general methods declarations-----------------------------------
        
        //! Returns the magnitude of the normal
        float GetMagnitude() const;

        //! Returns the magnitude of the normal, squared
        float GetSquaredMagnitude() const;

        //! Normalizes the normal
        void Normalize();
        
        //! Displays the contents of the normal in the console.
        void DisplayContents() const;
        
        // end general methods declarations-------------------------------------
        
        // begin operator override declarations---------------------------------
        
        //! Negation operation
        Normal operator- (void) const;
        
        //! Addition of two normals
        Normal operator+ (const Normal& secondNormal) const;
        
        //! Dot product of a normal and vector with vector on right
        float operator* (const Vector& secondVector) const;
        
        //! Scalar multiplication of normal with normal on right
        Normal operator* (const float scalar) const;
        
        //! Addition of a vector to a normal with vector on the right
        Vector operator+ (const Vector& secondVector) const;
        
        //! Assignment operator
        Normal& operator= (const Normal& secondNormal);
        
        //! Increment operator
        Normal& operator+= (const Normal& secondNormal);
        
        //! Destructor
        ~Normal();
        
    protected:
  
        Eigen::Vector4f coordinates;  //!< Coordinates of the normal
    };
    
    //normal subtraction
    inline Normal Normal::operator- (void) const {
        return Normal(-coordinates);
    }
    
    // normal addition
    inline Normal Normal::operator+ (const Normal& secondNormal) const {
        return Normal(coordinates + secondNormal.coordinates);
    }
    
    // normal scalar multiplication
    inline Normal Normal::operator* (const float scalar) const {
        return Normal(coordinates * scalar);
    }
    
    // normal assignment
    inline Normal& Normal::operator= (const Normal& secondNormal) {
        // check if assigning the same normal
        if(this == &secondNormal)
            return(*this);
        //set coordinates to those of secondnormal and return this
        coordinates = secondNormal.coordinates;
        return(*this);
    }
    
    // Normal increment
    inline Normal& Normal::operator+= (const Normal& secondNormal) {
        // increment and return a reference to this normal
        coordinates = coordinates + secondNormal.coordinates;
        return(*this);
    }
    
    //! Multiplication of normal by a scalar, scalar on the left
    Normal operator* (const float scalar, const Normal& normal);
    
    // scalar multiplication of normal
    inline Normal operator* (const float scalar, const Normal& normal) {
        return Normal(scalar * normal.GetContents());
    }
};

#endif	/* NORMAL_HPP */

