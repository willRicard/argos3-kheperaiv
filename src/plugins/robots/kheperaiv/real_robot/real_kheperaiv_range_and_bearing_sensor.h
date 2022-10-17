/**
 * @file <argos3/plugins/robots/generic/control_interface/ci_range_and_bearing_sensor.h>
 *
 * @author Guillaume Ricard <guillaume.ricard@polymtl.ca>
 */

#ifndef KHEPERAIV_RANGE_AND_BEARING_SENSOR_H
#define KHEPERAIV_RANGE_AND_BEARING_SENSOR_H

#include <argos3/core/control_interface/ci_sensor.h>
#include <argos3/core/utility/datatypes/datatypes.h>
#include <argos3/core/utility/datatypes/byte_array.h>
#include <argos3/core/utility/math/quaternion.h>

#include <argos3/plugins/robots/generic/control_interface/ci_range_and_bearing_sensor.h>
#include <argos3/plugins/robots/kheperaiv/real_robot/real_kheperaiv_device.h>

namespace argos {

   /****************************************/
   /****************************************/

   class CRealKheperaIVRangeAndBearingSensor : public CCI_RangeAndBearingSensor,
                                               public CRealKheperaIVDevice {

   public:

      CRealKheperaIVRangeAndBearingSensor(knet_dev_t *pt_dspic);
      virtual void Do(Real f_elapsed_time);

      struct SPacket {
         Real Range;
         CRadians HorizontalBearing;
         /**
          * The vertical bearing is defined as the angle between the local
          * robot XY plane and the message source position, i.e., the elevation
          * in math jargon. This is different from the inclination, which is the
          * angle between the azimuth vector (robot local Z axis) and
          * the vector to the message source. Elevation = 90 degrees - Inclination.
          */
         CRadians VerticalBearing;
         CByteArray Data;

         SPacket();
      };

      typedef std::vector<SPacket> TReadings;

   public:

      virtual ~CRealKheperaIVRangeAndBearingSensor() {}

      const TReadings& GetReadings() const;

#ifdef ARGOS_WITH_LUA
      virtual void CreateLuaState(lua_State* pt_lua_state);

      virtual void ReadingsToLuaState(lua_State* pt_lua_state);
#endif

   protected:

      TReadings m_tReadings;

   };

   /****************************************/
   /****************************************/

}

#endif
