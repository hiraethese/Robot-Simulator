#include "controller.h"

void contr_create_core(){}

void contr_delete_core(){
    delete ps_core;
}

void contr_set_new_settings(bool flagNewMap, std::string newMapValue, bool flagNewSpeed, int newSpeedValue, bool flagNewCorner, int newCornerValue){
    if(flagNewMap){
        ps_core->map = newMapValue;
    }
    if(flagNewSpeed){
        ps_core->speed = newSpeedValue;
    }
    if(flagNewCorner){
        ps_core->corner = newCornerValue;
    }
    ps_core->simIsReady = true;
}

std::string contr_get_map_value(){
    return ps_core->map;
}

int contr_get_speed_value(){
    return ps_core->speed;
}

int contr_get_corner_value(){
    return ps_core->corner;
}

bool contr_is_sim_ready(){
    return ps_core->simIsReady;
}

bool contr_is_sim_run(){
    return ps_core->simIsRun;
}

void contr_run_sim_command(){
    ps_core->simIsRun = true;
}

void contr_stop_sim_command(){
    ps_core->simIsRun = false;
}

