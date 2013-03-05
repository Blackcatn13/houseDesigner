#ifndef POINT3D_H
#define POINT3D_H

#pragma once

class CPoint3D
{
public:
    CPoint3D(void);
    CPoint3D(float nx, float ny, float nz);
    ~CPoint3D(void);
    CPoint3D operator+(const CPoint3D p);
    CPoint3D operator-(const CPoint3D p);
    CPoint3D operator*(const CPoint3D p);
    CPoint3D &operator=(const CPoint3D p);
    CPoint3D &operator+=(const CPoint3D p);
    bool operator==(const CPoint3D p);
    float x, y, z;
};

#endif
