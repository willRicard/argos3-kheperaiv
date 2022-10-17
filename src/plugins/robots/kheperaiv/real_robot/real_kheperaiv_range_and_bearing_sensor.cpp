/**
 * @file <argos3/plugins/robots/generic/control_interface/ci_range_and_bearing_sensor.cpp>
 *
 * @author Guillaume Ricard <guillaume.ricard@polymtl.ca>
 */

#include "real_kheperaiv_range_and_bearing_sensor.h"

#ifdef ARGOS_WITH_LUA
#include <argos3/core/wrappers/lua/lua_utility.h>
#endif

namespace argos {

   /****************************************/
   /****************************************/

  CRealKheperaIVRangeAndBearingSensor::CRealKheperaIVRangeAndBearingSensor(knet_dev_t *pt_dspic) : CRealKheperaIVDevice(pt_dspic) {
  }

  void CRealKheperaIVRangeAndBearingSensor::Do(Real f_elapsed_time) {

  }

   const CRealKheperaIVRangeAndBearingSensor::TReadings& CRealKheperaIVRangeAndBearingSensor::GetReadings() const {
     return m_tReadings;
   }

   /****************************************/
   /****************************************/
#ifdef ARGOS_WITH_LUA
   void CRealKheperaIVRangeAndBearingSensor::CreateLuaState(lua_State* pt_lua_state) {
   }
#endif

   /****************************************/
   /****************************************/

#ifdef ARGOS_WITH_LUA
   void CRealKheperaIVRangeAndBearingSensor::ReadingsToLuaState(lua_State* pt_lua_state) {
   }
#endif

   /****************************************/
   /****************************************/

   CRealKheperaIVRangeAndBearingSensor::SPacket::SPacket() :
      Range(0.0f) {}

   /****************************************/
   /****************************************/

}
