PROJECT(mattov)

ADD_EXECUTABLE(mattov mattov.c)
TARGET_LINK_LIBRARIES(mattov lipsia ${VIA_LIBRARY})

SET_TARGET_PROPERTIES(mattov PROPERTIES
                      LINK_FLAGS -Wl)

INSTALL(TARGETS mattov
        RUNTIME DESTINATION bin
        COMPONENT RuntimeLibraries)
