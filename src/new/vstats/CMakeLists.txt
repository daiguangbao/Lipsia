PROJECT(vstats)


ADD_EXECUTABLE(vstats vstats.c)
TARGET_LINK_LIBRARIES(vstats lipsia ${VIAIO_LIBRARY} ${GSL_GSL_LIBRARY} ${GSL_CBLAS_LIBRARY} ${LIPSIA_LIBRARY})

SET_TARGET_PROPERTIES(vstats PROPERTIES
                      LINK_FLAGS -Wl)

INSTALL(TARGETS vstats
        RUNTIME DESTINATION bin
        COMPONENT RuntimeLibraries)
