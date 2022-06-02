//
// Created by zhao.zeyu on 2022/04/27.
//
#include "class_diction.h"
#include <iostream>
#include <math.h>
#include "mytool.h"
#include <iomanip>

using namespace std;


// 显示二次元空间的向量方向
Vector::Vector()
{
    this->m_x = 1.0;
    this->m_y = 0.0;
    this->m_start_x = 0.0;
    this->m_start_y = 0.0;
    this->m_x_pin = &this->m_x;
    this->m_y_pin = &this->m_y;
    this->m_start_x_pin = &this->m_start_x;
    this->m_start_y_pin = &this->m_start_y;
    this->m_length = 1.0;
}

void Vector::show_direction() const // Vector 作用域下的成员函数
{
    cout << "指向为：x = " << *this->m_x_pin - *this->m_start_x_pin << "\t";
    cout << "y = " << *this->m_y_pin - *this->m_start_y_pin << endl;
}

void Vector::show_length() const
{
    cout << "length = " << this->m_length << endl;
}

void Vector::show_physical_vector() const
{
    double vector_length = pow(pow(*this->m_x_pin - *this->m_start_x_pin,2) +
                           pow(*this->m_y_pin - *this->m_start_y_pin,2), 0.5);
    cout << "real_x :" << (*this->m_x_pin - *this->m_start_x_pin) * (this->m_length / vector_length) << "\t";
    cout << "real_y :" << (*this->m_y_pin - *this->m_start_y_pin) * (this->m_length / vector_length) << endl;
}
// 设置x坐标
void Vector::set_end_x(double value)
{
    *this->m_x_pin = value;
}
// 设置y坐标
void Vector::set_end_y(double value)
{
    *this->m_y_pin = value;
}

void Vector::set_radian(double value)
{
    double vector_length = pow(pow(*this->m_x_pin - *this->m_start_x_pin,2) +
                               pow(*this->m_y_pin - *this->m_start_y_pin,2), 0.5);
    *this->m_x_pin = myround(cos(value) * vector_length, 7) + *this->m_start_x_pin;
    *this->m_y_pin = myround(sin(value) * vector_length, 7) + *this->m_start_y_pin;
}

void Vector::set_length(double value)
{
    this->m_length = value;
}

void Vector::set_real_xy(double value_x, double value_y)
{
    if (value_x == 0 && value_y == 0)
    {
        this->m_length = 0;
    }
    else
    {
        this->m_length = pow(pow(value_x,2) + pow(value_y,2), 0.5);
        *this->m_x_pin = value_x + *this->m_start_x_pin;
        *this->m_y_pin = value_y + *this->m_start_y_pin;
    }
}

void Vector::set_start_x(double value)
{
    *this->m_start_x_pin = value;
}

void Vector::set_start_y(double value)
{
    *this->m_start_y_pin = value;
}

void Vector::show_start_point() const
{
    cout << "向量的起始点：x = " << *this->m_start_x_pin << "\t";
    cout << "y = " << *this->m_start_y_pin << endl;
}

void Vector::show_end_point() const
{
    cout << "向量的终止点：x = " << *this->m_x_pin << "\t";
    cout << "y = " << *this->m_y_pin << endl;
}

// 获取x坐标
double Vector::get_x()
{
    return *m_x_pin - *m_start_x_pin;
}
//获取y坐标
double Vector::get_y()
{
    return *m_y_pin - *m_start_y_pin;
}
// 显示当前坐标的弧度制角度
void Vector::show_radian() const
{
    cout << "radian = " << atan2(*this->m_y_pin - *this->m_start_y_pin,
                                 *this->m_x_pin - *this->m_start_x_pin) << endl;
}
//获取弧度制角度
double Vector::get_radian()
{
    return atan2(*this->m_y_pin - *this->m_start_y_pin,
                 *this->m_x_pin - *this->m_start_x_pin);
}
//获取向量模长
double Vector::get_length()
{
    return m_length;
}

