PROJECT(vccm)


ADD_EXECUTABLE(vccm vccm.c Kendall.c CCC.c OCCC.c)
TARGET_LINK_LIBRARIES(vccm ${VIAIO_LIBRARY}  ${LIPSIA_LIBRARY}
    ${GSL_GSL_LIBRARY} ${GSL_CBLAS_LIBRARY})

SET_TARGET_PROPERTIES(vccm PROPERTIES
                      LINK_FLAGS -Wl)

INSTALL(TARGETS vccm
        RUNTIME DESTINATION bin
        COMPONENT RuntimeLibraries)
