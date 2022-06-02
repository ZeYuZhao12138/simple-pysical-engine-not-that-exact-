//
// Created by zhao.zeyu on 2022/04/27.
//
#pragma once // 防止头文件重复包含
//#define Grav 6.67408e-11
#define Grav 1
#define deltaT 0.01 //秒
#define MAXaddingForce 100
#define ElesticK 1 // N/m

class Vector;
class Force;
class point;

class Vector // 头文件中类的声明
{

public:
    Vector();

    void show_direction() const;

    void show_radian() const;

    void show_length() const;

    void show_physical_vector() const;

    void set_end_x(double value);

    void set_end_y(double value);

    void set_radian(double value);

    void set_length(double value);

    void set_real_xy(double value_x, double value_y);

    void set_start_x(double value);

    void set_start_y(double value);

    void show_start_point() const;

    void show_end_point() const;

    double get_x();

    double get_y();

    double get_radian();

    double get_length();

    double get_real_x() const;

    double get_real_y() const;

protected:
    double m_x;
    double m_y;
    double m_start_x;
    double m_start_y;
    double * m_x_pin;
    double * m_y_pin;
    double * m_start_x_pin;
    double * m_start_y_pin;
    double m_length;
};


class Force: public Vector
{
public:
    Force();

    void bunding_affect_point(point * P);

    void unbunding_affect_point();

    void bunding_point_to(point * P);

    void unbunding_point_to();

    virtual void update_length();

private:

};



class ForceArray
{
public:
    void show_forces() const;

    void append_force(Force * F);

    void update_added_force();

    void show_added_force();

    void update_all_forces();

private:
    Force * Force_pin_list[MAXaddingForce];
    int size = 0;
public:
    Force AddedForce;
};



class Gravity: public Force
{

public:
    Gravity(point * AffectP, point * PointP);

    void link_gravity();   // 初始化重力

    virtual void update_length();   //初始化之后每次变动2点位置的时候需要更新重力大小

    void show_gravity_length();

    double get_gravity_length();

protected:
    point * m_AffectP;
    point * m_PointP;
};

class Elestic: public Force
{
public:
    Elestic(point * AffectP, point * PointP);

    virtual void update_length();

protected:
    point * m_AffectP;
    point * m_PointP;
};


class point
{
    friend void Force::bunding_affect_point(point * P);
    friend void Force::bunding_point_to(point *P);

public:
    point();

    void set_position_x(double value);

    void set_position_y(double value);

    void set_mass(double value);

    void show_position() const;

    void show_mass() const;

    double get_position_x() const;

    double get_position_y() const;

    double get_mass() const;

    void update_position();

    void update_state();

    void update_accelerate();

    static void initial_point(point * P);


private:
    double m_position_x;
    double m_position_y;
    double m_mass;

public:
    Vector m_speed;
    Vector m_acceleration;
    ForceArray m_forces;
};



