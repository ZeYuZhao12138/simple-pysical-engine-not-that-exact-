#include <iostream>
#include <typeinfo>
#include <fstream>
#include <iostream>
#include "class_diction.h"
#include "mytool.h"
using namespace std;

//point P1;
//point::initial_point(&P1);   //初始化的点的速度为x方向1，而没有受力的原因加速度为0
//P1.m_speed.set_real_xy(1, 1);  //初始化之后可以设置初始速度
//
//Force F1;
//Force F2;
//P1.m_forces.append_force(&F1);
//P1.m_forces.append_force(&F2);
//P1.update_accelerate();  //添加完力之后直接使用更新加速度的选项可以把力和加速度同时更新
//F1.set_length(1);
//F1.set_radian(PI/2);
//P1.update_accelerate();
//P1.m_acceleration.show_physical_vector();
//P1.m_speed.show_physical_vector();
//P1.update();
//P1.show_position();
//P1.update();
//P1.show_position();
//P1.update();
//P1.show_position();
//P1.update();
//P1.show_position();

int main() {


    point P1;
    point P2;
    point P3;
    P1.set_position_x(-3);
    P1.set_position_y(-1);
    P1.m_speed.set_real_xy(0.1, -0.2);
//    P2.set_position_x(1);
//    P2.set_position_y(2);
//    P3.set_position_x(1);
//    P3.set_position_y(-1);
//    P1.show_position();
//    P2.show_position();
//    P3.show_position();
    Gravity G21(&P1, &P2);
//    Gravity G31(&P1, &P3);
//    Gravity G12(&P2, &P1);
//    Gravity G32(&P2, &P3);
//    Gravity G13(&P3, &P1);
//    Gravity G23(&P3, &P2);
    P1.m_forces.show_forces();
    P1.update_accelerate();
//    P2.update_accelerate();
//    P3.update_accelerate();
    P1.m_acceleration.show_physical_vector();
    P1.m_speed.show_physical_vector();
    cout << "*********" << endl;


    ofstream outfile;
    outfile.open("output.txt");
    cout << "Writing to the file" << endl;

    for (int i = 0; i < 20000; i++)
    {
        P1.update_position();
//        P2.update_position();
//        P3.update_position();
        P1.update_state();
//        P2.update_state();
//        P3.update_state();
//        P1.m_forces.AddedForce.show_physical_vector();
//        P1.m_speed.show_physical_vector();
//        P1.show_position();
        outfile << P1.get_position_x() << endl;
        outfile << P1.get_position_y() << endl;
//        outfile << P2.get_position_x() << endl;
//        outfile << P2.get_position_y() << endl;
//        outfile << P3.get_position_x() << endl;
//        outfile << P3.get_position_y() << endl;
        cout << endl;
    }

    outfile.close();









//    point P2;
//    point::initial_point(&P2);
//    P2.m_speed.show_physical_vector();





    return 0;
}