double Vector::get_real_x() const
{
    double vector_length = pow(pow(*this->m_x_pin - *this->m_start_x_pin,2) +
                               pow(*this->m_y_pin - *this->m_start_y_pin,2), 0.5);
    return (*this->m_x_pin - *this->m_start_x_pin) * (this->m_length / vector_length);
}

double Vector::get_real_y() const
{
    double vector_length = pow(pow(*this->m_x_pin - *this->m_start_x_pin,2) +
                               pow(*this->m_y_pin - *this->m_start_y_pin,2), 0.5);
    return (*this->m_y_pin - *this->m_start_y_pin) * (this->m_length / vector_length);
}





// Force 部分
Force::Force()
{
    this->set_start_x(0.0);
    this->set_start_y(0.0);
    this->set_end_x(1.0);
    this->set_end_y(0.0);
    this->set_length(0.0);
}

void Force::bunding_affect_point(point * P)
{
    this->m_start_x_pin = &P->m_position_x;
    this->m_start_y_pin = &P->m_position_y;
}

void Force::unbunding_affect_point()    //解绑完成之后一定要先赋值，否则作用点会回到绑定前的位置
{
    this->m_start_x_pin = &this->m_start_x;
    this->m_start_y_pin = &this->m_start_y;
}


void Force::bunding_point_to(point *P)
{
    this->m_x_pin = &P->m_position_x;
    this->m_y_pin = &P->m_position_y;
}

void Force::unbunding_point_to()
{
    this->m_x_pin = &this->m_x;
    this->m_y_pin = &this->m_y;
}

void Force::update_length()
{

}


void ForceArray::show_forces() const
{
    cout << "共有" << this->size << "个力" << endl;
    for(int i = 0; i < this->size; i++)
    {
        cout << "第" << i + 1 << "个力的方向为：" << "\t";
        Force_pin_list[i]->show_direction();
    }
}

void ForceArray::append_force(Force * F)
{
    if (this->size >= MAXaddingForce)
    {
        cout << "力的个数超出最大值！" << endl;
        cout << "添加失败" << endl;
    }
    else
    {
        Force_pin_list[size] = F;
        size++;
        cout << "添加成功" << endl;
    }

}

void ForceArray::update_added_force()
{
    double x = 0;
    double y = 0;
    if (this->size == 0)
    {
        this->AddedForce.set_length(0);
    }
    else
    {
        for (int i = 0; i < this->size; i++)
        {
            x += this->Force_pin_list[i]->get_real_x();
            y += this->Force_pin_list[i]->get_real_y();
        }
        double length = pow(pow(x,2) + pow(y,2), 0.5);
        this->AddedForce.set_real_xy(x, y);
        this->AddedForce.set_length(length);
    }
}

void ForceArray::show_added_force()
{
    cout << "合力的物理向量的指向为：x = " << this->AddedForce.get_real_x() << "\t";
    cout << "y = " << this->AddedForce.get_real_y() << endl;
}

void ForceArray::update_all_forces()
{
    for (int i = 0; i < this->size; i++)
    {
        this->Force_pin_list[i]->update_length();
    }
}




Gravity::Gravity(point * AffectP, point * PointP)
{
    this->m_AffectP = AffectP;
    this->m_PointP = PointP;
    this->bunding_affect_point(this->m_AffectP);
    this->bunding_point_to(this->m_PointP);
    double distance = pow(pow(this->m_AffectP->get_position_x() - this->m_PointP->get_position_x(),2) +
                          pow(this->m_AffectP->get_position_y() - this->m_PointP->get_position_y(),2), 0.5);
    this->m_length = Grav * this->m_AffectP->get_mass() * this->m_PointP->get_mass() / pow(distance, 2);

    AffectP->m_forces.append_force(this);
}

void Gravity::link_gravity()
{
    this->bunding_affect_point(this->m_AffectP);
    this->bunding_point_to(this->m_PointP);

    double distance = pow(pow(this->m_AffectP->get_position_x() - this->m_PointP->get_position_x(),2) +
                          pow(this->m_AffectP->get_position_y() - this->m_PointP->get_position_y(),2), 0.5);
    this->m_length = Grav * this->m_AffectP->get_mass() * this->m_PointP->get_mass() / pow(distance, 2);
}

