
add_executable (
    event_broker
    event_broker.cpp
    listener.cpp
    main.cpp
)

target_include_directories(
    event_broker
    PRIVATE
        $ENV{PROJECT_SRC_DIR}
        ${Boost_INCLUDE_DIRS}
)

target_link_libraries (
	event_broker
    PRIVATE
    pthread
)

install (
    TARGETS event_broker
    DESTINATION $ENV{PROJECT_BIN_DIR}/
)
