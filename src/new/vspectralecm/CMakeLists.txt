PROJECT(vspectralecm)

ADD_EXECUTABLE(vspectralecm vspectralecm.c)
TARGET_LINK_LIBRARIES(vspectralecm  ${VIAIO_LIBRARY} ${LIPSIA_LIBRARY}
    ${GSL_GSL_LIBRARY} ${GSL_CBLAS_LIBRARY})

SET_TARGET_PROPERTIES(vspectralecm PROPERTIES
                      LINK_FLAGS -Wl)

INSTALL(TARGETS vspectralecm
        RUNTIME DESTINATION bin
        COMPONENT RuntimeLibraries)
