#include "Quaternion.h"
#include "Matrix3.h"
#include "Vector3.h"

double Quaternion::Modulus()
{ 
	return sqrt(w * w + x * x + y * y + z * z); 
}

Quaternion Quaternion::Normalise()
{
	double m = w * w + x * x + y * y + z * z;
	if (m > 0.001)
	{
		m = sqrt(m);
		return Quaternion(w / m, x / m, y / m, z / m);
	}
	else
	{
		return Quaternion(1, 0, 0, 0);
	}
}

Quaternion Quaternion::Conjugate()
{
	return Quaternion(w, -x, -y, -z);
}


void Quaternion::FromAxisAngle(Vector3new axis, double angleRadian)
{
	double m = axis.Length();
	if (m > 0.0001)
	{
		double ca = acos(angleRadian / 2);
		double sa = asin(angleRadian / 2);
		x = axis.x / m * sa;
		y = axis.y / m * sa;
		z = axis.z / m * sa;
		w = ca;
	}
	else
	{
		w = 1; x = 0; y = 0; z = 0;
	}
}

Quaternion Quaternion::Multiply(Quaternion _q)
{
	double nw = _q.w *  w - _q.x *  x - _q.y *  y - _q.z *  z;
	double nx = _q.w *  x + _q.x *  w + _q.y *  z - _q.z *  y;
	double ny = _q.w *  y + _q.y *  w + _q.z *  x - _q.x *  z;
	double nz = _q.w *  z + _q.z *  w + _q.x *  y - _q.y *  x;
	return Quaternion(nw, nx, ny, nz);
}

Quaternion Quaternion::Copy()
{
	return Quaternion(x, y, z, w);
}
//                  -1
// V'=q*V*q     ,

Vector3new Quaternion::Rotate(Vector3new pt, int _angle)
{
	Quaternion axis, rotate;
	axis = Normalise();
	double angleRad = acos(-1) / 180 * _angle;
	rotate = Quaternion(acos(angleRad / 2), asin(angleRad / 2) * axis.x, asin(angleRad / 2) * axis.y, asin(angleRad / 2) * axis.z);
	Quaternion conjugate = rotate.Conjugate();
	Quaternion qNode = Quaternion(0, pt.x, pt.y, pt.z);
	qNode = rotate * qNode * conjugate;
	return Vector3new(qNode.x, qNode.y, qNode.z);
}

// Multiplying q1 with q2 is meaning of doing q2 firstly then q1
Quaternion Quaternion::operator+(Quaternion q1)
{
	return Quaternion(q1.w + w, q1.x + x, q1.y + y, q1.z + z);
}

Quaternion  Quaternion::operator -(Quaternion q1)
{
	return Quaternion(-q1.w, -q1.x, -q1.y, -q1.z);
}

Quaternion  Quaternion::operator -(Quaternion q1)
{
	return Quaternion(q1.w - w, q1.x - x, q1.y - y, q1.z - z);
}


Quaternion  Quaternion::operator *( double s)
{
	return  Quaternion(w * s, x * s, y * s, z * s);
}

Quaternion  Quaternion::operator *(float s)
{
	return Quaternion(w * s, x * s, y * s, z * s);
}

 Quaternion  Quaternion::operator *(int s)
{
	return  Quaternion(w * s, x * s, y * s, z * s);
}

Quaternion  Quaternion::operator *(double s)
{
	return  Quaternion(w * s, x * s, y * s, z * s);
}

Quaternion  Quaternion::operator *(float s)
{
	return Quaternion(w * s, x * s, y * s, z * s);
}

Quaternion  Quaternion::operator *(int s)
{
	return Quaternion(w * s, x * s, y * s, z * s);
}

Quaternion  Quaternion::operator *(Quaternion q1)
{
	double nw = q1.w * w - q1.x * x - q1.y * y - q1.z * z;
	double nx = q1.w * x + q1.x * w + q1.y * z - q1.z * y;
	double ny = q1.w * y + q1.y * w + q1.z * x - q1.x * z;
	double nz = q1.w * z + q1.z * w + q1.x * y - q1.y * x;
	return  Quaternion(nw, nx, ny, nz);
}

