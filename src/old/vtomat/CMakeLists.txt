PROJECT(vtomat)

ADD_EXECUTABLE(vtomat vtomat.c)
TARGET_LINK_LIBRARIES(vtomat lipsia ${VIA_LIBRARY})

SET_TARGET_PROPERTIES(vtomat PROPERTIES
                      LINK_FLAGS -Wl)

INSTALL(TARGETS vtomat
        RUNTIME DESTINATION bin
        COMPONENT RuntimeLibraries)
