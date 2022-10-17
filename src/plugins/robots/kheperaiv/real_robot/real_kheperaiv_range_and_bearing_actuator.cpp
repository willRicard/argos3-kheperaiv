/**
 * @file <argos3/plugins/robots/generic/control_interface/ci_range_and_bearing_actuator.cpp>
 *
 * @author Guillaume Ricard <guillaume.ricard@polymtl.ca>
 */

#include "real_kheperaiv_range_and_bearing_actuator.h"

#ifdef ARGOS_WITH_LUA
#include <argos3/core/wrappers/lua/lua_utility.h>
#endif

namespace argos {

   /****************************************/
   /****************************************/

#ifdef ARGOS_WITH_LUA
   /*
    * The stack can have one or two values
    * - The case of one value is when you set an entire array
    * - In the case of two values, you must have:
    *   1. the idx of the data item to set
    *   2. the value of the data item in the range [0,255]
    */
   int LuaKheperaIVRABSetData(lua_State* pt_lua_state) {
     return 0;
   }
#endif

#ifdef ARGOS_WITH_LUA
   /*
    * The stack must have no values
    */
   int LuaKheperaIVRABClearData(lua_State* pt_lua_state) {
     return 0;
   }
#endif

   CRealKheperaIVRangeAndBearingActuator::CRealKheperaIVRangeAndBearingActuator(knet_dev_t *pt_dspic) : CRealKheperaIVDevice(pt_dspic) {
     m_cData.Resize(2);
   }

   void CRealKheperaIVRangeAndBearingActuator::Do(Real f_elapsed_time) {}

   /****************************************/
   /****************************************/

   size_t CRealKheperaIVRangeAndBearingActuator::GetSize() const {
     return 0;
   }
  
   /****************************************/
   /****************************************/

   void CRealKheperaIVRangeAndBearingActuator::SetData(size_t un_idx,
					    UInt8 un_value) {
   }
  
   /****************************************/
   /****************************************/

   void CRealKheperaIVRangeAndBearingActuator::ClearData() {
   }

   /****************************************/
   /****************************************/

#ifdef ARGOS_WITH_LUA
   void CRealKheperaIVRangeAndBearingActuator::CreateLuaState(lua_State* pt_lua_state) {
      CLuaUtility::StartTable(pt_lua_state, "range_and_bearing");
      CLuaUtility::AddToTable(pt_lua_state, "_instance", this);
      CLuaUtility::AddToTable(pt_lua_state, "set_data", &LuaKheperaIVRABSetData);
      CLuaUtility::AddToTable(pt_lua_state, "clear_data", &LuaKheperaIVRABClearData);
      CLuaUtility::EndTable(pt_lua_state);
   }
#endif

   /****************************************/
   /****************************************/

   void CRealKheperaIVRangeAndBearingActuator::SetData(const CByteArray& c_data) {
   }

   /****************************************/
   /****************************************/

}
