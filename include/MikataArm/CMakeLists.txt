set(hdrs MikataArm.h
    PARENT_SCOPE
    ManipulatorCommonInterface_MiddleLevelSVC_impl.h
    ManipulatorCommonInterface_CommonSVC_impl.h
    )

install(FILES ${hdrs} DESTINATION ${INC_INSTALL_DIR}/${PROJECT_NAME_LOWER}
    COMPONENT library)

