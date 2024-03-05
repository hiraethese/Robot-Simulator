#include "controller.h"

void contr_create_core(){}

void contr_delete_core(){
    delete ps_core;
}

void contr_set_new_settings(bool flagNewMap, std::string newMapValue, bool flagNewSpeed, int newSpeedValue, bool flagNewAngle, int newAngleValue){
    if(flagNewMap){
        ps_core->map = newMapValue;
        ps_core->simIsReady = true;
        std::cout << "SET SIM IS READY " << ps_core->simIsReady << std::endl;
    }
    if(flagNewSpeed){
        ps_core->speed = newSpeedValue;
    }
    if(flagNewAngle){
        ps_core->angle = newAngleValue;
    }
}

std::string contr_get_map_value(){
    return ps_core->map;
}

int contr_get_speed_value(){
    return ps_core->speed;
}

int contr_get_angle_value(){
    return ps_core->angle;
}

bool contr_is_sim_ready(){
    return ps_core->simIsReady;
}

bool contr_is_sim_run(){
    return ps_core->simIsRun;
}

void contr_run_sim_command(){
    ps_core->simIsRun = true;
    std::cout << "RUN SIM IS READY " << ps_core->simIsRun << std::endl;
}

void contr_stop_sim_command(){
    ps_core->simIsRun = false;
    std::cout << "STOP SIM IS READY " << ps_core->simIsRun << std::endl;
}



void contr_forward_move_sig(){

}

void contr_left_rotate_move_sig(){

}

void contr_right_rotate_move_sig(){

}

void contr_stop_move_sig(){

}
