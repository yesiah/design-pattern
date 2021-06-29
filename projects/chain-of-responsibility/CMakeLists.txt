set(HDR event_handler.h widget.h button.h dialog.h application.h)
set(SRC event_handler.cc widget.cc button.cc dialog.cc application.cc)
add_executable("gof_sample" "gof_sample.cc" ${HDR} ${SRC})
