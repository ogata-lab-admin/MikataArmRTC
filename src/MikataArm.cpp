// -*- C++ -*-
/*!
 * @file  MikataArm.cpp
 * @brief ROBOTICS MIKATA Arm RTC
 * @date $Date$
 *
 * @author Yuki Suga (ysuga@ysuga.net)
 *
 * GPLv3
 *
 * $Id$
 */

#include "MikataArm.h"

// Module specification
// <rtc-template block="module_spec">
static const char* mikataarm_spec[] =
  {
    "implementation_id", "MikataArm",
    "type_name",         "MikataArm",
    "description",       "ROBOTICS MIKATA Arm RTC",
    "version",           "1.0.0",
    "vendor",            "Ogata Labratory",
    "category",          "Manipulator",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.port_name", "COM1",
    "conf.default.baudrate", "1000000",

    // Widget
    "conf.__widget__.port_name", "text",
    "conf.__widget__.baudrate", "text",
    // Constraints

    "conf.__type__.port_name", "string",
    "conf.__type__.baudrate", "int",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
MikataArm::MikataArm(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_manipMiddlePort("manipMiddle"),
    m_manipCommonPort("manipCommon")

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
MikataArm::~MikataArm()
{
}



RTC::ReturnCode_t MikataArm::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  m_manipMiddlePort.registerProvider("JARA_ARM_ManipulatorCommonInterface_Middle", "JARA_ARM::ManipulatorCommonInterface_Middle", m_manipMiddle);
  m_manipCommonPort.registerProvider("JARA_ARM_ManipulatorCommonInterface_Common", "JARA_ARM::ManipulatorCommonInterface_Common", m_manipCommon);
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  addPort(m_manipMiddlePort);
  addPort(m_manipCommonPort);
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("port_name", m_port_name, "COM1");
  bindParameter("baudrate", m_baudrate, "1000000");
  // </rtc-template>


  m_manipMiddle.setRTC(this);
  m_manipCommon.setRTC(this);
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t MikataArm::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MikataArm::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MikataArm::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t MikataArm::onActivated(RTC::UniqueId ec_id)
{
  m_pArm = new ssr::mikata::MikataArm(m_port_name.c_str(), m_baudrate);
  return RTC::RTC_OK;
}


RTC::ReturnCode_t MikataArm::onDeactivated(RTC::UniqueId ec_id)
{
  delete m_pArm;
  return RTC::RTC_OK;
}


RTC::ReturnCode_t MikataArm::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t MikataArm::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MikataArm::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t MikataArm::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t MikataArm::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MikataArm::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void MikataArmInit(RTC::Manager* manager)
  {
    coil::Properties profile(mikataarm_spec);
    manager->registerFactory(profile,
                             RTC::Create<MikataArm>,
                             RTC::Delete<MikataArm>);
  }
  
};


