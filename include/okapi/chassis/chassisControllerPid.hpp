/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#ifndef _OKAPI_CHASSISCONTROLLERPID_HPP_
#define _OKAPI_CHASSISCONTROLLERPID_HPP_

#include "okapi/chassis/chassisController.hpp"
#include "okapi/control/pidController.hpp"
#include <memory>

namespace okapi {
class ChassisControllerPID : public virtual ChassisController {
  public:
  ChassisControllerPID(const ChassisModelParams &imodelParams,
                       const PIDControllerParams &idistanceParams,
                       const PIDControllerParams &iangleParams)
    : ChassisController(imodelParams), distancePid(idistanceParams), anglePid(iangleParams) {
  }

  ChassisControllerPID(const ChassisModel &imodel, const PIDControllerParams &idistanceParams,
                       const PIDControllerParams &iangleParams)
    : ChassisController(imodel), distancePid(idistanceParams), anglePid(iangleParams) {
  }

  ChassisControllerPID(const ChassisModelParams &imodelParams, const PIDController &idistance,
                       const PIDController &iangle)
    : ChassisController(imodelParams), distancePid(idistance), anglePid(iangle) {
  }

  ChassisControllerPID(const ChassisModel &imodel, const PIDController &idistance,
                       const PIDController &iangle)
    : ChassisController(imodel), distancePid(idistance), anglePid(iangle) {
  }

  virtual ~ChassisControllerPID();

  /**
   * Drives the robot straight.
   *
   * @param itarget Distance to travel
   */
  void driveStraight(const int itarget) override;

  /**
   * Turns the robot clockwise in place.
   *
   * @param idegTarget Degrees to turn for
   */
  void pointTurn(float idegTarget) override;

  protected:
  PIDController distancePid, anglePid;
};
} // namespace okapi

#endif