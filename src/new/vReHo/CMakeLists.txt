PROJECT(vReHo)


ADD_EXECUTABLE(vReHo vReHo.c Kendall.c)
TARGET_LINK_LIBRARIES(vReHo lipsia ${VIAIO_LIBRARY} ${VIAIO_LIBRARY} ${GSL_GSL_LIBRARY} ${GSL_CBLAS_LIBRARY} ${LIPSIA_LIBRARY})

SET_TARGET_PROPERTIES(vReHo PROPERTIES
                      LINK_FLAGS -Wl)

INSTALL(TARGETS vReHo
        RUNTIME DESTINATION bin
        COMPONENT RuntimeLibraries)
