set(APP_NAME bridge)

set(HDR DataProvider.h DataConsumer.h)
set(SRC DataConsumer.cc)

add_executable(${APP_NAME} "main.cc" ${HDR} ${SRC})
