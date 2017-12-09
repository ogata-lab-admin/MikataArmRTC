
// -*-C++-*-
/*!
 * @file  ManipulatorCommonInterface_MiddleLevelSVC_impl.cpp
 * @brief Service implementation code of ManipulatorCommonInterface_MiddleLevel.idl
 *
 * @author Yuki Suga (ysuga@ysuga.net)
 *
 * GPLv3
 *
 */

#include "MikataArm.h"

#include "libmikataarm/include/kinematics.h"
#include "ManipulatorCommonInterface_MiddleLevelSVC_impl.h"

/*
 * Example implementational code for IDL interface JARA_ARM::ManipulatorCommonInterface_Middle
 */
JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl()
{
  // Please add extra constructor code here.
}


JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::~JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl()
{
  // Please add extra destructor code here.
}


/*
 * Methods corresponding to IDL attributes and operations
 */
JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::closeGripper()
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::OK;
  result->comment = CORBA::string_dup("OK");

  try {
    m_pRTC->m_pArm->closeGripper();

    if (m_pRTC->is_blocking()) {
      m_pRTC->m_pArm->waitGripperAttained(m_pRTC->timeoutTime());
    }
  } catch (const ssr::mikata::TimeoutException& ex) { 
    std::cerr << "JARA_ARM_ManipulatorCommonINterface_MiddleSVC_impl::closeGripper()" << std::endl;
    std::cerr << ex.what() << std::endl;
    result->id = JARA_ARM::NG;
    result->comment = CORBA::string_dup(ex.what());
  } catch (const std::exception& ex) {
    std::cerr << "JARA_ARM_ManipulatorCommonINterface_MiddleSVC_impl::closeGripper()" << std::endl;
    std::cerr << ex.what() << std::endl;
    result->id = JARA_ARM::NG;
    result->comment = CORBA::string_dup(ex.what());
  }

  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::getBaseOffset(JARA_ARM::HgMatrix offset)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::getFeedbackPosCartesian(JARA_ARM::CarPosWithElbow& pos)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::getMaxSpeedCartesian(JARA_ARM::CartesianSpeed& speed)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::getMaxSpeedJoint(JARA_ARM::DoubleSeq_out speed)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::getMinAccelTimeCartesian(::CORBA::Double& aclTime)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::getMinAccelTimeJoint(::CORBA::Double& aclTime)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::getSoftLimitCartesian(JARA_ARM::LimitValue& xLimit, JARA_ARM::LimitValue& yLimit, JARA_ARM::LimitValue& zLimit)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::moveGripper(JARA_ARM::ULONG angleRatio)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::OK;
  result->comment = CORBA::string_dup("OK");

  try {
    m_pRTC->m_pArm->moveGripper(angleRatio / 100.0);
    if (m_pRTC->is_blocking()) {
      m_pRTC->m_pArm->waitGripperAttained(m_pRTC->timeoutTime());
    }
  } catch (const ssr::mikata::TimeoutException& ex) { 
    std::cerr << "JARA_ARM_ManipulatorCommonINterface_MiddleSVC_impl::moveGripper()" << std::endl;
    std::cerr << ex.what() << std::endl;
    result->id = JARA_ARM::NG;
    result->comment = CORBA::string_dup(ex.what());
  } catch (const std::exception& ex) {
    std::cerr << "JARA_ARM_ManipulatorCommonINterface_MiddleSVC_impl::moveGripper()" << std::endl;
    std::cerr << ex.what() << std::endl;
    result->id = JARA_ARM::NG;
    result->comment = CORBA::string_dup(ex.what());
  }

  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::moveLinearCartesianAbs(const JARA_ARM::CarPosWithElbow& carPoint)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::moveLinearCartesianRel(const JARA_ARM::CarPosWithElbow& carPoint)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::movePTPCartesianAbs(const JARA_ARM::CarPosWithElbow& carPoint)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::OK;
  result->comment = CORBA::string_dup("OK");
  
  Matrix44 m;
  for (int i = 0;i < 3;i++) {
    for(int j = 0;j < 4;j++) {
      m.v[i][j] = carPoint.carPos[i][j];
    }
  }
  m.v[3][0] = 0;
  m.v[3][1] = 0;
  m.v[3][2] = 0;
  m.v[3][3] = 1.0;

  // meter to millimeter
  m.v[0][3] *= 1000;
  m.v[1][3] *= 1000;
  m.v[2][3] *= 1000;

  std::cout << "Mat: "<< std::endl << str(m) << std::endl;
  std::vector<double> js = inverse_kinematics(m);
  std::vector<ssr::mikata::JointCommand> cmds;
  for(int i = 0;i < 6;i++) {
    ssr::mikata::JointCommand cmd;
    cmd.angle = js[i];
    cmds.push_back(cmd);
  }
  m_pRTC->m_pArm->move(cmds);
  
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::movePTPCartesianRel(const JARA_ARM::CarPosWithElbow& carPoint)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::movePTPJointAbs(const JARA_ARM::JointPos& jointPoints)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::OK;
  result->comment = CORBA::string_dup("OK");
  try {
     std::vector<ssr::mikata::JointCommand> joints;
     
     for(int i = 0;i < ssr::mikata::numJoints;i++) {
       ssr::mikata::JointCommand jc;
       jc.angle = jointPoints[i];
       jc.velocity = -1;
       joints.push_back(jc);
     }
     m_pRTC->m_pArm->move(joints);

     if (m_pRTC->is_blocking()) {
       m_pRTC->m_pArm->waitAttained(m_pRTC->timeoutTime());
     }
  } catch (const ssr::mikata::TimeoutException& ex) { 
    std::cerr << "JARA_ARM_ManipulatorCommonINterface_MiddleSVC_impl::movePTPJointAbs()" << std::endl;
    std::cerr << ex.what() << std::endl;
    result->id = JARA_ARM::NG;
    result->comment = CORBA::string_dup(ex.what());
  } catch (const std::exception& ex) {
    std::cerr << "JARA_ARM_ManipulatorCommonINterface_MiddleSVC_impl::movePTPJointAbs()" << std::endl;
    std::cerr << ex.what() << std::endl;
    result->id = JARA_ARM::NG;
    result->comment = CORBA::string_dup(ex.what());
  }
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::movePTPJointRel(const JARA_ARM::JointPos& jointPoints)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::openGripper()
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::OK;
  result->comment = CORBA::string_dup("OK");

  try {
    m_pRTC->m_pArm->openGripper();

     if (m_pRTC->is_blocking()) {
       m_pRTC->m_pArm->waitGripperAttained(m_pRTC->timeoutTime());
     }
  } catch (const ssr::mikata::TimeoutException& ex) { 
    std::cerr << "JARA_ARM_ManipulatorCommonINterface_MiddleSVC_impl::openGripper()" << std::endl;
    std::cerr << ex.what() << std::endl;
    result->id = JARA_ARM::NG;
    result->comment = CORBA::string_dup(ex.what());
  } catch (const std::exception& ex) {
    std::cerr << "JARA_ARM_ManipulatorCommonINterface_MiddleSVC_impl::openGripper()" << std::endl;
    std::cerr << ex.what() << std::endl;
    result->id = JARA_ARM::NG;
    result->comment = CORBA::string_dup(ex.what());
  }

  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::pause()
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::resume()
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::stop()
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::setAccelTimeCartesian(::CORBA::Double aclTime)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::setAccelTimeJoint(::CORBA::Double aclTime)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::setBaseOffset(const JARA_ARM::HgMatrix offset)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::setControlPointOffset(const JARA_ARM::HgMatrix offset)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::setMaxSpeedCartesian(const JARA_ARM::CartesianSpeed& speed)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::setMaxSpeedJoint(const JARA_ARM::DoubleSeq& speed)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::setMinAccelTimeCartesian(::CORBA::Double aclTime)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::setMinAccelTimeJoint(::CORBA::Double aclTime)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::setSoftLimitCartesian(const JARA_ARM::LimitValue& xLimit, const JARA_ARM::LimitValue& yLimit, const JARA_ARM::LimitValue& zLimit)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::setSpeedCartesian(JARA_ARM::ULONG spdRatio)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::setSpeedJoint(JARA_ARM::ULONG spdRatio)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::OK;
  result->comment = CORBA::string_dup("OK");

  try {
    m_pRTC->m_pArm->setVelocityRatio(spdRatio/100.0);

  } catch (const ssr::mikata::TimeoutException& ex) { 
    std::cerr << "JARA_ARM_ManipulatorCommonINterface_MiddleSVC_impl::closeGripper()" << std::endl;
    std::cerr << ex.what() << std::endl;
    result->id = JARA_ARM::NG;
    result->comment = CORBA::string_dup(ex.what());
  } catch (const std::exception& ex) {
    std::cerr << "JARA_ARM_ManipulatorCommonINterface_MiddleSVC_impl::closeGripper()" << std::endl;
    std::cerr << ex.what() << std::endl;
    result->id = JARA_ARM::NG;
    result->comment = CORBA::string_dup(ex.what());
  }


  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::moveCircularCartesianAbs(const JARA_ARM::CarPosWithElbow& carPointR, const JARA_ARM::CarPosWithElbow& carPointT)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::moveCircularCartesianRel(const JARA_ARM::CarPosWithElbow& carPointR, const JARA_ARM::CarPosWithElbow& carPointT)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::setHome(const JARA_ARM::JointPos& jointPoint)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::getHome(JARA_ARM::JointPos_out jointPoint)
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}

JARA_ARM::RETURN_ID* JARA_ARM_ManipulatorCommonInterface_MiddleSVC_impl::goHome()
{
  JARA_ARM::RETURN_ID_var result(new JARA_ARM::RETURN_ID());
  result->id = JARA_ARM::NOT_IMPLEMENTED;
  result->comment = CORBA::string_dup("NOT_IMPLEMENTED");
  return result._retn();
}



// End of example implementational code



