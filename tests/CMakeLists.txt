
include(ECMMarkAsTest)

########### next target ###############

# FIXME: Build fails
set(testread_SRCS testread.cpp)
add_executable(testread ${testread_SRCS})
target_link_libraries(testread KF5Contacts KF5::I18n Qt5::Gui)

########### next target ###############

# FIXME: Build fails
set(testwrite_SRCS testwrite.cpp)
add_executable(testwrite ${testwrite_SRCS})
target_link_libraries(testwrite KF5Contacts Qt5::Gui KF5::I18n)

########### next target ###############

set(testread2_SRCS testread2.cpp testutils.cpp)
add_executable(testread2 ${testread2_SRCS})
target_link_libraries(testread2 KF5Contacts Qt5::Gui)
