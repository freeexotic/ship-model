#pragma once

namespace Math
{
double abs(double value);
double sign(double value);

double min(double lhs, double rhs);
double max(double lhs, double rhs);
double clamp(double min, double value, double max);

double sqrt(double value);
double pow(double lhs, double rhs);

double deg2rad(double a);
double rad2deg(double a);

double cos(double a);
double sin(double a);
double tan(double a);

double atan(double a);

double angle(double x, double y);
double hypot(double x, double y);

double heading(double a);
double difference(double a);
double traverse(double a);
double reverse(double a);
}
