#pragma once

class Quaternion
{

public:
	double x, y, z, w;

	Quaternion::Quaternion()
	{
		w = 0; x = 0; y = 0; z = 0;
	}

	Quaternion::Quaternion(double _w, double _x, double _y, double _z)
	{
		w = _w; x = _x; y = _y; z = _z;
	}

	Quaternion::Quaternion(double _w, Vector3new v)
	{
		w = _w; 
		x = v.x;
		y = v.y; 
		z = v.z;
	}

	double Modulus();
	Quaternion Normalise();
	Quaternion Conjugate();
	void Quaternion::FromAxisAngle(Vector3new axis, double angleRadian);
	Quaternion Multiply(Quaternion _q);
	Quaternion Copy();
	Vector3new Rotate(Vector3new pt, int _angle);

	Quaternion operator +(Quaternion q1);
	Quaternion operator -(Quaternion q1);
	Quaternion operator -(Quaternion q1);
	Quaternion operator *(double s);
	Quaternion operator *(float s);
	Quaternion operator *(int s);

	Quaternion operator *(Quaternion q1);
};