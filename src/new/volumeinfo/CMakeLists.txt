PROJECT(volumeinfo)

ADD_EXECUTABLE(volumeinfo volumeinfo.c)
TARGET_LINK_LIBRARIES(volumeinfo lipsia ${GSL_GSL_LIBRARY} ${GSL_CBLAS_LIBRARY} ${VIA_LIBRARY} ${VIAIO_LIBRARY} ${LIPSIA_LIBRARY})

SET_TARGET_PROPERTIES(volumeinfo PROPERTIES
                      LINK_FLAGS -Wl)

INSTALL(TARGETS volumeinfo
        RUNTIME DESTINATION bin
        COMPONENT RuntimeLibraries)
