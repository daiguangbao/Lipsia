PROJECT(vgauss)

ADD_EXECUTABLE(vgauss vgauss.c)
TARGET_LINK_LIBRARIES(vgauss lipsia ${VIA_LIBRARY})

SET_TARGET_PROPERTIES(vgauss PROPERTIES
                      LINK_FLAGS -Wl)

INSTALL(TARGETS vgauss
        RUNTIME DESTINATION bin
        COMPONENT RuntimeLibraries)
