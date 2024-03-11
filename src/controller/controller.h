#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <string>
#include <iostream>
#include "PseudoCore.h"

void contr_create_core();
void contr_delete_core();

/**
 * @brief set_new_settings  : give for core new settings value by user
 * @param flagNewMap        : flag is need updating for map
 * @param newMapValue       : absolute path to map
 * @param flagNewSpeed      : flag is need updating for speed
 * @param newSpeedValue     : new speed value
 * @param flagNewAngle     : flag is need updating for Angle
 * @param newAngleValue    : new Angle value
 */
void contr_set_new_settings(bool flagNewMap, std::string newMapValue, bool flagNewSpeed, int newSpeedValue, bool flagNewAngle, int newAngleValue);

/**
 * @brief get_map_value getter with actual path to map
 * @return
 */
std::string contr_get_map_value();

/**
 * @brief get_speed_value   : getter with actual speed value
 * @return                  : int
 */
int contr_get_speed_value();

/**
 * @brief get_angle_value  : getter with actual angle value
 * @return                  : int
 */
int contr_get_angle_value();

/**
 * @brief is_simulation_map_ready   : flag is simulation ready to starting
 * @return                          : bool
 */
bool contr_is_sim_ready();

/**
 * @brief is_simulation_run : flag is simulation actual running
 * @return                  : bool
 */
bool contr_is_sim_run();

/**
 * @brief run_sim_command : run activate simulation running
 */
void contr_run_sim_command();

/**
 * @brief stop_sim_command : stopped simulation running
 */
void contr_stop_sim_command();


/**
 * @brief contr_forward_move_sig : inform core that users robot make forward moving
 */
void contr_forward_move_sig();

/**
 * @brief contr_left_turn_move_sig : inform core that users robot make left rotate moving
 */
void contr_left_rotate_move_sig();

/**
 * @brief contr_right_rotate_move_sig : inform core that users robot make right rotate moving
 */
void contr_right_rotate_move_sig();

/**
 * @brief contr_stop_move_sig : inform core that users robot make stop of moving
 */
void contr_stop_move_sig();

void create_new_sim_obj(unsigned w, unsigned h, unsigned type_of_sim_obj);

#endif // CONTROLLER_H
