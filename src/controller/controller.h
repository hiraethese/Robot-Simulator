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
 * @param flagNewCorner     : flag is need updating for corner
 * @param newCornerValue    : new corner value
 */
void contr_set_new_settings(bool flagNewMap, std::string newMapValue, bool flagNewSpeed, int newSpeedValue, bool flagNewCorner, int newCornerValue);

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
 * @brief get_corner_value  : getter with actual corner value
 * @return                  : int
 */
int contr_get_corner_value();

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

#endif // CONTROLLER_H
