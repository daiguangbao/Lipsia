PROJECT(vflip3d)

ADD_EXECUTABLE(vflip3d vflip3d.c)
TARGET_LINK_LIBRARIES(vflip3d ${VIAIO_LIBRARY} ${LIPSIA_LIBRARY})

SET_TARGET_PROPERTIES(vflip3d PROPERTIES
                      LINK_FLAGS -Wl)

INSTALL(TARGETS vflip3d
        RUNTIME DESTINATION bin
        COMPONENT RuntimeLibraries)
