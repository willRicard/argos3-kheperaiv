/**
 * @file <argos3/plugins/robots/generic/control_interface/ci_range_and_bearing_actuator.h>
 *
 * @author Guillaume Ricard <guillaume.ricard@polymtl.ca>
 */

#ifndef KHEPERAIV_RANGE_AND_BEARING_ACTUATOR_H
#define KHEPERAIV_RANGE_AND_BEARING_ACTUATOR_H

#include <argos3/core/control_interface/ci_actuator.h>
#include <argos3/core/utility/datatypes/byte_array.h>

#include <argos3/plugins/robots/generic/control_interface/ci_range_and_bearing_actuator.h>
#include <argos3/plugins/robots/kheperaiv/real_robot/real_kheperaiv_device.h>

namespace argos {

   class CRealKheperaIVRangeAndBearingActuator : public CCI_RangeAndBearingActuator,
                                                 public CRealKheperaIVDevice {

   public:

      CRealKheperaIVRangeAndBearingActuator(knet_dev_t *pt_dspic);

      virtual ~CRealKheperaIVRangeAndBearingActuator() {}

      void Do(Real f_elapsed_time);

      size_t GetSize() const;

      void SetData(const CByteArray& c_data);

      void SetData(size_t un_idx,
		   UInt8 un_value);

      void ClearData();

#ifdef ARGOS_WITH_LUA
      virtual void CreateLuaState(lua_State* pt_lua_state);
#endif

   };

}

#endif