void Gravity::update_length()
{
    double distance = pow(pow(this->m_AffectP->get_position_x() - this->m_PointP->get_position_x(),2) +
                          pow(this->m_AffectP->get_position_y() - this->m_PointP->get_position_y(),2), 0.5);
    this->m_length = Grav * this->m_AffectP->get_mass() * this->m_PointP->get_mass() / pow(distance, 2);
}

double Gravity::get_gravity_length()
{
    return this->m_length;
}

void Gravity::show_gravity_length()
{
    cout << "gravity = " << this->m_length << endl;
}



Elestic::Elestic(point * AffectP, point * PointP)
{
    this->m_AffectP = AffectP;
    this->m_PointP = PointP;
    this->bunding_affect_point(this->m_AffectP);
    this->bunding_point_to(this->m_PointP);
    double distance = pow(pow(this->m_AffectP->get_position_x() - this->m_PointP->get_position_x(),2) +
                          pow(this->m_AffectP->get_position_y() - this->m_PointP->get_position_y(),2), 0.5);
    this->m_length = ElesticK * distance;
    AffectP->m_forces.append_force(this);
}

void Elestic::update_length()
{
    double distance = pow(pow(this->m_AffectP->get_position_x() - this->m_PointP->get_position_x(),2) +
                          pow(this->m_AffectP->get_position_y() - this->m_PointP->get_position_y(),2), 0.5);
    this->m_length = ElesticK * distance;
}




// point部分
point::point()
{
    this->m_position_x = 0.0;
    this->m_position_y = 0.0;
    this->m_mass = 1.0;  //kg
    this->m_speed.set_length(0.0);
}

void point::set_position_x(double value)
{
    this->m_position_x = value;
}

void point::set_position_y(double value)
{
    this->m_position_y = value;
}

void point::set_mass(double value)
{
    this->m_mass = value;
}

void point::show_position() const
{
    cout << "x坐标 = " << this->m_position_x << '\t';
    cout << "y坐标 = " << this->m_position_y << endl;
}

void point::show_mass() const
{
    cout << "mass = " << this->m_mass << endl;
}


double point::get_position_x() const
{
    return this->m_position_x;
}

double point::get_position_y() const
{
    return this->m_position_y;
}

double point::get_mass() const
{
    return this->m_mass;
}



void point::update_position()
{
    this->m_position_x = this->m_position_x + this->m_speed.get_real_x() * deltaT +
                         this->m_acceleration.get_real_x() * pow(deltaT, 2) / 2;
    this->m_position_y = this->m_position_y + this->m_speed.get_real_y() * deltaT +
                         this->m_acceleration.get_real_y() * pow(deltaT, 2) / 2;
}

void point::update_state()
{
    //从力开始更新下一时段状态
    this->m_speed.set_real_xy(this->m_speed.get_real_x() + this->m_acceleration.get_real_x() * deltaT,
                              this->m_speed.get_real_y() + this->m_acceleration.get_real_y() * deltaT);
    this->m_forces.update_all_forces();
    this->m_forces.update_added_force();
    this->m_acceleration.set_real_xy(this->m_forces.AddedForce.get_real_x()/this->m_mass,
                                     this->m_forces.AddedForce.get_real_y()/this->m_mass);
}


void point::update_accelerate()  //最开始的使用用一下就行
{
    this->m_forces.update_all_forces();
    this->m_forces.update_added_force();
    this->m_acceleration.set_real_xy(this->m_forces.AddedForce.get_real_x()/this->m_mass,
                                     this->m_forces.AddedForce.get_real_y()/this->m_mass);
}

void point::initial_point(point * P)
{
    P->m_forces.update_added_force();
    P->m_acceleration.set_real_xy(P->m_forces.AddedForce.get_real_x()/P->m_mass,
                                  P->m_forces.AddedForce.get_real_y()/P->m_mass);
}