PROJECT(vpretty)

ADD_EXECUTABLE(vpretty vpretty.c)
TARGET_LINK_LIBRARIES(vpretty lipsia ${VIA_LIBRARY})

SET_TARGET_PROPERTIES(vpretty PROPERTIES
                      LINK_FLAGS -Wl)

INSTALL(TARGETS vpretty
        RUNTIME DESTINATION bin
        COMPONENT RuntimeLibraries)
