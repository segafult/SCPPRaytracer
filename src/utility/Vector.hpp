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

 * File:   Vector.hpp
 * Author: Elanna Stephenson
 *
 * Created on October 25, 2015, 12:45 AM
 * 
 * Utility vector wrapper class for linear algebra operations.
 * Class and method definitions.
 */

/*!
 \file Vector.hpp
 Header definition for Vector wrapper class
 */


#ifndef VECTOR_HPP
#define	VECTOR_HPP

#include <Eigen/Core>
#include <Eigen/Dense>

#include "ForwardVectorDeclarations.hpp"
#include "Normal.hpp"
#include "Point.hpp"

namespace SCPPR {

    //! 3D Vector class
    /*!
     A wrapper class for the Vector4f to provide vector behaviour while
     transforming.
     */
    class Vector {
        
    public:

        // constructor declarations --------------------------------------------

        //! Default constructor
        /*!
         Creates a Vector of {0,0,0}
         */
        Vector();

        //! Parameterized constructor
        /*!
         Creates a Vector with chosen coordinates
         */
        Vector(float xArg, float yArg, float zArg);

        //! Array constructor
        /*!
         Constructs a Vector using float values in passed array.
         */
        Vector(float *coords);

        //! Explicit constructor
        /*!
         Constructs a Vector containing the passed Eigen::Vector4f
         */
        Vector(Eigen::Vector4f copy);

        //! Copy constructor
        /*!
         Creates a copy of the passed Vector
         */
        Vector(const Vector& copy);
        
        //! Normal copy constructor
        /*!
         Constructs a Vector using the coordinates in the passed Normal
         */
        Vector(const Normal& normalCopy);
        
        //! Point copy constructor
        /*!
         Constructs a Vector using the coordinates in the passed Point
         */
        Vector(const Point& pointCopy);

        // end constructor declarations-----------------------------------------

        // accessor declarations------------------------------------------------

        //! Returns X component of wrapped vector
        float GetX() const;

        //! Returns Y component of wrapped vector
        float GetY() const;

        //! Returns Z component of wrapped vector
        float GetZ() const;

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
         \param newContents The new contents of the Vector wrapper
         */
        void SetContents(Eigen::Vector4f newContents);

        // end accessor declarations--------------------------------------------

        // maths methods--------------------------------------------------------

        //! Returns the magnitude of the vector
        float GetMagnitude() const;

        //! Returns the magnitude of the vector, squared
        float GetSquaredMagnitude() const;

        //! Normalizes the vector
        void Normalize();

        // debug methods--------------------------------------------------------

        //! Displays the contents of the vector in the console.
        void DisplayContents() const;

        //! Destructor
        ~Vector();


        // begin operator overloads---------------------------------------------
        
        //! Addition of two vectors
        Vector operator+ (const Vector& otherVector) const;
        
        //! Unary addition of this vector with a second vector
        Vector& operator+= (const Vector& otherVector);
        
        //! Subtraction of two vectors
        Vector operator- (const Vector& otherVector) const;
        
        //! Unary subtraction of this vector with a second vector
        Vector& operator-= (const Vector& otherVector);
        
        //! Scalar multiplication with multiplar on right hand side
        Vector operator* (const float scalar) const;
        
        //! Scalar division
        Vector operator/ (const float scalar) const;
        
        //! Dot product
        float operator* (const Vector& secondVector) const;
        
        //! Cross product
        Vector operator^ (const Vector& secondVector) const;
        
        //! Assignment operator, vector to a vector
        Vector& operator= (const Vector& rightSide);
        
        //! Negation operator
        Vector operator- (void) const;
        
        //! Dot product of a normal and a vector with the normal on the right
        float operator* (const Normal& secondNormal) const;
        
        //! Addition of a normal and a vector with the normal on the right
        Vector operator+ (const Normal& secondNormal) const;
        
    private:
        // member declarations

    protected:
        Eigen::Vector4f coordinates; //!< Coordinates of vector
    };

    inline Vector Vector::operator+ (const Vector& otherVector) const {
        return Vector(coordinates + otherVector.coordinates);        
    }
    
    inline Vector& Vector::operator+= (const Vector& otherVector) {
        coordinates = coordinates + otherVector.coordinates;
        return(*this);
    }
    
    inline Vector Vector::operator- (const Vector& otherVector) const {
        return Vector(coordinates - otherVector.coordinates);
    }
    
    inline Vector& Vector::operator-= (const Vector& otherVector) {
        coordinates = coordinates - otherVector.coordinates;
        return(*this);
    }
    
    inline Vector Vector::operator* (const float scalar) const {
        return Vector(coordinates * scalar);
    }
    
    inline Vector Vector::operator/ (const float scalar) const {
        return Vector(coordinates / scalar);
    }
    
    inline Vector& Vector::operator= (const Vector& otherVector) {
        // check if assignment of the same vector
        if(this == &otherVector)
            return(*this);
        
        coordinates = otherVector.coordinates;
        return(*this);
    }
    
    inline float Vector::operator* (const Vector& otherVector) const {
        return coordinates.dot(otherVector.coordinates);
    }
    
    
    inline Vector Vector::operator^ (const Vector& secondVector) const {
        //Create temporary Vector3f for cross product
        Eigen::Vector3f vect1 (coordinates.data());
        Eigen::Vector3f vect2 (secondVector.coordinates.data());
        Eigen::Vector3f crossProduct = vect1.cross(vect2);
        return Vector(crossProduct.data());
    }
    
    inline Vector Vector::operator- (void) const {
        return Vector(-coordinates);
    }
    
    //! Multiplication of a vector by a scalar on the left side
    Vector operator* (const float scalar, const Vector& vector);
    
    inline Vector operator* (const float scalar, const Vector& vector) {
        return Vector(scalar * vector.GetContents());
    }
};


#endif	/* VECTOR_HPP */

