#include "controller.h"

void contr_create_core() {
    SimStart();
}

void contr_delete_core() {
    SimEnd();
}

void contr_set_new_settings(bool flagNewMap,
                            std::string newMapValue,
                            bool flagNewSpeed,
                            int newSpeedValue,
                            bool flagNewAngle,
                            int newAngleValue) {
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

std::string contr_get_map_value() {
    return ps_core->map;
}

int contr_get_speed_value() {
    if (controlledRobot == nullptr) {
        return 0;
    } else {
        return controlledRobot->GetMovement()->GetSpeed();
    }
}

int contr_get_angle_value() {
    if (controlledRobot == nullptr) {
        return 0;
    } else {
        return controlledRobot->GetMovement()->GetAngle();
    }
}

bool contr_is_sim_ready() {
    return ps_core->simIsReady;
}

bool contr_is_sim_run() {
    return ps_core->simIsRun;
}

void contr_run_sim_command() {
    ps_core->simIsRun = true;
    std::cout << "RUN SIM IS READY " << ps_core->simIsRun << std::endl;
}

void contr_stop_sim_command() {
    ps_core->simIsRun = false;
    std::cout << "STOP SIM IS READY " << ps_core->simIsRun << std::endl;
}

void contr_forward_move_sig() {
    controlledRobot->GetMovement()->MoveForward();
}

void contr_left_rotate_move_sig() {
    controlledRobot->GetMovement()->RotateLeft();
}

void contr_right_rotate_move_sig() {
    controlledRobot->GetMovement()->RotateRight();
}

void contr_stop_move_sig() {}
