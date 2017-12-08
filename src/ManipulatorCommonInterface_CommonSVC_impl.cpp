// -*-C++-*-
/*!
 * @file  ManipulatorCommonInterface_CommonSVC_impl.cpp
 * @brief Service implementation code of ManipulatorCommonInterface_Common.idl
 *
 * @author Yuki Suga (ysuga@ysuga.net)
 *
 * GPLv3
 *
 */

#include "MikataArm.h"
#include "ManipulatorCommonInterface_CommonSVC_impl.h"

/*
 * Example implementational code for IDL interface JARA_ARM::ManipulatorCommonInterface_Common
 */
JARA_ARM_ManipulatorCommonInterface_CommonSVC_impl::JARA_ARM_ManipulatorCommonInterface_CommonSVC_impl()
{
  // Please add extra constructor code here.
}


JARA_ARM_ManipulatorCommonInterface_CommonSVC_impl::~JARA_ARM_ManipulatorCommonInterface_CommonSVC_impl()
{
  // Please add extra destructor code here.
}


/*
 * Methods corresponding to IDL attributes and operations
 */
JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_CommonSVC_impl::clearAlarms()
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_CommonSVC_impl::getActiveAlarm(JARA_ARM::AlarmSeq_out alarms)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_CommonSVC_impl::getFeedbackPosJoint(JARA_ARM::JointPos_out pos)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::OK;
  result->comment = CORBA::string_dup("OK");
  try {
    JARA_ARM::JointPos_var pos_v(new JARA_ARM::JointPos());
    pos_v->length(7);
    std::vector<ssr::mikata::JointInfo> jointInfos = m_pRTC->m_pArm->jointInfos();
    ssr::mikata::JointInfo gripper = m_pRTC->m_pArm->gripper();
    for(int i = 0;i < 6;i++) {
      pos_v[i] = jointInfos[i].angle;
    }
    pos_v[6] = gripper.angle;
    pos = pos_v.out();
  } catch (const std::exception& ex) {
    std::cerr << "JARA_ARM_ManipulatorCommonINterface_CommonSVC_impl::getFeedbackPosJoint()" << std::endl;
    std::cerr << ex.what() << std::endl;
    result->id = JARA_ARM::NG;
    result->comment = CORBA::string_dup(ex.what());
  }
  
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_CommonSVC_impl::getManipInfo(JARA_ARM::ManipInfo_out mInfo)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::OK;
  result->comment = CORBA::string_dup("OK");
  try {
    JARA_ARM::ManipInfo_var info(new JARA_ARM::ManipInfo());
    info->manufactur = CORBA::string_dup("ROBOTIS");
    info->type = CORBA::string_dup("Mikata Arm");
    info->axisNum = 6;
    info->cmdCycle = 20;
    info->isGripper = true;
    mInfo = info.out();
  } catch (const std::exception& ex) {
    std::cerr << "JARA_ARM_ManipulatorCommonINterface_CommonSVC_impl::getManipInfo()" << std::endl;
    std::cerr << ex.what() << std::endl;
    result->id = JARA_ARM::NG;
    result->comment = CORBA::string_dup(ex.what());
  }
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_CommonSVC_impl::getSoftLimitJoint(JARA_ARM::LimitSeq_out softLimit)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_CommonSVC_impl::getState(JARA_ARM::ULONG& state)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_CommonSVC_impl::servoOFF()
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::OK;
  result->comment = CORBA::string_dup("OK");

  try {
    m_pRTC->m_pArm->servoOn(false);
    m_pRTC->m_pArm->gripperServoOn(false);
  } catch (const std::exception& ex) {
    std::cerr << "JARA_ARM_ManipulatorCommonINterface_CommonSVC_impl::servoOFF()" << std::endl;
    std::cerr << ex.what() << std::endl;
    result->id = JARA_ARM::NG;
    result->comment = CORBA::string_dup(ex.what());
  }
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_CommonSVC_impl::servoON()
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::OK;
  result->comment = CORBA::string_dup("OK");
  try {
    m_pRTC->m_pArm->servoOn(true);
    m_pRTC->m_pArm->gripperServoOn(true);
  } catch (const std::exception& ex) {
    std::cerr << "JARA_ARM_ManipulatorCommonINterface_CommonSVC_impl::servoON()" << std::endl;
    std::cerr << ex.what() << std::endl;
    result->id = JARA_ARM::NG;
    result->comment = CORBA::string_dup(ex.what());
  }
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_CommonSVC_impl::setSoftLimitJoint(const JARA_ARM::LimitSeq& softLimit)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}



// End of example implementational code



