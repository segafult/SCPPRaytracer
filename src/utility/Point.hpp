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

 * File:   Point.hpp
 * Author: Elanna Stephenson
 *
 * Created on October 26, 2015, 2:52 PM
 * 
 * Utility vector wrapper class for linear algebra operations.
 * Class and method definitions
 */

#ifndef POINT_HPP
#define	POINT_HPP

#include <Eigen/Core>
#include <Eigen/Dense>

#include "ForwardVectorDeclarations.hpp"
#include "Normal.hpp"
#include "Vector.hpp"

namespace SCPPR {
    
    //! 3D point class
    /*!
     A wrapper class for vector4f to provide point behaviour while transforming
     */
    class Point {
    public:
        // begin constructor declarations---------------------------------------
        
        //! Default constructor
        /*!
         Constructs a point of {0,0,0}
         */
        Point();
        
        //! Parameterized constructor
        /*!
         Constructs a point of {xArg,yArg,zArg}
         */
        Point(float xArg, float yArg, float zArg);
        
        //! Array constructor
        /*!
         Constructs a point with the values stored at coords
         */
        Point(float *coords);
        
        //! Explicit constructor
        /*!
         Constructs a point to wrap the provided Vector4f
         */
        Point(Eigen::Vector4f copy);
        
        //! Copy constructor
        /*!
         Clones the provided point
         */
        Point(const Point& copy);
        
        //! Normal constructor
        /*!
         Clones the provided normal as a point
         */
        Point(const Normal& normal);
        
        //! Vector constructor
        /*!
         Clones the provided vector as a point
         */
        Point(const Vector& normal);
        
        // end constructor declarations-----------------------------------------
        
        // begin accessor declarations------------------------------------------
        
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
        
        
        //! Displays contents of the point using std::cout
        void DisplayContents() const;
        
        // begin operator overloads---------------------------------------------
        
        //! Addition of a vector to a point
        Point operator+ (const Vector& vector) const;
        
        //! Subtraction of a vector from a point
        Point operator- (const Vector& vector) const;
        
        //! Subtraction of a point from a point to yield a vector
        Vector operator- (const Point& point) const;
        
        //! Assignment operator
        Point& operator= (const Point& point);
        
        //! Multiplication by a scalar with scalar on the right
        Point operator* (const float scalar) const;
        
        // end operator overloads-----------------------------------------------
        
        //! Destructor
        ~Point();

        
    protected:
        
        Eigen::Vector4f coordinates; //!< Wrapped vector
    };
    
    
    // Assignment operator
    inline Point& Point::operator= (const Point& point)  {
        //Check for self-assignment
        if(this == &point)
            return (*this);
        // Assign passed point coordinates to coordinates
        coordinates = point.coordinates;
        return(*this);
    }
    
    // Scalar multiplication, scalar on right
    inline Point Point::operator* (const float scalar) const {
        return Point(coordinates * scalar);
    }
    
    //! Multiplication of a point by a scalar with scalar on the left
    Point operator* (const float scalar, const Point& point);
    
    // Scalar multiplication scalar on left
    inline Point operator* (const float scalar, const Point& point) {
        return Point(scalar * point.GetContents());
    }
}

#endif	/* POINT_HPP */

