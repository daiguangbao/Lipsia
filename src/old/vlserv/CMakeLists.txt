PROJECT(vlserv)

INCLUDE_DIRECTORIES(${QT_INCLUDE_DIR})

QT_WRAP_CPP(vlserv VLSERV_MOC dock.h)

ADD_EXECUTABLE(vlserv
               dock.C vlserv.C ${VLSERV_MOC})
TARGET_LINK_LIBRARIES(vlserv ${QT_LIBRARIES} lipsia ${VIA_LIBRARY})

SET_TARGET_PROPERTIES(vlserv PROPERTIES
                      LINK_FLAGS -Wl)

INSTALL(TARGETS vlserv
        RUNTIME DESTINATION bin
        COMPONENT RuntimeLibraries)
