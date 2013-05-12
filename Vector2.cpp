#include "Vector2.h"
#include <math.h>



float min(float f1, float f2)
{
	return (f1 < f2) ? f1 : f2;
}

float max(float f1, float f2)
{
	return (f1 > f2) ? f1 : f2;
}

float clamp(float value, float minimum, float maximum)
{
	return max(minimum, min(maximum, value));
}

float lerp(float value1, float value2, float amount)
{
	return value1 + ((value2 - value1) * amount );
}

Vector2 Vector2::Zero(0.0f, 0.0f);
Vector2 Vector2::One(1.0f, 1.0f);
Vector2 Vector2::UnitX(1.0f, 0.0f);
Vector2 Vector2::UnitY(0.0f, 1.0f);

Vector2::Vector2(float x, float y)
: X(x)
, Y(y)
{}

Vector2::Vector2(float value)
: X(value)
, Y(value)
{}

Vector2::Vector2()
: X(0)
, Y(0)
{}

float Vector2::Length()
{
        return sqrt(LengthSquared());
}

float Vector2::LengthSquared()
{
        return (X * X) + (Y * Y);
}

/*static*/ float Vector2::Distance(const Vector2& value1, const Vector2& value2)
{
        return Vector2(value1 - value2).Length();
}

/*static*/ float Vector2::DistanceSquared(const Vector2& value1, const Vector2& value2)
{
        return Vector2(value1 - value2).LengthSquared();

}

/*static*/ float Vector2::Dot(const Vector2& value1, const Vector2& value2)
{
        return ((value1.X * value2.X) + (value1.Y * value2.Y));
}

void Vector2::Normalize()
{
        float len = Length();


        if( len < 1e-7f )
        {
                if( Y > X )
                        *this = UnitY;
                else
                        *this = UnitX;
        }
        else
        {
                *this = *this / len;
        }
}

/*static*/ Vector2 Vector2::Normalize(const Vector2& value)
{
        Vector2 retVal(value);
        retVal.Normalize();
        return retVal;
}

/*static*/ Vector2 Vector2::Reflect(const Vector2& vector, const Vector2& normal)
{
        return vector - (normal * 2.0f * Dot(vector, normal));
}

/*static*/ Vector2 Vector2::Min(const Vector2& value1, const Vector2& value2)
{
        return Vector2(min(value1.X, value2.X), min(value1.Y, value2.Y));
}

/*static*/ Vector2 Vector2::Max(const Vector2& value1, const Vector2& value2)
{
        return Vector2(max(value1.X, value2.X), max(value1.Y, value2.Y));
}

/*static*/ Vector2 Vector2::Clamp(const Vector2& value, const Vector2& min, const Vector2& max)
{
        return Vector2(clamp(value.X, min.X, max.X), clamp(value.Y, min.Y, max.Y));
}

/*static*/ Vector2 Vector2::Lerp(const Vector2& value1, const Vector2& value2, float amount)
{
        return Vector2(lerp( value1.X, value2.X, amount ), lerp( value1.Y, value2.Y, amount ) );
}
/*static*/ Vector2 Vector2::Negate(const Vector2& value)
{
        return -value;
}

/*static*/ Vector2 Vector2::Rotate(const Vector2& value, const float radians)
{
    float c = cos(radians);
    float s = sin(radians);
    return Vector2(value.X*c-value.Y*s,value.Y*c+value.X*s);
}

bool Vector2::operator==(const Vector2 &v) const
{
        return X == v.X && Y == v.Y;
}

bool Vector2::operator!=(const Vector2 &v) const
{
        return !(*this == v);
}

Vector2 Vector2::operator-() const
{
        return Vector2::Zero - *this;
}

Vector2 Vector2::operator-(const Vector2 &v) const
{
        return Vector2(X - v.X, Y - v.Y);
}

Vector2 Vector2::operator+(const Vector2 &v) const
{
        return Vector2(X + v.X, Y + v.Y);
}

Vector2 Vector2::operator/(float divider) const
{
        return Vector2(X / divider, Y / divider);
}

Vector2 Vector2::operator*(float scaleFactor) const
{
        return Vector2(X * scaleFactor, Y * scaleFactor);
}

Vector2& Vector2::operator+=(const Vector2 &v)
{
    X += v.X;
    Y += v.Y;
    return *this;
}

Vector2& Vector2::operator-=(const Vector2 &v)
{
    X -= v.X;
    Y -= v.Y;
    return *this;
}

Vector2& Vector2::operator*=(float scaleFactor)
{
    X *= scaleFactor;
    Y *= scaleFactor;
    return *this;
}

Vector2& Vector2::operator/=(float scaleFactor)
{
    X /= scaleFactor;
    Y /= scaleFactor;
    return *this;
}